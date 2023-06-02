//
// Created by Arya Rakha on 5/1/2023.
//

#ifndef CMAKESFMLPROJECT_VECTORMATH_H
#define CMAKESFMLPROJECT_VECTORMATH_H
#include "SFML/Graphics.hpp"

class VectorMath {
public:
    static sf::Vector2f smoothDamp(sf::Vector2f current, sf::Vector2f target, sf::Vector2f& velocity, float smoothTime, float deltaTime);
    static sf::Vector2f normalize(sf::Vector2f vector);
    static sf::Vector2f scalar(sf::Vector2f vector, sf::Vector2f scalar);
};


#endif //CMAKESFMLPROJECT_VECTORMATH_H
