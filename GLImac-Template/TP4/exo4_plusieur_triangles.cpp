#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <GL/glew.h>
#include <GL/glew.h>
#include <iostream>

using namespace glimac;

//COMPIL :
//cmake ../GLImac-Template && make && ./TP4/TP4_exo4_plusieur_triangles tex2D_4.vs.glsl tex2D_4.fs.glsl


class Vertex2DUV {

    public:
        Vertex2DUV(); 
        Vertex2DUV(const glm::vec2 &vecPos, const glm::vec2 &vecCoord) : position(vecPos), coordinate(vecCoord){}; // constructeur

        glm::vec2 position;
        glm::vec2 coordinate;

};

glm::mat3 translate(float tx, float ty) {
    return glm::mat3(
        glm::vec3(1,0,0),
        glm::vec3(0,1,0), 
        glm::vec3(tx,ty,1)
    );
}

glm::mat3 scale(float sx, float sy){
    return glm::mat3(
        glm::vec3(sx,0,0),
        glm::vec3(0,sy,0),
        glm::vec3(0,0,1)
    ); 
}

glm::mat3 rotate(float teta){
    return glm::mat3(
        glm::vec3(cos(teta),sin(teta),0),
        glm::vec3(-sin(teta),cos(teta),0),
        glm::vec3(0,0,1)
    );  
}

float rotSpeed = 0.001;
float angle = 0;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
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
    Program program = loadProgram(applicationPath.dirPath() + "shaders/" + argv[1],
                                applicationPath.dirPath() + "shaders/" + argv[2]);
    program.use(); // Indiquer a OpenGL de les utiliser
    
    //bout de code pour obtenir l'emplacement de la variable uniforme "uTime" dans le shader
    GLint modelMatrixLocation = glGetUniformLocation(program.getGLId(), "uModelMatrix");
    GLint colorLocation = glGetUniformLocation(program.getGLId(), "uColor");
    //changement de la valeur de la variable uniforme
    glUniformMatrix3fv(modelMatrixLocation, 1, GL_FALSE,  glm::value_ptr(rotate(0)));
    glUniform3fv(colorLocation, 1,  glm::value_ptr(glm::vec3(1,1,0)));

    // Création d'un seul VBO = contient les données
    GLuint vbo;
    glGenBuffers(1, &vbo);

    //Binding d'un VBO sur la cible GL_ARRAY_BUFFER: permet de la modifier
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //On peut à présent modifier le VBO en passant par la cible 

    //Coordonnée triangle
    Vertex2DUV vertices[] = {
        Vertex2DUV(glm::vec2(-1, -1), glm::vec2(0, 0)),
        Vertex2DUV(glm::vec2(1, -1), glm::vec2(0, 0)),
        Vertex2DUV(glm::vec2(0, 1), glm::vec2(0, 0))
    };

    //Envoi des données
    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof (Vertex2DUV), vertices, GL_STATIC_DRAW);
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
    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_COORDINATE = 1;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_COORDINATE);

    //Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Spécification des attributs de vertex
    //glVertexAttribPointer(GLuint index,GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof (Vertex2DUV), (const GLvoid*) offsetof(Vertex2DUV, position));
    glVertexAttribPointer(VERTEX_ATTR_COORDINATE, 2, GL_FLOAT, GL_FALSE, sizeof (Vertex2DUV), (const GLvoid*) offsetof(Vertex2DUV, coordinate));


    //Débindage
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
        /*********************************
         *         RENDERING CODE
         *********************************/
        //glClear(GLbitfield mask);
        angle += rotSpeed;
        
        glBindVertexArray(vao);
        
        glClear(GL_COLOR_BUFFER_BIT);

        glUniformMatrix3fv(modelMatrixLocation, 1, GL_FALSE,  glm::value_ptr(
                rotate(angle) * translate(-0.5, -0.5) * scale(0.5, 0.5)
            )
        );
        glUniform3fv(colorLocation, 1,  glm::value_ptr(glm::vec3(1,1,0)));
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUniformMatrix3fv(modelMatrixLocation, 1, GL_FALSE,  glm::value_ptr(
                rotate(angle) * translate(0.5, -0.5) * scale(0.5, 0.5)
            )
        );
        glUniform3fv(colorLocation, 1,  glm::value_ptr(glm::vec3(1,0,1)));
        glDrawArrays(GL_TRIANGLES, 0, 3);


        glUniformMatrix3fv(modelMatrixLocation, 1, GL_FALSE,  glm::value_ptr(
                rotate(angle) * translate(0,0.5) * scale(0.5, 0.5)
            )
        );
        glUniform3fv(colorLocation, 1,  glm::value_ptr(glm::vec3(0,1,1)));
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
