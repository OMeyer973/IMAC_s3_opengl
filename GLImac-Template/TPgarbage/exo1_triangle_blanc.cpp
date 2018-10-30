#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>

using namespace glimac;

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
    std::cout << "hgfGLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
     
     //Création d'un seul VBO
     GLuint vbo;
     glGenBuffers(1,&vbo);

     //Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
     glBindBuffer(GL_ARRAY_BUFFER, vbo);
     //On peut à présent modifier le VBO en passant par la cible GL_ARRAY_BUFFER

     //Coordonnée triangle
     GLfloat vertices[] = { -0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f};

     //Envoi des données
     glBufferData(GL_ARRAY_BUFFER, 6*sizeof(GLfloat),vertices,GL_STATIC_DRAW);

     //Débindage
     glBindBuffer(GL_ARRAY_BUFFER, 0);

     //Création du VAO
     GLuint vao;
     //glGenVertexArrays(GLsizei n, GLuint *arrays);
     //glBindVertexArray(GLuint vao);

     glGenVertexArrays(1, &vao);
     glBindVertexArray(vao);

     //Bindage vbo sur array buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

     //Activation des attributs de vertex
     const GLuint VERTEX_ATTR_POSITION = 0;
     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);

     //Spécification des attributs de vertex
     //glVertexAttribPointer(GLuint index,GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
     glVertexAttribPointer(VERTEX_ATTR_POSITION,2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
     //Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
     
     //Débindage
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

        /***************************************
         * HERE SHOULD COME THE RENDERING CODE *
         ***************************************/
         //glClear(GLbitfield mask);
         glClear(GL_COLOR_BUFFER_BIT);
         glBindVertexArray(vao);
         //glDrawArrays(GLenum mode, GLint first, GLsizei count);
         glDrawArrays(GL_TRIANGLES, 0, 3);

         //débindage
         glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    //void glDeleteBuffers(GLsizei n, const GLuint * buffers);
    glDeleteBuffers(1, &vbo);

    //void glDeleteVertexArrays( GLsizei n, const GLuint *arrays);
    glDeleteVertexArrays( 1, &vao);
    return EXIT_SUCCESS;
}
