//
// Created by Arya Rakha on 5/1/2023.
//

#ifndef CMAKESFMLPROJECT_ENTITYSPRITERENDERER_H
#define CMAKESFMLPROJECT_ENTITYSPRITERENDERER_H
#include "SFML/Graphics.hpp"
#include "Entity.h"

class EntitySpriteRenderer {
public:
    EntitySpriteRenderer(Entity* target, sf::Vector2f& size);
    void render(sf::RenderTarget* renderTarget);
    void setColor(sf::Color color);

private:
    sf::Vector2f &rectSize;
    Entity* targetEntity;
    sf::RectangleShape rect;
};


#endif //CMAKESFMLPROJECT_ENTITYSPRITERENDERER_H
