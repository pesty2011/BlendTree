#pragma once
#include "State.h"
#include <string>

using namespace BlendTree;

class XState :
	public State
{
public:
	XState();
	XState(UniqueID id, std::string name);
	~XState();

	void virtual Enter(void* params);
	void virtual Execute(void* params);
	void virtual Exit(void* params);
};

