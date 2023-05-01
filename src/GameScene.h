//
// Created by Arya Rakha on 5/1/2023.
//

#ifndef CMAKESFMLPROJECT_GAMESCENE_H
#define CMAKESFMLPROJECT_GAMESCENE_H


#include "Scene.h"
#include "PlayerEntity.h"
#include "Camera.h"

class GameScene : public Scene {
public:
    void update() override;

    GameScene();

    void render(sf::RenderTarget *renderTarget) override;

private:
    PlayerEntity player;
    sf::View worldView;
    sf::RectangleShape ground;
    sf::Texture groundTexture;
    Camera camera;

    float zoom = 1.0f;
};


#endif //CMAKESFMLPROJECT_GAMESCENE_H
