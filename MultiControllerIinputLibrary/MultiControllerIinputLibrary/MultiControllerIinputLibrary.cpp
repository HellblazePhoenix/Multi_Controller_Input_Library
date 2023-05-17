// MultiControllerIinputLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

enum class XboxAxesID
{
	LeftToggleX  =  0,
	LeftToggleY  =  1,
	RightToggleX =  2,
	RightToggleY =  3,
	LeftTrigger  =  4,
	RightTrigger =  5
};

enum class XboxButtonID
{
	AButton     = 0,
	BButton     = 1,
	XButton     = 2,
	YButton     = 3,
	LBButton    = 4,
	RBButton    = 5,
	BackButton  = 6,
	StartButton = 7,
	LeftToggle  = 8,
	RightToggle = 9,
	DpadUp      = 10,
	DpadRight   = 11,
	DpadDown    = 12,
	DpadLeft    = 13,
};

/// <summary>
/// An object that handles input from controllers.
/// </summary>
class InputManager
{
private:

/// <summary>
/// A vector that keeps track of the active joystick IDs to prevent errors from occuring due to checking inactive IDs.
/// </summary>
std::vector<bool> ActiveJoysticks;
/// <summary>
/// A vector that holds the size/number of axes on each controller that has been connected.
/// </summary>
std::vector<int> NumAxes;
/// <summary>
/// A vector that holds pointers to the memory adresses of the axes on each controller.
/// </summary>
std::vector<float*> JoystickAxes;
/// <summary>
/// A vector that holds the size/number of buttons on each controller that has been connected.
/// </summary>
std::vector<int> NumButtons;
/// <summary>
/// A vector that holds pointers to the memory adresses of the buttons on each controller.
/// </summary>
std::vector<unsigned char*> Buttons;

/// <summary>
/// A possible constructor that in theory will run the update function on itself in a loop while the rest of the program is running.
/// </summary>
//InputManager();
/// <summary>
/// A destructor to explicitly delete the input manager should it be neccessary. 
/// </summary>
//~InputManager();


public:


/// <summary>
/// takes a joystick ID, a button ID and a function pointer then executes that function using the jid and bid.
/// </summary>
/// <param name="jid"></param>
/// <param name="bid"></param>
/// <param name="execFunc"></param>
void SetButtonPressCallback(int jid, int bid, std::function<void()> execFunc);	//Should execFunc take deltatime?
void SetButtonReleaseCallback(int jid, int bid, std::function<void()> execFunc);
void Button_Held(int jid, int bid, std::function<void()> execFunc);

/// <summary>
/// executes a function basd on the state of the trigger.
/// Triggers have an axis which gives a float value
/// </summary>
/// <param name="jid"></param>
/// <param name="aid"></param>
/// <param name="execFunc"></param>
void Trigger(int jid, int aid, std::function<void(float axisVal)> execFunc);

int ConnectInputDevice();
void DisconnectInputDevice(int jid);

/// <summary>
/// this should be called in the main loop of an application or game to check for connected controllers.
/// </summary>
void UpdateInputManager();

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
