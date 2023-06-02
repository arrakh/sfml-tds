//
// Created by Arya Rakha on 5/1/2023.
//

#include "CoreContext.h"
#include "SimplePhysics2D.h"

float CoreContext::dt = 0.0f;

void CoreContext::updateDeltaTime()
{
    dt = deltaClock.restart().asSeconds();
}

void CoreContext::updateSFMLEvents()
{
    while (window->pollEvent(sfEvent))
    {
        if (sfEvent.type == sf::Event::Closed)
            window->close();

        if (sfEvent.type == sf::Event::Resized){
            auto view = window->getView();
            view.setSize(sfEvent.size.width, sfEvent.size.height);
        }
    }
}

CoreContext::CoreContext() {
    window = new sf::RenderWindow(sf::VideoMode(1280, 720), "SFML TDS");
}

void CoreContext::update()
{
    updateDeltaTime();

    updateSFMLEvents();

    SimplePhysics2D::physicsUpdate();

    sceneStack.top()->update();
}

void CoreContext::render()
{
    window->clear();

    sceneStack.top()->render(window);

    window->display();
}

float CoreContext::deltaTime() {
    return dt;
}

void CoreContext::run() {
    while(window->isOpen()){
        update();
        render();
    }
}

void CoreContext::enterScene(Scene *scene) {
    sceneStack.push(scene);
}

void CoreContext::exitScene() {
    delete sceneStack.top();
    sceneStack.pop();
}
