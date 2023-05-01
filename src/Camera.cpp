//
// Created by Arya Rakha on 5/1/2023.
//

#include <iostream>
#include "Camera.h"
#include "CoreContext.h"
#include "VectorMath.h"

void Camera::update(sf::View* view) {
    const float speed = 200.0f;

    if (toFollow){
        position = VectorMath::smoothDamp(position, toFollow->position, velocity, 2.0f,
                                          CoreContext::deltaTime());
    }

    view->setCenter(position);
}

void Camera::setFollow(Entity *entity) {
    toFollow = entity;
}
