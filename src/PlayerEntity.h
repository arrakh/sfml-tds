//
// Created by Arya Rakha on 5/1/2023.
//

#ifndef CMAKESFMLPROJECT_PLAYERENTITY_H
#define CMAKESFMLPROJECT_PLAYERENTITY_H

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "EntitySpriteRenderer.h"


class PlayerEntity : public Entity {
private:
public:
    PlayerEntity();

public:
    void update() override;
    void render(sf::RenderTarget *renderTarget) override;

private:
    EntitySpriteRenderer spriteRenderer {this, scale * 30.0f};
};


#endif //CMAKESFMLPROJECT_PLAYERENTITY_H
