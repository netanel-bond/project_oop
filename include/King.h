#pragma once
#include "Player.h"

class King : public Player {
public:
	using Player::Player;

	virtual void handleCollision(Moving& moving, const sf::Vector2f moveDirection)override {};


	virtual void handleCollision(Mage& mage, const sf::Vector2f moveDirection) override {};

private:




};