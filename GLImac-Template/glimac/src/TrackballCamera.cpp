#include <cmath>
#include <vector>
#include <iostream>
#include "glimac/common.hpp"
#include "glimac/TrackballCamera.hpp"

namespace glimac {

glm::mat4 TrackballCamera::getViewMatrix() const{
    glm::mat4 ViewMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -m_fDistance));
    ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleX), glm::vec3(1,0,0));
    ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleY), glm::vec3(0,1,0));
    return ViewMatrix;
};

}
