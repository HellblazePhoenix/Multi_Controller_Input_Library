#include <iostream>
#include "ApplicationHarness.h"

//Include the necessary header file here for your game type
#include "InputManagerDemo.h"


int main()
{
	
	
	ApplicationHarness program(new InputManagerDemo());	//Create a new instance of your application type to pass into the harness here.

	program.Run();

	return 0;
}