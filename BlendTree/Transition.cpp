#include "Transition.h"



namespace BlendTree
{
	Transition::Transition()
	{
	}



	Transition::~Transition()
	{
	}

	bool Transition::Test(void* pParams)
	{

		bool bStatus = false;

		if (m_pCondition)
		{
			bStatus = m_pCondition->Test(pParams);
		}


/*
		for (ConditionItr it = m_Conditions.begin(); it != m_Conditions.end(); ++it)
		{
			Condition* cond = *it;
			if (cond->Test(pParams))
			{
				bStatus = true;
			}
		}
*/


		return bStatus;
	}
}
