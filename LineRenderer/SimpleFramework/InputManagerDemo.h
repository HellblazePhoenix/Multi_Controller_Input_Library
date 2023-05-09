#pragma once
#include "ApplicationHarness.h"
#include "Maths.h"
#include <vector>


/// <summary>
/// The idea is to link up two players to individual controlers with the controllers being 
/// able to move and change the color of the player they are associated with.
/// </summary>
class InputManagerDemo : public Application
{
private:
	struct player
	{
		Vec2 position; // position of the player
		Vec3 Facing; // direction of the player through faux rotation
		float radius; // size of the player 
		Vec3 color; // color of the player
	};
	//std::vector<player> players; //maybe later
	player player1;
	player player2;



public:

	void Start();
	void Update(float delta);

	void DrawPlayerCharacter(player target);

/// <summary>
/// Group any draw calls under this function.
/// </summary>
	void Draw();

};
