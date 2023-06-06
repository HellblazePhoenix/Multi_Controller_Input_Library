#include "pch.h"
#include "MultiControllerInput.h"

void InputManager::SetButtonPressCallback(int controllerID, int button, std::function<void()> execFunc)
{
	ActivePressButtons[controllerID][button] = true; ButtonPressFuncs[controllerID][button] = execFunc;
}

void InputManager::SetButtonPressCallbackMultipleControllers(int controllerIDEnd, int button, std::function<void()> execFunc)
{
	for (int i = 0; i < controllerIDEnd; i++)
	{
		ActivePressButtons[i][button] = true; ButtonPressFuncs[i][button] = execFunc;
	}
}

void InputManager::SetButtonReleaseCallback(int controllerID, int button, std::function<void()> execFunc)
{
	ActiveReleaseButtons[controllerID][button] = true; ButtonReleaseFuncs[controllerID][button] = execFunc;
}

void InputManager::SetButtonReleaseCallbackMultipleControllers(int ControllerIDEnd, int button, std::function<void()> execFunc)
{
	for (int i = 0; i < ControllerIDEnd; i++)
	{
		ActiveReleaseButtons[i][button] = true; ButtonReleaseFuncs[i][button] = execFunc;
	}
}

void InputManager::SetAxisInputCallback(int controllerID, int axisID, std::function<void(float axisVal)> execFunc)
{
	ActiveAxes[controllerID][axisID] = true;  AxesFuncs[controllerID][axisID] = execFunc;
}

void InputManager::SetAxisInputCallbackMultipleControllers(int ControllerIDEnd, int axisID, std::function<void(float axisVal)> execFunc)
{
	for (int i = 0; i < ControllerIDEnd; i++)
	{
		ActiveAxes[i][axisID] = true;  AxesFuncs[i][axisID] = execFunc;
	}
}

void InputManager::UpdateInputManager()
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
			for (int j = 0; j < NumButtons[i]-1; j++)
			{
				ButtonsLastUpdate[i][j] = Buttons[i][j]; //get the button state from the last call out of buttons.
			}
			//update the buttons and axes.
			ControllerAxes[i] = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &NumAxes[i]);
			Buttons[i] = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &NumButtons[i]);



			for (int j = 0; j < NumButtons[i]; j++)
			{
				if (ActivePressButtons[i][j] && (Buttons[i][j] == GLFW_PRESS) && (ButtonsLastUpdate[i][j] != GLFW_PRESS)) ButtonPressFuncs[i][j]();
				// if button press is active and button is pressed do button press function once if it wasn't pressed last update.
				else if (ActiveReleaseButtons[i][j] && ButtonsLastUpdate[i][j] == GLFW_PRESS && Buttons[i][j] == GLFW_RELEASE) ButtonReleaseFuncs[i][j]();
				// otherwise if button not be pressed, button release is active and press was true last update...
			}

			for (int j = 0; j < NumAxes[i]; j++)
			{
				if (ActiveAxes[i][j]) AxesFuncs[i][j](ControllerAxes[i][j]); // do active axes functions
			}
		}
	}
}
