//
// Created by Arya Rakha on 5/7/2023.
//

#include <iostream>
#include "ObstacleEntity.h"
#include "VectorMath.h"

void ObstacleEntity::update() {
    finalSize = VectorMath::scalar(size, scale);

}

void ObstacleEntity::render(sf::RenderTarget *renderTarget) {
    spriteRenderer.render(renderTarget);
    collider.debugRender(renderTarget);
}

ObstacleEntity::ObstacleEntity(const sf::Vector2f &position, const sf::Vector2f &size) : Entity(position), size(size) {
    spriteRenderer.setColor(sf::Color(0, 0, 255, 100));
    collider.init();
    std::cout << "\nCREATING OBSTACLE ENTITY WITH COLLIDER ID " << collider.getId() << " AT x:" << position.x << " y:" << position.y;
}
