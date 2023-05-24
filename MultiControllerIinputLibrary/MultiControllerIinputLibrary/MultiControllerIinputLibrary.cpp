// MultiControllerIinputLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

enum class XboxAxesID
{
	LeftToggle = 0,
	LeftToggleY = 1,
	RightToggle = 2,
	RightToggleY = 3,
	LeftTrigger = 4,
	RightTrigger = 5
};

enum class XboxButtonID
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

enum class ControllerID
{
	Player1 = GLFW_JOYSTICK_1,
	Player2 = GLFW_JOYSTICK_2,
	Player3 = GLFW_JOYSTICK_3,
	Player4 = GLFW_JOYSTICK_4,
	Player5 = GLFW_JOYSTICK_5,
	Player6 = GLFW_JOYSTICK_6,
	Player7 = GLFW_JOYSTICK_7,
	Player8 = GLFW_JOYSTICK_8,
	Player9 = GLFW_JOYSTICK_9,
	Player10 = GLFW_JOYSTICK_10,
	Player11 = GLFW_JOYSTICK_11,
	Player12 = GLFW_JOYSTICK_12,
	Player13 = GLFW_JOYSTICK_13,
	Player14 = GLFW_JOYSTICK_14,
	Player15 = GLFW_JOYSTICK_15,
	Player16 = GLFW_JOYSTICK_LAST,
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
	std::vector<bool> ActiveControllers;
	/// <summary>
	/// A vector that holds the size/number of axes on each controller that has been connected.
	/// </summary>
	std::vector<int> NumAxes;
	/// <summary>
	/// A vector that holds pointers to the memory adresses of the axes on each controller.
	/// </summary>
	std::vector<const float*> ControllerAxes;
	/// <summary>
	/// A vector that keeps track of the active Axes to prevent errors from occuring due to checking inactive IDs.
	/// </summary>
	std::vector<std::vector<bool>> ActiveAxes;
	/// <summary>
	/// the vector that holds functions to execute on axes defined by the user in SetAxisInputCallback.
	/// </summary>
	std::vector<std::vector<std::function<void(float axisVal)>>> AxesFuncs;
	/// <summary>
	/// A vector that holds the size/number of buttons on each controller that has been connected.
	/// </summary>
	std::vector<int> NumButtons;
	/// <summary>
	/// A vector that holds pointers to the memory adresses of the button states on each controller.
	/// </summary>
	std::vector<const unsigned char*> Buttons;
	/// <summary>
	/// A vector that keeps track of the buttons with active press functions.
	/// </summary>
	std::vector<std::vector<bool>> ActivePressButtons;
	/// <summary>
	/// A vector that keeps track of the buttons with active release functions.
	/// </summary>
	std::vector<std::vector<bool>> ActiveReleaseButtons;
	/// <summary>
	/// the vector that holds functions to execute when pressing defined by the user in SetButtonPressCallback.
	/// </summary>
	std::vector<std::vector<std::function<void()>>> ButtonPressFuncs;
	/// <summary>
	/// the vector that holds functions to execute when releasing a button defined by the user in SetButtonReleaseCallback.
	/// </summary>
	std::vector<std::vector<std::function<void()>>> ButtonReleaseFuncs;
	/// <summary>
	/// A vector that holds pointers to the memory adresses of the buttons on each controller but only updates at the end of the update meaning it holds the button state from the previous update.
	/// </summary>
	std::vector<unsigned char*> ButtonsLastUpdate;


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
	/// If you want to pass in a method belonging to a class then use a lambda [&classInstanceName](){classInstanceName.functionName();}.
	/// </summary>
	/// <param name="jid"></param>
	/// <param name="bbutton"></param>
	/// <param name="execFunc"></param>
	void SetButtonPressCallback(int controllerID, int button, std::function<void()> execFunc) { ActivePressButtons[controllerID][button] = true; ButtonPressFuncs[controllerID][button] = execFunc; }
	/// <summary>
	/// Sets button released callbacks for all controllers from player1 to the input ControllerID.
	/// </summary>
	void SetButtonPressCallbackMultipleControllers(int controllerIDEnd, int button, std::function<void()> execFunc)
	{
		for (int i = 0; i < controllerIDEnd; i++)
		{
			ActivePressButtons[i][button] = true; ButtonPressFuncs[i][button] = execFunc;
		}
	}
	/// <summary>
	/// takes a ControllerID, an XboxButtonID and a function pointer then sets a callback that executes execFunc when the XboxButtonID button is released.
	/// If you want to pass in a method belonging to a class then use a lambda [&classInstanceName](){classInstanceName.functionName();}.
	/// </summary>
	void SetButtonReleaseCallback(int controllerID, int button, std::function<void()> execFunc) { ActiveReleaseButtons[controllerID][button] = true; ButtonReleaseFuncs[controllerID][button] = execFunc; }
	/// <summary>
	/// Sets button released callbacks for all controllers from player1 to the input ControllerID.
	/// </summary>
	void SetButtonReleaseCallbackMultipleControllers(int ControllerIDEnd, int button, std::function<void()> execFunc)
	{
		for (int i = 0; i < ControllerIDEnd; i++)
		{
			ActiveReleaseButtons[i][button] = true; ButtonReleaseFuncs[i][button] = execFunc;
		}
	}

    // OPTIONAL TODO: Button held?

	/// <summary> 
	/// Takes a ControllerID and an axis ID and sets a callback to execute a function that takes a float based on the state of the trigger.
	/// It should be noted that you should also use this function to individually querry the axes of the toggles on the controller.
	/// If you want to pass in a method belonging to a class then use a lambda [&classInstanceName](){classInstanceName.functionName();}.
	/// </summary>
	/// <param name="jid"></param>
	/// <param name="trigger"></param>
	/// <param name="execFunc"></param>
	void SetAxisInputCallback(int controllerID, int axisID, std::function<void(float axisVal)> execFunc) { ActiveAxes[controllerID][axisID] = true;  AxesFuncs[controllerID][axisID] = execFunc; }
	/// <summary>
	/// Sets Axis callbacks for all controllers from player1 to the input ControllerID.
	/// </summary>
	void SetAxisInputCallbackMultipleControllers(int ControllerIDEnd, int axisID, std::function<void()> execFunc)
	{
		for (int i = 0; i < ControllerIDEnd; i++)
		{
			ActiveAxes[i][axisID] = true;  AxesFuncs[i][axisID] = execFunc;
		}
	}


	//void ToggleInput(int jid, int toggle, std::function<void(float xVal, float yVal)> execFunc); // Optional TODO: implement this function



	/// <summary>
	/// this should be called in the main loop of an application or game to check for connected controllers.
	/// </summary>
	void UpdateInputManager()
	{
		int numactive;
		// Check all Joystick ports for active joysticks as the system doesn't support reconnecting more than 1 disconnected controller at a time we can break
		// if we find two inactive controllers in a row. This might negate the need for connect and disconnect methods because we know what controllers are connected and can therefore
		// act only on controllers that are active.
		for (numactive = GLFW_JOYSTICK_1; numactive < GLFW_JOYSTICK_LAST; numactive++)
		{
			ActiveControllers[numactive] = glfwJoystickPresent(numactive);
			if (glfwJoystickPresent(numactive) == 0 && glfwJoystickPresent(numactive + 1 == 0)) break;
		}

		//Copy Buttons to ButtonsLastUpdate


		for (int i = 0; i < numactive; i++)
		{

			if (ActiveControllers[i]) // catch disconnected controllers.
			{
				for (int j = 0; j < NumButtons[i]; j++)
				{
					ButtonsLastUpdate[i][j] = Buttons[i][j]; //get the button state from the last call.
				}
				//update the buttons and axes.
				ControllerAxes[i] = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &NumAxes[i]);
				Buttons[i] = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &NumButtons[i]);



				for (int j = 0; j < NumButtons[i]; j++)
				{
					if (ActivePressButtons[i][j] && (Buttons[i][j] == GLFW_PRESS) && (ButtonsLastUpdate[i][j] != GLFW_PRESS)) ButtonPressFuncs[i][j]; // if button press is active and button is pressed do button press function
					else if (ActiveReleaseButtons[i][j] && ButtonsLastUpdate[i][j] == GLFW_PRESS) ButtonReleaseFuncs[i][j]; // else button must not be pressed so if button release is active and press was true last update...
				}

				for (int j = 0; j < NumAxes[i]; j++)
				{
					if (ActiveAxes[i][j]) AxesFuncs[i][j]; // do active axes functions
				}
			}
		}
	}

	/// <summary>
	/// Creates an IMgui window displaying the states of all the input units on a controller based on the joystick/controller ID passed in.
	/// </summary>
	/// <param name="jid"></param>
	void SpawnControllerAnalysisWindow(int jid);
};
/* Plan2
*/


/* Plan1
class InputManager
{
private:
	// list of InputDevice Instances and corresponding objects
	// method that creates a thread that infinitely loops to check inputs from the active devices
	// and launches events based on those inputs it also checks if the controller is still connected
	// method to trigger events based on inputs

};

class InputDevice
{
// unique controller descriptor
// port/connector ID??? maybe instance ID???
// Indication of active status for disconnecting
// 6 Axes for toggles and trigers
// 14 buttons and their States D-pad, upper triggers, XYAB, start, menu, toggle buttons
};

// TODO: This is an example of a library function
void fnMultiControllerIinputLibrary()
{

}

InputDevice ConnectDevice()
{
	// check for the existence of an InputDevice that isn't already connected
	// check there is an existing instance of InputDevice with the same ID as the controller if so assign it to that
	// else if an inactive InputDevice exists overwrite it else create a new instance
	// Map InputDevice inputs to an instance of InputDevice
	// Return the instance to the manager
}

void DisConnectDevice(InputDevice disconDevice)
{
	// set disconDevice as inactive
}



*/
