#include "InputManagerDemo.h"
#include <iostream>
#include <string>
#include <sstream>
#include "imgui.h"

void InputManagerDemo::Start()
{


}

void InputManagerDemo::Update(float delta)
{


	bool thisIsACheckboxVal = true;

	for (size_t i = 0; i < length; i++)
	{
		int joystick1 = glfwJoystickPresent(i);
		for (size_t j = 0; j < 15; j++)
		{

			std::stringstream joystick1Axis =
				std::stringstream joystick1Axis
				//std::cout << joystick1 << std::endl;
		}
	}


	ImGui::Begin("Window");
	ImGui::Text("");
	if (ImGui::Button("Hello"))
	{
	}

	ImGui::Checkbox("Booya", &thisIsACheckboxVal);

	ImGui::End();



	ImGui::ShowDemoWindow();


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
