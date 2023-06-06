#include "InputManagerDemo.h"
#include <iostream>
#include <string>
#include <sstream>
#include "imgui.h"

void InputManagerDemo::Start()
{
	manager.SetAxisInputCallback(CIDPlayer1, RightToggleY, [this](float axisval){player1.Move(axisval);});
	manager.SetAxisInputCallback(CIDPlayer1, RightToggleX, [this](float axisval){player1.Turn(axisval); });
	manager.SetButtonPressCallback(CIDPlayer1, AButton, [this](){player1.ChangeColor(Vec3(0, 1, 0)); });
	manager.SetButtonReleaseCallback(CIDPlayer1, AButton, [this]() {player1.ChangeColor(Vec3(1, 0, 0)); });

}

void InputManagerDemo::Update(float delta)
{
	manager.UpdateInputManager();
	Draw();
	deltaTime = delta;

	// Strings to hold Joystick Test data Need to add a summary to explain naming conventions later
	// 14 buttons 6 axes 2 counts.
	int Joystick1AxesCount;
	std::stringstream joystick1AxisCount; std::string Joystick1AxisCount;
	std::stringstream joystick1Axis0; std::string Joystick1Axis0;
	std::stringstream joystick1Axis1; std::string Joystick1Axis1;
	std::stringstream joystick1Axis2; std::string Joystick1Axis2;
	std::stringstream joystick1Axis3; std::string Joystick1Axis3;
	std::stringstream joystick1Axis4; std::string Joystick1Axis4;
	std::stringstream joystick1Axis5; std::string Joystick1Axis5;
	int Joystick1ButtonCount;
	std::stringstream joystick1ButtonsCount; std::string Joystick1ButtonsCount;
	std::stringstream joystick1AXYBButtons; std::string Joystick1AXYBButtons;
	std::stringstream joystick1TriggerandMenuButtons; std::string Joystick1TriggerandMenuButtons;
	std::stringstream joystick1ToggleButtons; std::string Joystick1ToggleButtons;
	std::stringstream joystick1DPADButtons; std::string Joystick1DPADButtons;

	if (glfwJoystickPresent(GLFW_JOYSTICK_1) == 1)
	{
		const float* Joystick1AxesArrayptr = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &Joystick1AxesCount);
		joystick1AxisCount << "Joystick1 Axes " << Joystick1AxesCount; Joystick1AxisCount = joystick1AxisCount.str();
		joystick1Axis0 << "Left toggle X  " << round(Joystick1AxesArrayptr[0] * 100) / 100; Joystick1Axis0 = joystick1Axis0.str();
		joystick1Axis1 << "Left toggle Y  " << round(Joystick1AxesArrayptr[1] * 100) / 100; Joystick1Axis1 = joystick1Axis1.str();
		joystick1Axis2 << "Right toggle X " << round(Joystick1AxesArrayptr[2] * 100) / 100; Joystick1Axis2 = joystick1Axis2.str();
		joystick1Axis3 << "Right toggle Y " << round(Joystick1AxesArrayptr[3] * 100) / 100; Joystick1Axis3 = joystick1Axis3.str();
		joystick1Axis4 << "Left trigger   " << round(Joystick1AxesArrayptr[4] * 100) / 100; Joystick1Axis4 = joystick1Axis4.str(); // the objective is to limit precision to 2 decimal places but I have no idea how.
		joystick1Axis5 << "Right trigger  " << round(Joystick1AxesArrayptr[5] * 100) / 100; Joystick1Axis5 = joystick1Axis5.str();
		const unsigned char* Joystick1ButtonArrayptr = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &Joystick1ButtonCount);
		joystick1ButtonsCount << "Controller 1 button count " << Joystick1ButtonCount; Joystick1ButtonsCount = joystick1ButtonsCount.str();
		joystick1AXYBButtons << "(A" << (Joystick1ButtonArrayptr[0] == GLFW_PRESS ? '1' : '0') << ") (B" << (Joystick1ButtonArrayptr[1] == GLFW_PRESS ? '1' : '0')
			<< ") (X" << (Joystick1ButtonArrayptr[2] == GLFW_PRESS ? '1' : '0') << ") (Y" << (Joystick1ButtonArrayptr[3] == GLFW_PRESS ? '1' : '0') << ")";
		Joystick1AXYBButtons = joystick1AXYBButtons.str();
		joystick1TriggerandMenuButtons << "(LB" << (Joystick1ButtonArrayptr[4] == GLFW_PRESS ? '1' : '0') << ") (RB"
			<< (Joystick1ButtonArrayptr[5] == GLFW_PRESS ? '1' : '0') << ") (Back" << (Joystick1ButtonArrayptr[6] == GLFW_PRESS ? '1' : '0')
			<< ") Start" << (Joystick1ButtonArrayptr[7] == GLFW_PRESS ? '1' : '0') /* << ") XBox Button" << (Joystick1ButtonArrayptr[14] == GLFW_PRESS ? '1' : '0')*/ << ")";
			Joystick1TriggerandMenuButtons = joystick1TriggerandMenuButtons.str();
			joystick1ToggleButtons << "(Left Toggle" << (Joystick1ButtonArrayptr[8] == GLFW_PRESS ? '1' : '0') << ") Right Toggle" << (Joystick1ButtonArrayptr[9] == GLFW_PRESS ? '1' : '0');
			Joystick1ToggleButtons = joystick1ToggleButtons.str();
			joystick1DPADButtons << "(Dpad Up" << (Joystick1ButtonArrayptr[10] == GLFW_PRESS ? '1' : '0') << ") Dpad Right" << (Joystick1ButtonArrayptr[11] == GLFW_PRESS ? '1' : '0')
				<< ") (Dpad Down" << (Joystick1ButtonArrayptr[12] == GLFW_PRESS ? '1' : '0') << ") Dpad Left" << (Joystick1ButtonArrayptr[13] == GLFW_PRESS ? '1' : '0') << ")";
			Joystick1DPADButtons = joystick1DPADButtons.str();
			// I tried to figure out how to create an array of std::string but there's no point if the only way I can do it is through pointers.
			// so instead I'll add several outputs to individual strings

	}

	ImGui::Begin("Window");

	ImGui::Text(Joystick1AxisCount.c_str());
	ImGui::Text(Joystick1Axis0.c_str());
	ImGui::Text(Joystick1Axis1.c_str());
	ImGui::Text(Joystick1Axis2.c_str());
	ImGui::Text(Joystick1Axis3.c_str());
	ImGui::Text(Joystick1Axis4.c_str());
	ImGui::Text(Joystick1Axis5.c_str());
	ImGui::Text(Joystick1ButtonsCount.c_str());
	ImGui::Text(Joystick1AXYBButtons.c_str());
	ImGui::Text(Joystick1TriggerandMenuButtons.c_str());
	ImGui::Text(Joystick1ToggleButtons.c_str());
	ImGui::Text(Joystick1DPADButtons.c_str());

	ImGui::End();
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

