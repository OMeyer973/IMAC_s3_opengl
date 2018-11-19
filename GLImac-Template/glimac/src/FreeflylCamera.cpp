#include <cmath>
#include <vector>
#include <iostream>
#include "glimac/common.hpp"
#include "glimac/FreeflyCamera.hpp"

namespace glimac {

void FreeflyCamera::computeDirectionVectors() {
    m_FrontVector = glm::vec3(
        glm::cos(m_fTheta) * glm::sin(m_fPhi),
        glm::sin(m_fTheta), 
        glm::cos(m_fTheta) * glm::cos(m_fPhi));

    m_LeftVector = glm::vec3(
        glm::sin(m_fPhi + glm::half_pi<float>()),
        0,
        glm::cos(m_fPhi + glm::half_pi<float>()));
    
    m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
};

}
