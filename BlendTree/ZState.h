#pragma once
#include "State.h"
#include <string>

using namespace BlendTree;


class ZState :
	public State
{
public:
	ZState();
	ZState(UniqueID id, std::string name);
	~ZState();

	void virtual Enter(void* params);
	void virtual Execute(void* params);
	void virtual Exit(void* params);

};

