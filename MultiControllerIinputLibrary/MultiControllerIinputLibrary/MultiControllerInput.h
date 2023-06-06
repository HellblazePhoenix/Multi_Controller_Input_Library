#pragma once

// MultiControllerIinputLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

enum XboxAxesID:int
{
	LeftToggleX = 0,
	LeftToggleY = 1,
	RightToggleX = 2,
	RightToggleY = 3,
	LeftTrigger = 4,
	RightTrigger = 5
};

enum XboxButtonID:int
{
	AButton = 0,
	BButton = 1,
	XButton = 2,
	YButton = 3,
	LBButton = 4,
	RBButton = 5,
	BackButton = 6,
	StartButton = 7,
	LeftToggle = 8,
	RightToggle = 9,
	DpadUp = 10,
	DpadRight = 11,
	DpadDown = 12,
	DpadLeft = 13,
};

enum ControllerID:int
{
	CIDPlayer1 = GLFW_JOYSTICK_1,
	CIDPlayer2 = GLFW_JOYSTICK_2,
	CIDPlayer3 = GLFW_JOYSTICK_3,
	CIDPlayer4 = GLFW_JOYSTICK_4,
	CIDPlayer5 = GLFW_JOYSTICK_5,
	CIDPlayer6 = GLFW_JOYSTICK_6,
	CIDPlayer7 = GLFW_JOYSTICK_7,
	CIDPlayer8 = GLFW_JOYSTICK_8,
	CIDPlayer9 = GLFW_JOYSTICK_9,
	CIDPlayer10 = GLFW_JOYSTICK_10,
	CIDPlayer11 = GLFW_JOYSTICK_11,
	CIDPlayer12 = GLFW_JOYSTICK_12,
	CIDPlayer13 = GLFW_JOYSTICK_13,
	CIDPlayer14 = GLFW_JOYSTICK_14,
	CIDPlayer15 = GLFW_JOYSTICK_15,
	CIDPlayer16 = GLFW_JOYSTICK_LAST,
};

//////////////////////////////////////////// TODO implement button held in Input manager and spawn test window, then start testing.

/// <summary>
/// An object that handles input from controllers.
/// </summary>
class InputManager
{
private: // private variables and all methods are camel case first letter capatilised


	/// <summary>
	/// A vector that keeps track of the active ControllerIDs to prevent errors from occuring due to checking inactive IDs.
	/// </summary>
	std::array<bool, 16> ActiveControllers;
	/// <summary>
	/// A vector that holds the size/number of axes on each controller that has been connected.
	/// </summary>
	std::array<int, 16> NumAxes;
	/// <summary>
	/// A vector that holds pointers to the memory adresses of the axes on each controller.
	/// </summary>
	std::array<const float*, 16> ControllerAxes;
	/// <summary>
	/// A vector that keeps track of the active Axes to prevent errors from occuring due to checking inactive IDs.
	/// </summary>
	std::array<std::array<bool, 6>, 16> ActiveAxes;
	/// <summary>
	/// the vector that holds functions to execute on axes defined by the user in SetAxisInputCallback.
	/// </summary>
	std::array<std::array<std::function<void(float axisVal)>, 6>, 16> AxesFuncs;
	/// <summary>
	/// A vector that holds the size/number of buttons on each controller that has been connected.
	/// </summary>
	std::array<int, 16> NumButtons;
	/// <summary>
	/// A vector that holds pointers to the memory adresses of the button states on each controller.
	/// </summary>
	std::array<const unsigned char*, 16> Buttons;
	/// <summary>
	/// A vector that keeps track of the buttons with active press functions.
	/// </summary>
	std::array<std::array<bool, 14>, 16> ActivePressButtons;
	/// <summary>
	/// A vector that keeps track of the buttons with active release functions.
	/// </summary>
	std::array<std::array<bool, 14>, 16> ActiveReleaseButtons;
	/// <summary>
	/// the vector that holds functions to execute when pressing defined by the user in SetButtonPressCallback.
	/// </summary>
	std::array<std::array<std::function<void()>, 14>, 16> ButtonPressFuncs;
	/// <summary>
	/// the vector that holds functions to execute when releasing a button defined by the user in SetButtonReleaseCallback.
	/// </summary>
	std::array<std::array<std::function<void()>, 14>, 16> ButtonReleaseFuncs;
	/// <summary>
	/// A vector that holds pointers to the memory adresses of the buttons on each controller but only updates at the end of the update meaning it holds the button state from the previous update.
	/// </summary>
	std::array<std::array< unsigned char, 14>, 16> ButtonsLastUpdate;


	/// <summary>
	/// A possible constructor that in theory will run the update function on itself in a loop while the rest of the program is running.
	/// </summary>
	//InputManager();
	/// <summary>
	/// A destructor to explicitly delete the input manager should it be neccessary. 
	/// </summary>
	//~InputManager();


public:

	//Should execFunc take deltatime? Or should that be left to the application user of the library? I could also have
	//a delta time variable in the input manager but that could get dicey fast.

	/// <summary>
	/// takes a ControllerID, an XboxButtonID and a function pointer then sets a callback that executes execFunc when the XboxButtonID button is pressed.
	/// If you want to pass in a method belonging to a class then use a lambda [ANDclassInstanceName](){classInstanceName.functionName();}.
	/// </summary>
	/// <param name="jid"></param>
	/// <param name="bbutton"></param>
	/// <param name="execFunc"></param>
	void SetButtonPressCallback(int controllerID, int button, std::function<void()> execFunc);

	/// <summary>
	/// Sets button released callbacks for all controllers from player1 to the input ControllerID.
	/// </summary>
	void SetButtonPressCallbackMultipleControllers(int controllerIDEnd, int button, std::function<void()> execFunc);

	/// <summary>
	/// takes a ControllerID, an XboxButtonID and a function pointer then sets a callback that executes execFunc when the XboxButtonID button is released.
	/// If you want to pass in a method belonging to a class then use a lambda [ANDclassInstanceName](){classInstanceName.functionName();}.
	/// </summary>
	void SetButtonReleaseCallback(int controllerID, int button, std::function<void()> execFunc);

	/// <summary>
	/// Sets button released callbacks for all controllers from player1 to the input ControllerID.
	/// </summary>
	void SetButtonReleaseCallbackMultipleControllers(int ControllerIDEnd, int button, std::function<void()> execFunc);

	// OPTIONAL TODO Button held?

	/// <summary> 
	/// Takes a ControllerID and an axis ID and sets a callback to execute a function that takes a float based on the state of the trigger.
	/// It should be noted that you should also use this function to individually querry the axes of the toggles on the controller.
	/// If you want to pass in a method belonging to a class then use a lambda [ANDclassInstanceName](){classInstanceName.functionName();}.
	/// </summary>
	/// <param name="jid"></param>
	/// <param name="trigger"></param>
	/// <param name="execFunc"></param>
	void SetAxisInputCallback(int controllerID, int axisID, std::function<void(float axisVal)> execFunc);
	
	/// <summary>
	/// Sets Axis callbacks for all controllers from player1 to the input ControllerID.
	/// </summary>
	void SetAxisInputCallbackMultipleControllers(int ControllerIDEnd, int axisID, std::function<void(float axisVal)> execFunc);


	//void ToggleInput(int jid, int toggle, std::function<void(float xVal, float yVal)> execFunc); // Optional TODO: implement this function



	/// <summary>
	/// This should be called in the main loop of an application or game to check for connected controllers.
	/// It also is responsible for calling your set callbacks based on the controller state.
	/// </summary>
	void UpdateInputManager();

	/// <summary>
	/// Creates an IMgui window displaying the states of all the input units on a controller based on the joystick/controller ID passed in.
	/// </summary>
	/// <param name="jid"></param>
	//void SpawnControllerAnalysisWindow(int jid) // this can't be implemented without adding string, sstream and imgui to the library which really just isn't worth it.
};
