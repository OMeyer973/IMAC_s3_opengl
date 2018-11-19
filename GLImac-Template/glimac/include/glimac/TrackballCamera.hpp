#pragma once

#include "common.hpp"

namespace glimac {

// TrackballCamera
class TrackballCamera {
    
public:
    // Constructeur: initialise la distance et les angles
    inline TrackballCamera()
    :m_fDistance(5), m_fAngleX(0), m_fAngleY(0)
    {};

    // Constructeur: initialise la distance et les angles
    inline TrackballCamera(const float fDistance, const float fAngleX, const float fAngleY)
    :m_fDistance(fDistance), m_fAngleX(fAngleX), m_fAngleY(fAngleY)
    {};

    inline void moveFront(const float delta) {
        m_fDistance -= delta;  
    };

    inline void rotateLeft(const float degrees) {
        m_fAngleX += degrees;
    };

    inline void rotateUp(const float degrees) {
        m_fAngleY += degrees;
    };

    glm::mat4 getViewMatrix() const;

private:
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;
};
    
}