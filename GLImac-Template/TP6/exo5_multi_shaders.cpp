#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Image.hpp>
#include <GL/glew.h>
#include <iostream>
#include<glm/gtc/random.hpp>

using namespace glimac;

//cmake ../GLImac-Template && make && ./TP6/TP6_exo5_multi_shaders

//le modèle de sphère utilisé pour la terre et les lunes
Sphere sphere(1, 32, 16);


struct EarthProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uEarthTexture;
    GLint uCloudTexture;

    EarthProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/multiTex3D.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uEarthTexture = glGetUniformLocation(m_Program.getGLId(), "uEarthTexture");
        uCloudTexture = glGetUniformLocation(m_Program.getGLId(), "uCloudTexture");
    }
};

struct MoonProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;

    MoonProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/tex3D.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
    }
};



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
    
    /////////////////////////
    // ATTRIBUTS DES VERTEX

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
    
    ///////////////////////////////////
    // SHADERS ET VARIABLES UNIFORMES

    // Charger et compiler les shaders
    FilePath applicationPath(argv[0]);
    EarthProgram earthProgram(applicationPath);
    MoonProgram moonProgram(applicationPath);

    /////////////
    // TEXTURES
    
    // TEXTURE TERRE
    //chargement d'une texture par fichier en utilisant la classe image de glimac
    const Image* earthMap  = ImageManager::loadImage("/home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/assets/textures/EarthMap.jpg");
    if (earthMap == NULL) {
        std::cout << "Texture ptr is null. exit program." << std::endl;
        return 0;
    }

    //création et binding d'un texture object
    GLuint earthTexture;
    glGenTextures(1, &earthTexture);

    glBindTexture(GL_TEXTURE_2D, earthTexture);

    glTexImage2D(
        GL_TEXTURE_2D,          //GLenum target
        0,                      //GLint level
        GL_RGBA,                //GLint internalformat
        earthMap->getWidth(),   //GLsizei width
        earthMap->getHeight(),  //GLsizei height
        0,                      //GLint border
        GL_RGBA,                //GLenum format
        GL_FLOAT,               //GLenum type
        earthMap->getPixels()   //const GLvoid * data
    );

    //paramètres de filtrage de texture 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
    
    // TEXTURE NUAGES
    //chargement d'une texture par fichier en utilisant la classe image de glimac
    const Image* cloudMap  = ImageManager::loadImage("/home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/assets/textures/CloudMap.jpg");
    if (cloudMap == NULL) {
        std::cout << "Texture ptr is null. exit program." << std::endl;
        return 0;
    }

    //création et binding d'un texture object
    GLuint cloudTexture;
    glGenTextures(1, &cloudTexture);

    glBindTexture(GL_TEXTURE_2D, cloudTexture);

    glTexImage2D(
        GL_TEXTURE_2D,          //GLenum target
        0,                      //GLint level
        GL_RGBA,                //GLint internalformat
        cloudMap->getWidth(),   //GLsizei width
        cloudMap->getHeight(),  //GLsizei height
        0,                      //GLint border
        GL_RGBA,                //GLenum format
        GL_FLOAT,               //GLenum type
        cloudMap->getPixels()   //const GLvoid * data
    );

    //paramètres de filtrage de texture 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    //TEXTURE LUNE
    //chargement d'une texture par fichier en utilisant la classe image de glimac
    const Image* moonMap  = ImageManager::loadImage("/home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/assets/textures/MoonMap.jpg");
    if (moonMap == NULL) {
        std::cout << "Texture ptr is null. exit program." << std::endl;
        return 0;
    }

    //création et binding d'un texture object
    GLuint moonTexture;
    glGenTextures(1, &moonTexture);

    glBindTexture(GL_TEXTURE_2D, moonTexture);

    glTexImage2D(
        GL_TEXTURE_2D,          //GLenum target
        0,                      //GLint level
        GL_RGBA,                //GLint internalformat
        moonMap->getWidth(),   //GLsizei width
        moonMap->getHeight(),  //GLsizei height
        0,                      //GLint border
        GL_RGBA,                //GLenum format
        GL_FLOAT,               //GLenum type
        moonMap->getPixels()   //const GLvoid * data
    );

    //paramètres de filtrage de texture 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
    ///////////////////////////////
    // MATRICES DE TRANSFORMATION
    
    //calcul de la projection matrix
    glm::mat4 projMatrix = glm::perspective(glm::radians(70.f), 4.f/3.f, 0.1f, 100.f);
   
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
        
        earthProgram.m_Program.use();

        glUniform1i(earthProgram.uEarthTexture, 0);
        glUniform1i(earthProgram.uCloudTexture, 1);

        //calcul des view matrix, model matrix
        glm::mat4 globalMVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -5));

        glm::mat4 earthMVMatrix = glm::rotate(globalMVMatrix, windowManager.getTime(), glm::vec3(0, 1, 0));
        //on envoie les matrices à la CG dans les variables uniformes
        glUniformMatrix4fv(earthProgram.uMVMatrix, 1, GL_FALSE, 
            glm::value_ptr(earthMVMatrix));
        glUniformMatrix4fv(earthProgram.uNormalMatrix, 1, GL_FALSE, 
            glm::value_ptr(glm::transpose(glm::inverse(earthMVMatrix))));
        glUniformMatrix4fv(earthProgram.uMVPMatrix, 1, GL_FALSE, 
            glm::value_ptr(projMatrix * earthMVMatrix));

        glActiveTexture(GL_TEXTURE0);
        // la texture earthTexture est bindée sur l'unité GL_TEXTURE0
        glBindTexture(GL_TEXTURE_2D, earthTexture);
        // la texture cloudTexture est bindée sur l'unité GL_TEXTURE1
        // le 1 doit être différent du 0 de la première texture map
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, cloudTexture);

        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, 0); // débind sur l'unité GL_TEXTURE0
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0); // débind sur l'unité GL_TEXTURE1


        moonProgram.m_Program.use();
        for (size_t i=0; i<randomAxes.size(); ++i) {
           
            glUniform1i(moonProgram.uTexture, 0);

            //calcul des view matrix, model matrix
            glm::mat4 globalMVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -5));

            //rotation équitable pour que les lunes soient bien écartées :)
            glm::mat4 moonMVMatrix = glm::rotate(
                globalMVMatrix, 
                2*glm::pi<float>()*(float)i/randomAxes.size(),
                glm::vec3(0,1,0)
            );
            //rotation de la lune autours de son axe
            moonMVMatrix = glm::rotate(moonMVMatrix, windowManager.getTime(), randomAxes[i]); 
            //écartement de la lune
            moonMVMatrix = glm::translate(moonMVMatrix, glm::vec3(-2, 0, 0));
            moonMVMatrix = glm::scale(moonMVMatrix, glm::vec3(0.2, 0.2, 0.2));
            //on envoie les matrices à la CG dans les variables uniformes
            glUniformMatrix4fv(moonProgram.uMVMatrix, 1, GL_FALSE, 
                glm::value_ptr(moonMVMatrix));
            glUniformMatrix4fv(moonProgram.uNormalMatrix, 1, GL_FALSE, 
                glm::value_ptr(glm::transpose(glm::inverse(moonMVMatrix))));
            glUniformMatrix4fv(moonProgram.uMVPMatrix, 1, GL_FALSE, 
                glm::value_ptr(projMatrix * moonMVMatrix));

            glActiveTexture(GL_TEXTURE0);
            // la texture moonTexture est bindée sur l'unité GL_TEXTURE0
            glBindTexture(GL_TEXTURE_2D, moonTexture);
            
            glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
            
            glBindTexture(GL_TEXTURE_2D, 0); // débind sur l'unité GL_TEXTURE0
        }

        glBindTexture(GL_TEXTURE_2D, 0);

        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
