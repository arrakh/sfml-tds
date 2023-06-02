//
// Created by Arya Rakha on 5/7/2023.
//

#include <iostream>
#include "RectEntityCollider.h"
#include "SimplePhysics2D.h"

bool RectEntityCollider::intersects(ICollider *withCollider) {
    if (auto otherBox = dynamic_cast<RectEntityCollider*>(withCollider)) {
        sf::Vector2f thisMin = entityPosition - size / 2.f;
        sf::Vector2f thisMax = entityPosition + size / 2.f;
        sf::Vector2f otherMin = otherBox->entityPosition - otherBox->size / 2.f;
        sf::Vector2f otherMax = otherBox->entityPosition + otherBox->size / 2.f;
        return thisMax.x >= otherMin.x && thisMin.x <= otherMax.x
               && thisMax.y >= otherMin.y && thisMin.y <= otherMax.y;
    }

    std::cout << "\nCOLLIDES WITH NOTHING??";
    return false;
}

void RectEntityCollider::onCollision(ICollider *withCollider) {
    if (auto otherBox = dynamic_cast<RectEntityCollider*>(withCollider)){
        std::cout << "\nCOL " << colliderId << " IS COLLIDING WITH COL " << otherBox->colliderId;
    }
}

float RectEntityCollider::getPrunePosition() const {
    return entityPosition.x;
}

float RectEntityCollider::getLeftBound() const {
    return entityPosition.x - (size.x / 2.0f);
}

float RectEntityCollider::getRightBound() const {
    return entityPosition.x + (size.x / 2.0f);
}

RectEntityCollider::RectEntityCollider(sf::Vector2f &entityPosition, sf::Vector2f &size) : entityPosition(entityPosition), size(size) {

}

void RectEntityCollider::debugRender(sf::RenderTarget *renderTarget) {
    debugShape.setPosition(entityPosition.x - size.x / 2.0f, entityPosition.y - size.y / 2.0f);
    debugShape.setFillColor(sf::Color{0, 0, 0, 0});
    debugShape.setOutlineColor(sf::Color{0, 255, 0, 255});
    debugShape.setOutlineThickness(2.0f);
    renderTarget->draw(debugShape);

    //std::cout << "\nDEBUG RENDER ID " << colliderId;
}

RectEntityCollider::~RectEntityCollider() {
    if (!hasInit) return;
    std::cout << "\nWILL REMOVE RECT ENTITY COLLIDER WITH ID " << colliderId;

    SimplePhysics2D::removeCollider(colliderId);
}

uint32_t RectEntityCollider::getId() {
    return colliderId;
}

void RectEntityCollider::init() {
    colliderId = SimplePhysics2D::registerCollider(this);

    std::cout << "\nREGISTERED RECT ENTITY COLLIDER WITH ID " << colliderId;

    hasInit = true;
}
