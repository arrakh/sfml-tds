//
// Created by Arya Rakha on 5/1/2023.
//

#include <iostream>
#include "PlayerEntity.h"
#include "CoreContext.h"
#include "VectorMath.h"

void PlayerEntity::update() {
    finalSize = VectorMath::scalar(size, scale);

    const float speed = 400.0f;
    sf::Vector2f movement{};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x = movement.x - 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x = movement.x + 1.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y = movement.y - 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y = movement.y + 1.0f;

    position = position + (VectorMath::normalize(movement) * speed * CoreContext::deltaTime());
    //std::cout << "\nPlayer Position - x:" << position.x << " y:" << position.y;
}

void PlayerEntity::render(sf::RenderTarget *renderTarget) {
    spriteRenderer.render(renderTarget);
    collider.debugRender(renderTarget);
}

PlayerEntity::PlayerEntity() : Entity() {
    size = scale * 30.0f;
    spriteRenderer.setColor(sf::Color(255, 0, 0));
    collider.init();
    std::cout << "\nCREATING PLAYER ENTITY WITH COLLIDER ID " << collider.getId() << " AT x:" << position.x << " y:" << position.y;
}
