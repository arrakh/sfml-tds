//
// Created by Arya Rakha on 5/1/2023.
//

#ifndef CMAKESFMLPROJECT_GAMESCENE_H
#define CMAKESFMLPROJECT_GAMESCENE_H


#include "Scene.h"
#include "PlayerEntity.h"
#include "Camera.h"
#include "ObstacleEntity.h"

class GameScene : public Scene {
public:
    void update() override;

    GameScene();

    void render(sf::RenderTarget *renderTarget) override;

private:
    PlayerEntity player;
    ObstacleEntity obstacleTest{sf::Vector2f {100.0f, 100.0f}, sf::Vector2f { 30.0f, 500.0f}};
    sf::View worldView;
    sf::RectangleShape ground;
    sf::Texture groundTexture;
    Camera camera;

    float zoom = 1.0f;
};


#endif //CMAKESFMLPROJECT_GAMESCENE_H
