#include "InputManagerDemo.h"

void InputManagerDemo::Update(float delta)
{
}

void InputManagerDemo::DrawPlayerCharacter(player target)
{
	lines->DrawCircle(target.position, target.radius, target.color);
}


void InputManagerDemo::Draw()
{
	DrawPlayerCharacter(player1);
	DrawPlayerCharacter(player2);
}
