#pragma once
#include <vector>

#include "DataTypes.h"
#include "Condition.h"

namespace BlendTree
{
	class Transition
	{
		Condition*		m_pCondition;

	public:
		Transition();
		~Transition();

		UniqueID	TransitionID;

		bool Test(void* pParams);
		void AddCondition(Condition* cond) { m_pCondition = cond; }
	};
}
