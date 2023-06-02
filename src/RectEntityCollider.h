//
// Created by Arya Rakha on 5/7/2023.
//

#ifndef CMAKESFMLPROJECT_RECTENTITYCOLLIDER_H
#define CMAKESFMLPROJECT_RECTENTITYCOLLIDER_H

#include "SFML/Graphics.hpp"
#include "ICollider.h"
#include "Entity.h"

class RectEntityCollider : public ICollider {
public:
    RectEntityCollider(sf::Vector2f & entityPosition, sf::Vector2f & size);

    ~RectEntityCollider();

    float getPrunePosition() const override;

    float getLeftBound() const override;

    float getRightBound() const override;

    bool intersects(ICollider *withCollider) override;
    void onCollision(ICollider *withCollider) override;

    void debugRender(sf::RenderTarget* renderTarget);
    void init();

    uint32_t getId();
private:
    sf::Vector2f & entityPosition;
    sf::Vector2f & size;

    sf::RectangleShape debugShape {size};

    uint32_t colliderId = 0;
    bool hasInit = false;
};


#endif //CMAKESFMLPROJECT_RECTENTITYCOLLIDER_H
