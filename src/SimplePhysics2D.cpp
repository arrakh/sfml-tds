//
// Created by Arya Rakha on 5/7/2023.
//

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include "SimplePhysics2D.h"

std::map<uint32_t, ICollider*> SimplePhysics2D::colliders{};
uint32_t SimplePhysics2D::gid = 0;

uint32_t SimplePhysics2D::registerCollider(ICollider *collider) {
    gid++;

    colliders.emplace(gid, collider);

    return uint32_t{gid};
}

void SimplePhysics2D::removeCollider(uint32_t id) {
    auto it = colliders.find(id); // find the iterator for the collider with the given ID
    if (it != colliders.end()) { // if the collider with the given ID is found
        colliders.erase(it); // erase the collider from the map
    }
}

void SimplePhysics2D::physicsUpdate() {
    const bool debug = false;
    if (debug) std::system("cls");
    if (debug) std::cout << "\n===========================================";
    if (debug) std::cout << "\n============= PHYSICS REPORT ==============\n";

    // create a vector of pairs containing the key-value pairs from the colliders map
    std::vector<std::pair<uint32_t, ICollider*>> collider_pairs(colliders.begin(), colliders.end());

    auto pruneCompare = [](const std::pair<uint32_t, ICollider*> & a, const std::pair<uint32_t, ICollider*> & b){
        return a.second->getPrunePosition() < b.second->getPrunePosition();
    };

    // sort the vector by xPosition
    std::sort(collider_pairs.begin(), collider_pairs.end(), pruneCompare);
    if (debug) std::cout << "\nSorted " << collider_pairs.size() << " Pairs";

    // Group the colliders that are overlapping along the x-axis
    std::vector<std::vector<ICollider*>> possible_collisions;
    for (size_t i = 0; i < collider_pairs.size(); i++) {

        ICollider* collider = collider_pairs[i].second;

        float left_edge = collider->getLeftBound();
        float right_edge = collider->getRightBound();
        if (debug) std::cout << "\n[" << collider_pairs[i].first << "] left: " << left_edge << ", right: " << right_edge;

        std::vector<ICollider*> overlapping_colliders;
        overlapping_colliders.push_back(collider);

        for (size_t j = i + 1; j < collider_pairs.size(); j++) {

            ICollider* other_collider = collider_pairs[j].second;

            float other_left_edge = other_collider->getLeftBound();
            if (debug) std::cout << "\n    [" << collider_pairs[j].first << "] IS " << other_left_edge << " > " << right_edge << "?";

            if (other_left_edge > right_edge) break;  // No more overlapping colliders

            float other_right_edge = other_collider->getRightBound();
            if (debug) std::cout << "\n    [" << collider_pairs[j].first << "] IS " << other_right_edge << " >= " << left_edge << "?";

            if (other_right_edge < left_edge) break;
            overlapping_colliders.push_back(other_collider);
        }

        if (overlapping_colliders.size() > 1) possible_collisions.push_back(overlapping_colliders);
    }

    // Check for collisions within each group of overlapping colliders
    for (const auto& group : possible_collisions) {
        if (debug) std::cout << "\nChecking group with " << group.size() << " coll...";
        for (size_t i = 0; i < group.size(); i++) {
            ICollider* collider = group[i];
            for (size_t j = i + 1; j < group.size(); j++) {
                ICollider* other_collider = group[j];
                if (collider->intersects(other_collider)) {
                    collider->onCollision(other_collider);
                    other_collider->onCollision(collider);
                }
            }
        }
    }

    if (debug) std::cout << "\n\n-------------------------------------------\n";
}
