//
// Created by Arya Rakha on 5/7/2023.
//

#ifndef CMAKESFMLPROJECT_ICOLLIDER_H
#define CMAKESFMLPROJECT_ICOLLIDER_H


class ICollider {
public:
    virtual float getPrunePosition() const = 0;
    virtual float getLeftBound() const = 0;
    virtual float getRightBound() const = 0;
    virtual bool intersects(ICollider* withCollider) = 0;
    virtual void onCollision(ICollider* withCollider) = 0;
};


#endif //CMAKESFMLPROJECT_ICOLLIDER_H
