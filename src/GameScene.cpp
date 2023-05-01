//
// Created by Arya Rakha on 5/1/2023.
//

#include <iostream>
#include "GameScene.h"
#include "CoreContext.h"

void GameScene::update() {
    player.update();
    camera.update(&worldView);
}

void GameScene::render(sf::RenderTarget *renderTarget) {
    renderTarget->setView(worldView);
    renderTarget->draw(ground);
    player.render(renderTarget);
    renderTarget->setView(renderTarget->getDefaultView());
}

GameScene::GameScene() {
    const float width = 1280.0f;
    const float height = 720.0f;
    worldView.setSize(width, height);
    worldView.setCenter(0, 0);

    sf::Vector2f groundSize {10000.0f, 10000.0f};
    ground.setSize(groundSize);
    ground.setPosition(-groundSize/2.0f);

    if (!groundTexture.loadFromFile("../assets/img/ground.jpg")) {
        std::cout << "\n[ERROR] COULD NOT LOAD GROUND IMAGE";
        return;
    }

    std::cout << "\nLOADED GROUND TEXTURE";
    groundTexture.setRepeated(true);
    ground.setTextureRect({0, 0, 10000, 10000});
    ground.setTexture(&groundTexture);

    camera.setFollow(&player);
}
