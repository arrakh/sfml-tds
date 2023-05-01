//
// Created by Arya Rakha on 5/1/2023.
//

#ifndef CMAKESFMLPROJECT_CORECONTEXT_H
#define CMAKESFMLPROJECT_CORECONTEXT_H

#include <SFML/Graphics.hpp>
#include <stack>
#include "Scene.h"

class CoreContext {
private:
    sf::RenderWindow* window;
    sf::Event sfEvent;
    sf::Clock deltaClock;

    std::stack<Scene*> sceneStack;

    static float dt;

    void updateDeltaTime();
    void updateSFMLEvents();
    void update();
    void render();

public:
    CoreContext();

    static float deltaTime();

    void run();
    void enterScene(Scene* scene);
    void exitScene();
};


#endif //CMAKESFMLPROJECT_CORECONTEXT_H
