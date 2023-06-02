//
// Created by Arya Rakha on 5/7/2023.
//

#ifndef CMAKESFMLPROJECT_SIMPLEPHYSICS2D_H
#define CMAKESFMLPROJECT_SIMPLEPHYSICS2D_H


#include <vector>
#include <string>
#include <map>
#include "ICollider.h"

class SimplePhysics2D {
public:
    static void physicsUpdate();
    static uint32_t registerCollider(ICollider* collider);
    static void removeCollider(uint32_t id);

private:
    static std::map<uint32_t, ICollider*> colliders;
    static uint32_t gid;
};


#endif //CMAKESFMLPROJECT_SIMPLEPHYSICS2D_H
