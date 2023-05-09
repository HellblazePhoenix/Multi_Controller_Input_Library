#include <iostream>
#include <functional>


void PrintHello(int x, float y)
{
	std::cout << "Hello" << std::endl;
}


enum class FaceButton
{
	A,B,X,Y
};

class InputManager
{
	std::function<void(int)> functionToCallWhenAControllerGetsPluggedIn;


	//The int is the controller number where the button was pressed.
	std::function<void(int, FaceButton)> onButtonDown;
	std::function<void(int, FaceButton)> onButtonRelease;
	
};




int main()
{


	std::function<void(int, float)> thingToDo;

	thingToDo = PrintHello;


	thingToDo(3, 5);
}