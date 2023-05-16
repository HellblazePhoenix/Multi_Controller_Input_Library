// MultiControllerIinputLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"


enum class ButtonType
{
	AButton = 0,
	BButton = 1,

};

/// <summary>
/// An object that handles input from controllers.
/// </summary>
class InputManager
{
private:

std::vector<bool> ActiveJoysticks;
std::vector<float*> JoystickAxes;
std::vector<unsigned char*> Buttons;


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

void UpdateInputManager();
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
