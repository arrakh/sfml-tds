//
// Created by Arya Rakha on 5/1/2023.
//

#ifndef CMAKESFMLPROJECT_CAMERA_H
#define CMAKESFMLPROJECT_CAMERA_H

#include "SFML/Graphics.hpp"
#include "Entity.h"

class Camera {
public:
    void update(sf::View* view);
    void setFollow(Entity* entity);

private:
    sf::Vector2f position;
    sf::Vector2f velocity;

    Entity* toFollow;
};


#endif //CMAKESFMLPROJECT_CAMERA_H
