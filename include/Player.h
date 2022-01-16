#pragma once

#include "Moving.h"
#include "Static.h"
#include "Gift.h"

#include <memory>

using std::unique_ptr;

class Teleporter;
class Fire;
class Key;
class Orc;
class Gate;
class Dwarf;

class Player : public Moving {
public:

    using Moving::Moving;
    virtual void handleCollision(Static& staticObject) override;
    void handleCollision(Teleporter& teleport);
    virtual void handleCollision(Player& player)override {};
    virtual void handleCollision(Dwarf& Dwarf)override {};
    virtual void handleCollision(Mage& mage) override {};
    virtual void handleCollision(Fire& fire) = 0;
    virtual void handleCollision(Key& key) = 0;
    virtual void handleCollision(Orc& orc) = 0;
    virtual void handleCollision(Gate& gate) = 0;
    void handleCollision(Gift& gift, vector<unique_ptr<Dwarf>>&);
    void handleCollision(Gift& gift, float deltaTime);


    

    void stayInPlace();

private:


};