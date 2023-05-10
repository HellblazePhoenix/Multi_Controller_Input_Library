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

	//bool thisIsACheckboxVal = true;

	// Strings to hold Joystick Test data
	int Joystick1AxesCount;
	std::stringstream joystick1AxisCount; std::string Joystick1AxisCount;
	std::stringstream joystick1Axis0; std::string Joystick1Axis0;
	std::stringstream joystick1Axis1; std::string Joystick1Axis1;
	std::stringstream joystick1Axis2; std::string Joystick1Axis2;
	std::stringstream joystick1Axis3; std::string Joystick1Axis3;
	std::stringstream joystick1Axis4; std::string Joystick1Axis4;
	std::stringstream joystick1Axis5; std::string Joystick1Axis5;
	int Joystick1ButtonCount;
	std::stringstream joystick1DPADButtons; std::string Joystick1DPADButtons;
	std::stringstream joystick1AXYBButtons; std::string Joystick1AXYBButtons;
	std::stringstream joystick1TriggerandToggleButtons; std::string Joystick1TriggerandToggleButtons;


	int Joystick2AxesCount;
	std::stringstream joystick2AxisCount; std::string Joystick2AxisCount;
	std::stringstream joystick2Axis0; std::string Joystick2Axis0;
	std::stringstream joystick2Axis1; std::string Joystick2Axis1;
	std::stringstream joystick2Axis2; std::string Joystick2Axis2;
	std::stringstream joystick2Axis3; std::string Joystick2Axis3;
	std::stringstream joystick2Axis4; std::string Joystick2Axis4;
	std::stringstream joystick2Axis5; std::string Joystick2Axis5;
	int Joystick2ButtonCount;
	std::stringstream joystick2DPADButtons; std::string Joystick2DPADButtons;
	std::stringstream joystick2AXYBButtons; std::string Joystick2AXYBButtons;
	std::stringstream joystick2TriggerandToggleButtons; std::string Joystick2TriggerandToggleButtons;






	if (glfwJoystickPresent(GLFW_JOYSTICK_1) == 1)
	{
		const float* Joystick1AxesArrayptr = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &Joystick1AxesCount);
		joystick1AxisCount << Joystick1AxesCount; Joystick1AxisCount = joystick1AxisCount.str();
		joystick1Axis0 << round(Joystick1AxesArrayptr[0]); Joystick1Axis0 = joystick1Axis0.str();
		joystick1Axis1 << round(Joystick1AxesArrayptr[1]); Joystick1Axis1 = joystick1Axis1.str();
		joystick1Axis2 << round(Joystick1AxesArrayptr[2]); Joystick1Axis2 = joystick1Axis2.str();
		joystick1Axis3 << round(Joystick1AxesArrayptr[3]); Joystick1Axis3 = joystick1Axis3.str(); 
		joystick1Axis4 << round(Joystick1AxesArrayptr[4]); Joystick1Axis4 = joystick1Axis4.str(); // the objective is to limit precision to 2 decimal places but I have no idea how.
		joystick1Axis5 << round(Joystick1AxesArrayptr[5]); Joystick1Axis5 = joystick1Axis5.str();
		const float* Joystick1ButtonArrayptr = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &Joystick1ButtonCount);
		// I tried to figure out how to create an array of std::string but there's no point if the only way I can do it is through pointers.
		// so instead I'll add several outputs to individual strings

	}

	if (glfwJoystickPresent(GLFW_JOYSTICK_2) == 1)
	{
		const float* Joystick2Arrayptr = glfwGetJoystickAxes(GLFW_JOYSTICK_2, &Joystick2AxesCount);
		joystick2AxisCount << Joystick2AxesCount; Joystick2AxisCount = joystick2AxisCount.str();
		joystick2Axis1 << round(Joystick2Arrayptr[1]); Joystick2Axis1 = joystick2Axis1.str();
		joystick2Axis2 << round(Joystick2Arrayptr[2]); Joystick2Axis2 = joystick2Axis2.str();
		joystick2Axis0 << round(Joystick2Arrayptr[0]); Joystick2Axis0 = joystick2Axis0.str();
		joystick2Axis3 << round(Joystick2Arrayptr[3]); Joystick2Axis3 = joystick2Axis3.str();
		joystick2Axis4 << round(Joystick2Arrayptr[4]); Joystick2Axis4 = joystick2Axis4.str();
		joystick2Axis5 << round(Joystick2Arrayptr[5]); Joystick2Axis5 = joystick2Axis5.str();
	}


	Joystick1AxisCount = "Joystick1 Axes " + Joystick1AxisCount;
	Joystick1Axis0 = "Left toggle X  " + Joystick1Axis0;
	Joystick1Axis1 = "Left toggle Y  " + Joystick1Axis1;
	Joystick1Axis2 = "Right toggle X " + Joystick1Axis2;
	Joystick1Axis3 = "Right toggle Y " + Joystick1Axis3;
	Joystick1Axis4 = "Left trigger   " + Joystick1Axis4;
	Joystick1Axis5 = "Right trigger  " + Joystick1Axis5;

	Joystick2AxisCount = "Joystick2 Axes " + Joystick2AxisCount;
	Joystick2Axis0 = "Left toggle X  " + Joystick2Axis0;
	Joystick2Axis1 = "Left toggle Y  " + Joystick2Axis1;
	Joystick2Axis2 = "Right toggle X " + Joystick2Axis2;
	Joystick2Axis3 = "Right toggle Y " + Joystick2Axis3;
	Joystick2Axis4 = "Left trigger   " + Joystick2Axis4;
	Joystick2Axis5 = "Right trigger  " + Joystick2Axis5;

	ImGui::Begin("Window");

	ImGui::Text(Joystick1AxisCount.c_str());
	ImGui::Text(Joystick1Axis0.c_str());
	ImGui::Text(Joystick1Axis1.c_str());
	ImGui::Text(Joystick1Axis2.c_str());
	ImGui::Text(Joystick1Axis3.c_str());
	ImGui::Text(Joystick1Axis4.c_str());
	ImGui::Text(Joystick1Axis5.c_str());

	ImGui::Text(Joystick2AxisCount.c_str());
	ImGui::Text(Joystick2Axis0.c_str());
	ImGui::Text(Joystick2Axis1.c_str());
	ImGui::Text(Joystick2Axis2.c_str());
	ImGui::Text(Joystick2Axis3.c_str());
	ImGui::Text(Joystick2Axis4.c_str());
	ImGui::Text(Joystick2Axis5.c_str());
	//if (ImGui::Button("Hello")){}

	//ImGui::Checkbox("Booya", &thisIsACheckboxVal);

	ImGui::End();



	//ImGui::ShowDemoWindow();
	

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

