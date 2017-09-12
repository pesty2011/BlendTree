#include "ZState.h"
#include <iostream>


ZState::ZState()
{
}

ZState::ZState(UniqueID id, std::string name) :
	State(id, name)
{
}


ZState::~ZState()
{
}


void ZState::Enter(void* params)
{
	std::cout << "[BState] Enter" << std::endl;
}


void ZState::Execute(void* params)
{
	std::cout << "[BState] Execute" << std::endl;
}


void ZState::Exit(void* params)
{
	std::cout << "[BState] Exit" << std::endl;
}

