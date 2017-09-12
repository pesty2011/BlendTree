#pragma once
#include <vector>
#include <map>

#include "State.h"




namespace BlendTree
{
	class FSM
	{
	protected:
		typedef std::map<UniqueID, State*> StatesMap;
		typedef StatesMap::iterator StatesItr;
		typedef std::pair<UniqueID, State*> StatesPair;

		StatesMap	m_States;
		UniqueID		m_nInitialState;
		UniqueID		m_nCurrentState;
		State*		m_pCurrentState;

		bool		StateExists(State* state);
		bool		StateExists(UniqueID id);

		void*		m_pOwner;				// parameter passed to states
		
		bool		m_bDebug;
		bool		m_bLog;

	public:
		FSM();
		~FSM();

		void Update();

		int  AddState(State* state);
		bool DelState(State* state);

		bool ChangeState(UniqueID id);
	};
}
