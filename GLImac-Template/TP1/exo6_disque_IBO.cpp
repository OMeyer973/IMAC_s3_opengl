#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <GL/glew.h>
#include <vector>
#include <iostream>
#include <cstddef>

using namespace glimac;

struct Vertex2DColor{
  Vertex2DColor(); 
  Vertex2DColor(const glm::vec2 &vecPos, const glm::vec3 &vecCol) : position(vecPos), color(vecCol){}; // constructeur

  glm::vec2 position;
  glm::vec3 color;
};

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/triangle.vs.glsl",
                                  applicationPath.dirPath() + "shaders/triangle.fs.glsl");
    program.use();

    GLuint vbo;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

      //Coordonnée disques
  const size_t CIRCLE_POLYGONES = 30;
  const float r = 0.5;
  float teta = 0.;
  std::vector<Vertex2DColor> vertices;
  vertices.push_back(Vertex2DColor(glm::vec2(0, 0), glm::vec3(0, 0, 0.9)));

  for (size_t i = 0; i < CIRCLE_POLYGONES; i++){
    teta = 2 * glm::pi<float>() * i / CIRCLE_POLYGONES;
    vertices.push_back(Vertex2DColor(glm::vec2(r * glm::cos(teta), r * glm::sin(teta)), glm::vec3(0, 0, 0.4)));
  };

    // => Penser à bien changer le nombre de sommet (4 au lieu de 6):
    glBufferData(GL_ARRAY_BUFFER, (CIRCLE_POLYGONES+1) * sizeof(Vertex2DColor), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // => Creation du IBO
    GLuint ibo;
    glGenBuffers(1, &ibo);

    // => On bind sur GL_ELEMENT_ARRAY_BUFFER, cible reservée pour les IBOs
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    // => Tableau d'indices: ce sont les indices des sommets à dessiner
    // On en a 6 afin de former deux triangles
    // Chaque indice correspond au sommet correspondant dans le VBO
    std::vector<uint32_t> indices = {};

     for (size_t i = 0; i < CIRCLE_POLYGONES; i++){
        indices.push_back(0);
        indices.push_back(i+1);
        indices.push_back((i+1)%CIRCLE_POLYGONES + 1);
     }

    // => On remplit l'IBO avec les indices:
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3*CIRCLE_POLYGONES * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

    // => Comme d'habitude on debind avant de passer à autre chose
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    GLuint vao;
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);

    // => On bind l'IBO sur GL_ELEMENT_ARRAY_BUFFER; puisqu'un VAO est actuellement bindé,
    // cela a pour effet d'enregistrer l'IBO dans le VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    const GLuint VERTEX_ATTR_POSITION = 3;
    const GLuint VERTEX_ATTR_COLOR = 8;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 
        sizeof(Vertex2DColor), (const GLvoid*) offsetof(Vertex2DColor, position));
    glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, 
        sizeof(Vertex2DColor), (const GLvoid*) offsetof(Vertex2DColor, color));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vao);

        // => On utilise glDrawElements à la place de glDrawArrays
        // Cela indique à OpenGL qu'il doit utiliser l'IBO enregistré dans le VAO
        glDrawElements(GL_TRIANGLES, 3*CIRCLE_POLYGONES, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return EXIT_SUCCESS;
}