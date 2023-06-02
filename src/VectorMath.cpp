//
// Created by Arya Rakha on 5/1/2023.
//

#include <complex>
#include "VectorMath.h"

sf::Vector2f VectorMath::smoothDamp(sf::Vector2f current, sf::Vector2f target, sf::Vector2f &velocity, float smoothTime,
                                    float deltaTime) {
    float smooth = 1.0f - std::exp(-smoothTime * deltaTime);
    sf::Vector2f result = {
            current.x + (target.x - current.x) * smooth,
            current.y + (target.y - current.y) * smooth
    };
    velocity.x += (target.x - current.x) * smooth / deltaTime;
    velocity.y += (target.y - current.y) * smooth / deltaTime;
    return result;
}

sf::Vector2f VectorMath::normalize(sf::Vector2f vector) {
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    if (length != 0) {
        vector.x /= length;
        vector.y /= length;
    }
    return vector;
}

sf::Vector2f VectorMath::scalar(sf::Vector2f vector, sf::Vector2f scalar) {
    return sf::Vector2f{vector.x * scalar.x, vector.y * scalar.y};
}
