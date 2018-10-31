#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>
#include <GL/glew.h>
#include <iostream>
#include<glm/gtc/random.hpp>

using namespace glimac;

//cmake ../GLImac-Template && make && ./TP6/TP6_exo1_sphere

Sphere sphere(1, 32, 16);


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
     * INITIALIZATION CODE
     *********************************/
    
    // Création d'un seul VBO = contient les données
    GLuint vbo;
    glGenBuffers(1, &vbo);
    
    //Binding d'un VBO sur la cible GL_ARRAY_BUFFER: permet de la modifier
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //On peut à présent modifier le VBO en passant par la cible 

    //Envoi des données
    glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof (ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);
    //On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.

    //Débindage, pour éviter de remodifier le VBO par erreur.
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Création du VAO (Vertex Array Object) = décrit les données dans le VBOs
    GLuint vao;
    glGenVertexArrays(1, &vao);

    //Binding du VAO
    glBindVertexArray(vao);

    //Activation des attributs de vertex
    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORMAL = 1;
    const GLuint VERTEX_ATTR_COORDINATE = 2;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glEnableVertexAttribArray(VERTEX_ATTR_COORDINATE);

    //Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Spécification des attributs de vertex
    //glVertexAttribPointer(GLuint index,GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof (ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, position));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof (ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, normal));
    glVertexAttribPointer(VERTEX_ATTR_COORDINATE, 2, GL_FLOAT, GL_FALSE, sizeof (ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, texCoords));

    //Débindage
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);



    // Charger et compiler les shaders
    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                                applicationPath.dirPath() + "shaders/normals.fs.glsl");
    program.use(); // Indiquer a OpenGL de les utiliser

    //on récupère les locations des variables uniformes dans les shaders
    GLint uMVPMatrixLocation = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

    //calcul de la projetion matrix
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 4.f/3.f, 0.1f, 100.f);
    glm::mat4 MVMatrix;
    glm::mat4 NormalMatrix;
    glm::mat4 tmpMVMatrix;
    glm::mat4 tmpNormalMatrix;

    //calcul des axes de rotations aléatoires
    std::vector<glm::vec3> randomAxes;
    for (size_t i=0; i<30; ++i) {
     randomAxes.push_back(glm::sphericalRand(10.f));
    }


    glEnable(GL_DEPTH_TEST);
    
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

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /*********************************
         * RENDERING CODE
         *********************************/

        //Binding du VAO
        glBindVertexArray(vao);
        
        //calcul des view matrix, model matrix
        glm::mat4 MVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f ,-5.f));
        glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
        //on envoie les matrices à la CG dans les variables uniformes
        glUniformMatrix4fv(uMVPMatrixLocation, 1, GL_FALSE,  glm::value_ptr(ProjMatrix * MVMatrix));
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE,  glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE,  glm::value_ptr(NormalMatrix));

        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        for (size_t i=0; i<randomAxes.size(); ++i) {
            
            tmpMVMatrix = glm::rotate(MVMatrix, 2*glm::pi<float>()*(float)i/randomAxes.size(), glm::vec3(0,1,0)); //rotation équitable pour que les lunes soient bien écartées :)
            tmpMVMatrix = glm::rotate(tmpMVMatrix, windowManager.getTime(), randomAxes[i]); 
            tmpMVMatrix = glm::translate(tmpMVMatrix, glm::vec3(-2, 0, 0));
            tmpMVMatrix = glm::scale(tmpMVMatrix, glm::vec3(0.2, 0.2, 0.2));
            tmpNormalMatrix = glm::transpose(glm::inverse(tmpMVMatrix));
            
            //on envoie les matrices à la CG dans les variables uniformes
            glUniformMatrix4fv(uMVPMatrixLocation, 1, GL_FALSE,  glm::value_ptr(ProjMatrix * tmpMVMatrix));
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE,  glm::value_ptr(tmpMVMatrix));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE,  glm::value_ptr(tmpNormalMatrix));

            glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
        }

        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
