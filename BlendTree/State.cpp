#include "State.h"

namespace BlendTree
{
	State::State() :
		BaseNode()
	{
	}


	State::State(UniqueID id, std::string name) :
		BaseNode(id, name)
	{

	}


	State::State(UniqueID id) :
		BaseNode(id)
	{
	}


	State::~State()
	{
		BaseNode::~BaseNode();
	}


	bool State::TransitionExists(PARAM_TRANSITION_DEF tran)
	{
		bool bStatus = false;

		for (TransItr it = m_Transitions.begin(); it != m_Transitions.end(); ++it)
		{
			if (tran == *it)
			{
				bStatus = true;
				break;
			}
		}
		return bStatus;
	}



	bool State::AddTransition(PARAM_TRANSITION_DEF transition)
	{
		bool bStatus = false;

		if (TransitionExists(transition) == false)
		{
			m_Transitions.push_back(transition);
			bStatus = true;
		}

		return bStatus;
	}
}

