/// Notes

//Last updated 6/06/2023
/*
/// TODO
0. Link the required libraries (GLFW) (COMPLETE)
1. Detect the existence of a controller.
2. Assign it to an instance.
3. Get the controller's output and give it to the instance.
4. Detect that a controller has disconnected.
5. Detect that a disconnected controller has reconnected.
6. Create functions that allow controller instance data to be used as events.
7. Create Unique packages/classes for connected controllers based on either the controller's descriptor or the types of input it gives.
8. Create Debugging logic.
9. Create a demo project.

///Completed Tasks




///Stretch Goals




///Class List
class InputManager
class InputDevice
class Joystick


///Function List



///Further Notes





/// Code Investigation




Calling int glfwJoystickPresent	(int jid)	
only showed me that glfw knows about a joystick being plugged in but
it's jid only persists for as long as the application is runing
also the controllers have a light that shows?
if they are 1,2,3 or 4 but where the heck is that info coming from
you can also disconnect the first controller and then reconnect it and
it will go back to being the first controller both in jid and with the light?
pulling out both controllers at the same time causes them to lose their order
so it's not possible to reconnect a controller if more than one is unplugged at a time
unless I can find a way to get at it's device ID and the sourcecode to reassign
whatever the lights on the controllers are referencing.




const float * glfwGetJoystickAxes(int jid, int * count)
I've found that triggers start at -1 and go up to one the more they are indented
whereas toggles start at 0 and go from 1 to -1 with the Y positive of the toggle being towards the player and the x positive being to the right
the toggles are also unable to reach -1 Y I believe this is from damage or use but cannot be certain.



const unsigned char * glfwGetJoystickButtons(int jid, int * count)
Instead of returning a bool for some reason buttons return either a null terminator character which causes strings to stop
or an unknown character that gets interpreted as a question mark. I solved this by querying GLFW_PRESS which is GLFW's internal
value of a pressed button and then outputting a 1 or 0






/// Discarded code that holds value for possible future implementations

/*
* 
//bool thisIsACheckboxVal = true;

	// Strings to hold Joystick Test data Need to add a summary to explain naming conventions later
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

	int Joystick2AxesCount;
	std::stringstream joystick2AxisCount; std::string Joystick2AxisCount;
	std::stringstream joystick2Axis0; std::string Joystick2Axis0;
	std::stringstream joystick2Axis1; std::string Joystick2Axis1;
	std::stringstream joystick2Axis2; std::string Joystick2Axis2;
	std::stringstream joystick2Axis3; std::string Joystick2Axis3;
	std::stringstream joystick2Axis4; std::string Joystick2Axis4;
	std::stringstream joystick2Axis5; std::string Joystick2Axis5;
	int Joystick2ButtonCount;
	std::stringstream joystick2ButtonsCount; std::string Joystick2ButtonsCount;
	std::stringstream joystick2AXYBButtons; std::string Joystick2AXYBButtons;
	std::stringstream joystick2TriggerandMenuButtons; std::string Joystick2TriggerandMenuButtons;
	std::stringstream joystick2ToggleButtons; std::string Joystick2ToggleButtons;
	std::stringstream joystick2DPADButtons; std::string Joystick2DPADButtons;






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
			<< ") Start" << (Joystick1ButtonArrayptr[7] == GLFW_PRESS ? '1' : '0') /* << ") XBox Button" << (Joystick1ButtonArrayptr[14] == GLFW_PRESS ? '1' : '0') << ")";
			Joystick1TriggerandMenuButtons = joystick1TriggerandMenuButtons.str();
			joystick1ToggleButtons << "(Left Toggle" << (Joystick1ButtonArrayptr[8] == GLFW_PRESS ? '1' : '0') << ") Right Toggle" << (Joystick1ButtonArrayptr[9] == GLFW_PRESS ? '1' : '0');
			Joystick1ToggleButtons = joystick1ToggleButtons.str();
			joystick1DPADButtons << "(Dpad Up" << (Joystick1ButtonArrayptr[10] == GLFW_PRESS ? '1' : '0') << ") Dpad Right" << (Joystick1ButtonArrayptr[11] == GLFW_PRESS ? '1' : '0')
				<< ") (Dpad Down" << (Joystick1ButtonArrayptr[12] == GLFW_PRESS ? '1' : '0') << ") Dpad Left" << (Joystick1ButtonArrayptr[13] == GLFW_PRESS ? '1' : '0') << ")";
			Joystick1DPADButtons = joystick1DPADButtons.str();
			// I tried to figure out how to create an array of std::string but there's no point if the only way I can do it is through pointers.
			// so instead I'll add several outputs to individual strings

	}
	else if (glfwJoystickPresent(GLFW_JOYSTICK_2) == 1)
	{
	joystick1AxisCount << "Joystick1 Not Connected "; Joystick1AxisCount = joystick1AxisCount.str();
	}
	else
	{
	joystick1AxisCount << "No Joysticks Connected "; Joystick1AxisCount = joystick1AxisCount.str();
	}

	if (glfwJoystickPresent(GLFW_JOYSTICK_2) == 1)
	{
		const float* Joystick2Arrayptr = glfwGetJoystickAxes(GLFW_JOYSTICK_2, &Joystick2AxesCount);
		joystick2AxisCount << "Joystick2 Axes " << Joystick2AxesCount; Joystick2AxisCount = joystick2AxisCount.str();
		joystick2Axis1 << "Left toggle X  " << round(Joystick2Arrayptr[0] * 100) / 100; Joystick2Axis1 = joystick2Axis1.str();
		joystick2Axis2 << "Left toggle Y  " << round(Joystick2Arrayptr[1] * 100) / 100; Joystick2Axis2 = joystick2Axis2.str();
		joystick2Axis0 << "Right toggle X " << round(Joystick2Arrayptr[2] * 100) / 100; Joystick2Axis0 = joystick2Axis0.str();
		joystick2Axis3 << "Right toggle Y " << round(Joystick2Arrayptr[3] * 100) / 100; Joystick2Axis3 = joystick2Axis3.str();
		joystick2Axis4 << "Left trigger   " << round(Joystick2Arrayptr[4] * 100) / 100; Joystick2Axis4 = joystick2Axis4.str();
		joystick2Axis5 << "Right trigger  " << round(Joystick2Arrayptr[5] * 100) / 100; Joystick2Axis5 = joystick2Axis5.str();
		const unsigned char* Joystick2ButtonArrayptr = glfwGetJoystickButtons(GLFW_JOYSTICK_2, &Joystick2ButtonCount);
		joystick2ButtonsCount << "Controller 2 button count " << Joystick2ButtonCount; Joystick2ButtonsCount = joystick2ButtonsCount.str();
		joystick2AXYBButtons << "(A" << (Joystick2ButtonArrayptr[0] == GLFW_PRESS ? '1' : '0') << ") (B" << (Joystick2ButtonArrayptr[1] == GLFW_PRESS ? '1' : '0')
			<< ") (X" << (Joystick2ButtonArrayptr[2] == GLFW_PRESS ? '1' : '0') << ") (Y" << (Joystick2ButtonArrayptr[3] == GLFW_PRESS ? '1' : '0') << ")";
		Joystick2AXYBButtons = joystick2AXYBButtons.str();
		joystick2TriggerandMenuButtons << "(LB" << (Joystick2ButtonArrayptr[4] == GLFW_PRESS ? '1' : '0') << ") (RB"
			<< (Joystick2ButtonArrayptr[5] == GLFW_PRESS ? '1' : '0') << ") (Back" << (Joystick2ButtonArrayptr[6] == GLFW_PRESS ? '1' : '0')
			<< ") Start" << (Joystick2ButtonArrayptr[7] == GLFW_PRESS ? '1' : '0') /* << ") XBox Button" << (Joystick2ButtonArrayptr[14] == GLFW_PRESS ? '1' : '0') << ")";
		Joystick2TriggerandMenuButtons = joystick2TriggerandMenuButtons.str();
		joystick2ToggleButtons << "(Left Toggle" << (Joystick2ButtonArrayptr[8] == GLFW_PRESS ? '1' : '0') << ") Right Toggle" << (Joystick2ButtonArrayptr[9] == GLFW_PRESS ? '1' : '0');
		Joystick2ToggleButtons = joystick2ToggleButtons.str();
		joystick2DPADButtons << "(Dpad Up" << (Joystick2ButtonArrayptr[10] == GLFW_PRESS ? '1' : '0') << ") Dpad Right" << (Joystick2ButtonArrayptr[11] == GLFW_PRESS ? '1' : '0')
			<< ") (Dpad Down" << (Joystick2ButtonArrayptr[12] == GLFW_PRESS ? '1' : '0') << ") Dpad Left" << (Joystick2ButtonArrayptr[13] == GLFW_PRESS ? '1' : '0') << ")";
		Joystick2DPADButtons = joystick2DPADButtons.str();
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

	ImGui::NewLine();

	ImGui::Text(Joystick2AxisCount.c_str());
	ImGui::Text(Joystick2Axis0.c_str());
	ImGui::Text(Joystick2Axis1.c_str());
	ImGui::Text(Joystick2Axis2.c_str());
	ImGui::Text(Joystick2Axis3.c_str());
	ImGui::Text(Joystick2Axis4.c_str());
	ImGui::Text(Joystick2Axis5.c_str());
	ImGui::Text(Joystick2ButtonsCount.c_str());
	ImGui::Text(Joystick2AXYBButtons.c_str());
	ImGui::Text(Joystick2TriggerandMenuButtons.c_str());
	ImGui::Text(Joystick2ToggleButtons.c_str());
	ImGui::Text(Joystick2DPADButtons.c_str());
	//if (ImGui::Button("Hello")){}

	//ImGui::Checkbox("Booya", &thisIsACheckboxVal);

	ImGui::End();



	//ImGui::ShowDemoWindow();

















/// FINN NOTEPAD STUFF
////////////////////////////////////


Joystick Getting a normalised Vec2 from joysticks, rather than axis shite.

Get GLFW, read docs on how gamepads work, get multiple controllers

hookup IMGUI, and just poll the gamepad state and debug display it.


//////////////////////////////////////////////////////

int main()
{

	InputManager manager;

	manager.AddPlayerConnectCallback(


	manager.AddAction(Button::primaryAction, Shoot);

}


void OnNewPlayer(int playerNumber)
{
	//Spawn a player object or whatever
}


void Shoot(int playerNumber)
{
	someGlobalPlayerArray[playerNumber].FireWeapon();

}


void Jump(int playerNumber)
{


}





////////////////////////////////



class Player
{

	public:

	Vector2 velocity;
	Vector2 position;


	void OnJump()
	{
		velocity.y = 5;

	}



};


void DisplayMenu()
{

}


MultiControllerInputLibrary lib;

Player player;

lib.SetButtonPressCallback(0, 3, [&player](){player.OnJump();});
lib.SetButtonPressCallback(0, 5, DisplayMenu);

////////////////////////////////////////////////////////////////




*/