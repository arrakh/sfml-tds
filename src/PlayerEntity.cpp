//
// Created by Arya Rakha on 5/1/2023.
//

#include <iostream>
#include "PlayerEntity.h"
#include "CoreContext.h"
#include "VectorMath.h"

void PlayerEntity::update() {
    const float speed = 400.0f;
    sf::Vector2f movement{};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x = movement.x - 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x = movement.x + 1.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y = movement.y - 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y = movement.y + 1.0f;

    position = position + (VectorMath::normalize(movement) * speed * CoreContext::deltaTime());
}

void PlayerEntity::render(sf::RenderTarget *renderTarget) {
    spriteRenderer.render(renderTarget);
}

PlayerEntity::PlayerEntity() {
    spriteRenderer.setColor(sf::Color(255, 0, 0));
}
