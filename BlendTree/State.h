#pragma once
#include <vector>

#include "BaseNode.h"
#include "Transition.h"

#define PARAM_TRANSITION_DEF		Transition*


namespace BlendTree
{
	class State : public BaseNode
	{
		typedef std::vector<PARAM_TRANSITION_DEF> TransVec;
		typedef TransVec::iterator TransItr;

	private:
		TransVec	m_Transitions;

	public:
		State();
		State(UniqueID id);
		State(UniqueID id, std::string name);
		~State();

		void virtual Enter(void* params) = 0;
		void virtual Execute(void* params) = 0;
		void virtual Exit(void* params) = 0;

		bool AddTransition(PARAM_TRANSITION_DEF tran);
		bool TransitionExists(PARAM_TRANSITION_DEF tran);

	};
}


