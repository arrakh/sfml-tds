//
// Created by Arya Rakha on 5/1/2023.
//

#ifndef CMAKESFMLPROJECT_ENTITY_H
#define CMAKESFMLPROJECT_ENTITY_H
#include "SFML/Graphics.hpp"

class Entity {
public:
    Entity();
    virtual ~Entity();

    virtual void update() = 0;
    virtual void render(sf::RenderTarget* renderTarget) = 0;

    sf::Vector2f position {0.0f, 0.0f};
    sf::Vector2f scale {1.0f, 1.0f};
};


#endif //CMAKESFMLPROJECT_ENTITY_H
