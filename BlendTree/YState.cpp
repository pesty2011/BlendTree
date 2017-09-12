#include "YState.h"
#include <iostream>


YState::YState()
{
}

YState::YState(UniqueID id, std::string name) :
	State(id, name)
{
}

YState::~YState()
{
}


void YState::Enter(void* params)
{
	std::cout << "[ASTATE] Enter" << std::endl;
}


void YState::Execute(void* params)
{
	std::cout << "[ASTATE] Execute" << std::endl;
}


void YState::Exit(void* params)
{
	std::cout << "[ASTATE] Exit" << std::endl;
}

