#pragma once
#include "ApplicationHarness.h"
#include "Maths.h"
#include <vector>
#include "MultiControllerInput.h"


/// <summary>
/// The idea is to link up two players to individual controlers with the controllers being 
/// able to move and change the color of the player they are associated with.
/// </summary>
class InputManagerDemo : public Application
{

private:
	InputManager manager;

	struct player
	{
		InputManagerDemo* demo;
		Vec2 position; // position of the player
		float facingAngle; // direction of the player through faux rotation
		float turnSpeed = 50; // speed of turning
		float moveSpeed = 5; // move speed
		float radius; // size of the player 
		Vec3 color; // color of the player

		player(Vec2 p, float r, Vec3 c, InputManagerDemo* d)
		{
			position = p; facingAngle = 0; radius = r; color = c; demo = d;
		}

		//y toggle for moving forward x toggle for turning
		void Move(float speed) { position += Vec2(glm::cos(glm::radians(facingAngle)), glm::sin(glm::radians(facingAngle))) * 
			(round(speed * 10) / 10) * moveSpeed * demo->deltaTime; } // this is way too sensitive.
		void Turn(float direction) {facingAngle += direction * turnSpeed * demo->deltaTime;}
		void ChangeColor(Vec3 col) { color = col; }
	};
	//std::vector<player> players; //maybe later
	player player1 = player(Vec2(5.0f, 0.0f), 0.5f,Vec3(1, 0, 0), this);
	player player2 = player(Vec2(-5.0f, 0.0f), 0.5f, Vec3(0, 0, 1), this);



public:
	float deltaTime; // I wont argue this is a terrible way to do this so if you could explain an alternative
	//I would greatly apreciate it.

	void Start();
	void Update(float delta);

	void DrawPlayerCharacter(player target);

/// <summary>
/// Group any draw calls under this function.
/// </summary>
	void Draw();





};
