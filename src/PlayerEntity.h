//
// Created by Arya Rakha on 5/1/2023.
//

#ifndef CMAKESFMLPROJECT_PLAYERENTITY_H
#define CMAKESFMLPROJECT_PLAYERENTITY_H

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "EntitySpriteRenderer.h"
#include "RectEntityCollider.h"


class PlayerEntity : public Entity {
private:
public:
    PlayerEntity();

public:
    void update() override;
    void render(sf::RenderTarget *renderTarget) override;

private:
    EntitySpriteRenderer spriteRenderer {this, finalSize};
    RectEntityCollider collider {position, finalSize};

    sf::Vector2f size;
    sf::Vector2f finalSize;
};


#endif //CMAKESFMLPROJECT_PLAYERENTITY_H
