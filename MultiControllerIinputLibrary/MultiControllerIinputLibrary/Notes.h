/// Notes
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






















/// FINN NOTEPAD STUFF


Joystick Getting a normalised Vec2 from joysticks, rather than axis shite.

Get GLFW, read docs on how gamepads work, get multiple controllers

hookup IMGUI, and just poll the gamepad state and debug display it.


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







*/