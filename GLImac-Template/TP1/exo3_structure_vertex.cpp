#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <GL/glew.h>
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
  SDLWindowManager windowManager(800, 600, "GLImac");

  // Initialize glew for OpenGL3+ support
  GLenum glewInitError = glewInit();
  if (GLEW_OK != glewInitError) {
    std::cerr << glewGetErrorString(glewInitError) << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

  /*********************************
   *      INITIALIZATION CODE
   *********************************/

  // Charger et compiler les shaders
  FilePath applicationPath(argv[0]);
  Program program = loadProgram(applicationPath.dirPath() + "shaders/triangle.vs.glsl",
                                applicationPath.dirPath() + "shaders/triangle.fs.glsl");
  program.use(); // Indiquer a OpenGL de les utiliser

  // Création d'un seul VBO = contient les données
  GLuint vbo;
  glGenBuffers(1, &vbo);

  //Binding d'un VBO sur la cible GL_ARRAY_BUFFER: permet de la modifier
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  //On peut à présent modifier le VBO en passant par la cible 

  //Coordonnée triangle
  Vertex2DColor vertices[] = { 
    Vertex2DColor(glm::vec2(-0.5, -0.5), glm::vec3(1, 0, 0)),
    Vertex2DColor(glm::vec2(0.5, -0.5), glm::vec3(0, 1, 0)),
    Vertex2DColor(glm::vec2(0, 0.5), glm::vec3(0, 0, 1))
  };

  //Envoi des données
  glBufferData(GL_ARRAY_BUFFER, 3 * sizeof (Vertex2DColor), vertices, GL_STATIC_DRAW);
  //On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.

  //Débindage, pour éviter de remodifier le VBO par erreur.
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  //Création du VAO (Vertex Array Object) = décrit les données
  //décrit pour chaque attribut de sommet (position, couleur, normale, etc.) la manière dont ils sont rangés dans un ou plusieurs VBOs
  GLuint vao;
  glGenVertexArrays(1, &vao);

  //Binding du VAO
  glBindVertexArray(vao);

  //Activation des attributs de vertex
  const GLuint VERTEX_ATTR_POSITION = 3;
  const GLuint VERTEX_ATTR_COLOR = 8;
  glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
  glEnableVertexAttribArray(VERTEX_ATTR_COLOR);

  //Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  //Spécification des attributs de vertex
  //glVertexAttribPointer(GLuint index,GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
  glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof (Vertex2DColor), (const GLvoid*) offsetof(Vertex2DColor, position));
  glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex2DColor), (const GLvoid*) offsetof(Vertex2DColor, color));

  //Débindage
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);


  // Application loop:
  bool done = false;
  while (!done) {
    // Event loop:
    SDL_Event e;
    while (windowManager.pollEvent(e)) {
      if (e.type == SDL_QUIT) {
        done = true; // Leave the loop after this iteration
      }
    }

    /*********************************
     *         RENDERING CODE
     *********************************/
    //glClear(GLbitfield mask);
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    // Update the display
    windowManager.swapBuffers();
  }

  //libération des ressources
  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);

  return EXIT_SUCCESS;
}
