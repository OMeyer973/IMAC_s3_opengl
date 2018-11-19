#pragma once

#include "common.hpp"

#include <iostream>
namespace glimac {

// FreeflyCamera
class FreeflyCamera {
    
public:
    // Constructeur: initialise la distance et les angles
    inline FreeflyCamera()
    :m_Position(glm::vec3(0,0,0)), 
    m_fPhi(glm::pi<float>()),
    m_fTheta(0)
    {
        computeDirectionVectors();
    };

    // Constructeur: initialise la distance et les angles
    inline FreeflyCamera(const glm::vec3 position, const float phi, const float theta)
    :m_Position(position), m_fPhi(phi), m_fTheta(theta)
    {
        computeDirectionVectors();
    };

    inline void moveFront(const float delta) {
        m_Position += delta * m_FrontVector;
    };

    inline void moveLeft(const float delta) {
         m_Position += delta * m_LeftVector;
    };

    inline void moveUp(const float delta) {
         m_Position += delta * m_UpVector;
    };
    
    inline void rotateLeft(const float degrees) {
        m_fPhi -= glm::radians(degrees);
        computeDirectionVectors();
    };

    inline void rotateUp(const float degrees) {
        m_fTheta -= glm::radians(degrees);
        computeDirectionVectors();
    };

    inline glm::mat4 getViewMatrix() const {
        return glm::lookAt(
            m_Position, 
            m_Position + m_FrontVector,
            m_UpVector);
    };

private:
    glm::vec3 m_Position;
    float m_fPhi;
    float m_fTheta; 

    glm::vec3 m_FrontVector;
    glm::vec3 m_LeftVector;
    glm::vec3 m_UpVector;

    void computeDirectionVectors();
};
    
}