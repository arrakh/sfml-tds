//
// Created by Arya Rakha on 5/7/2023.
//

#ifndef CMAKESFMLPROJECT_OBSTACLEENTITY_H
#define CMAKESFMLPROJECT_OBSTACLEENTITY_H


#include "Entity.h"
#include "RectEntityCollider.h"
#include "EntitySpriteRenderer.h"

class ObstacleEntity : public Entity{
public:
    ObstacleEntity(const sf::Vector2f &position, const sf::Vector2f &size);

    void update() override;

    void render(sf::RenderTarget *renderTarget) override;

private:
    EntitySpriteRenderer spriteRenderer {this, finalSize};
    RectEntityCollider collider{position, finalSize};

    sf::Vector2f size;
    sf::Vector2f finalSize;
};


#endif //CMAKESFMLPROJECT_OBSTACLEENTITY_H
