#pragma once
#include "State.h"
#include <string>

using namespace BlendTree;

class YState :
	public State
{
public:
	YState();
	YState(UniqueID id, std::string name);
	~YState();

	void virtual Enter(void* params);
	void virtual Execute(void* params);
	void virtual Exit(void* params);

};

