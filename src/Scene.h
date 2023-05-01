//
// Created by Arya Rakha on 5/1/2023.
//

#ifndef CMAKESFMLPROJECT_SCENE_H
#define CMAKESFMLPROJECT_SCENE_H
#include <SFML/Graphics.hpp>

class Scene {
public:
    virtual void update() = 0;
    virtual void render(sf::RenderTarget* renderTarget) = 0;
};


#endif //CMAKESFMLPROJECT_SCENE_H
