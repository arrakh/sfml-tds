//
// Created by Arya Rakha on 5/1/2023.
//

#include "EntitySpriteRenderer.h"

EntitySpriteRenderer::EntitySpriteRenderer(Entity *target, sf::Vector2f & size) : targetEntity(target), rectSize(size) {
    rect.setSize(size);
}

void EntitySpriteRenderer::render(sf::RenderTarget *renderTarget) {
    rect.setPosition(targetEntity->position.x - rectSize.x / 2.0f, targetEntity->position.y - rectSize.y / 2.0f);
    rect.setSize(rectSize);
    renderTarget->draw(rect);
}

void EntitySpriteRenderer::setColor(sf::Color color) {
    rect.setFillColor(color);
}
