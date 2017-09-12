#include "XState.h"
#include <iostream>


XState::XState()
{
}


XState::XState(UniqueID id, std::string name) :
	State(id, name)
{
}

XState::~XState()
{
}



void XState::Enter(void* params)
{
	std::cout << "[XState] Enter" << std::endl;
}


void XState::Execute(void* params)
{
	std::cout << "[XState] Execute" << std::endl;
}


void XState::Exit(void* params)
{
	std::cout << "[XState] Exit" << std::endl;
}



