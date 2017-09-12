/* ----------------------------------------------------------------------------
	Using CRT library to detect memory leaks
	https://msdn.microsoft.com/en-us/library/x98tx3cf.aspx
---------------------------------------------------------------------------- */
#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <windows.h>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <chrono>



#include "FSM.h"
#include "State.h"
#include "ZState.h"
#include "XState.h"
#include "YState.h"


using namespace BlendTree;
using namespace std;



#if false

// an experiment
#define REGISTER_ENUM(x)	x,
typedef enum
{
	#include "Names.h"
	MSG_NUM
} MSG_Name;
#undef REGISTER_ENUM


#define REGISTER_ENUM(x)	#x,
static const char* MsgNameText[] =
{
	#include "Names.h"
	"Invalid"
};
#undef REGISTER_ENUM

#endif


//using a fixed timestep of 1 / (60fps) = 16 milliseconds
constexpr std::chrono::nanoseconds timeStep(16ms);

int main(int argc, char* argv[])
{
	// setup the timer, this should be moved to timer class
	using clock = std::chrono::high_resolution_clock;
	std::chrono::nanoseconds lag(0ns);


	bool bQuit = true;

#if _DEBUG
	// memory leak detection ...
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	_crtBreakAlloc = 145;
#endif

	// UTF8 Unicode console
	SetConsoleOutputCP(CP_UTF8);



//	std::cout << MsgNameText[MSG_PlayerSighted] << std::endl;

	{
		FSM* fsm = new FSM();
		if (fsm != NULL)
		{
			XState* pX = new XState(1, "NodeX");
			YState* pY = new YState(2, "NodeY");
			ZState* pZ = new ZState(3, "NodeZ");

			fsm->AddState(pX);
			fsm->AddState(pY);
			fsm->AddState(pZ);
		}


		auto now = clock::now();
		auto timeStart = now;



		// do this timer thing that can simulate a clock for the animation
		// update feature ...
		while (bQuit == false)
		{
			now = clock::now();
			auto deltaTime = now - timeStart;
			timeStart = now;

			lag += std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime);


			while (lag >= timeStep)
			{
				lag -= timeStep;

				std::cout << "update" << std::endl;
			}
		}

		delete fsm;
	}






	// dump the memory core
	_CrtDumpMemoryLeaks();
	return 1;
}