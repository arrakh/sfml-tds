#include <SFML/Graphics.hpp>
#include <iostream>
#include "CoreContext.h"
#include "GameScene.h"

int main()
{
    CoreContext ctx{};
    std::cout << "CREATING CORE CONTEXT";
    ctx.enterScene(new GameScene());
    std::cout << "\nENTERING GAME SCENE";
    ctx.run();
}