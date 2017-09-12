#include "FSM.h"
#include <iostream>

namespace BlendTree
{
	FSM::FSM() :
		m_nInitialState(STATEID_UNKNOWN),
		m_nCurrentState(STATEID_UNKNOWN),
		m_pCurrentState(NULL),
		m_pOwner(NULL)
	{
	}



	FSM::~FSM()
	{
		// loop through the map and free all of the states ...
		for (StatesItr it = m_States.begin(); it != m_States.end(); ++it)
		{
			State* state = it->second;
			delete state;
			it->second = NULL;
		}
		m_States.clear();
	}



	void FSM::Update()
	{
		if (m_pCurrentState != NULL)
		{
			m_pCurrentState->Execute(m_pOwner);
		}
	}



	bool FSM::StateExists(State* state)
	{
		bool bRet = false;

		if (state != NULL)
		{
			bRet = StateExists(state->GetID());
		}
		return bRet;
	}



	bool FSM::StateExists(UniqueID id)
	{
		StatesItr it;
		it = m_States.find(id);

		return it == m_States.end() ? false : true;
	}



	int FSM::AddState(State* state)
	{
		int nStatus = 0;

		if (state != NULL)
		{
			UniqueID id = state->GetID();
			std::string name = state->GetString();


			// check if the state machine is empty
			bool defaultState = m_States.empty();



			if (StateExists(state) == false)
			{
				UniqueID id = state->GetID();

				StatesPair pair = std::make_pair(id, state);
				m_States.insert(pair);


				// if state machine is empty, make this 
				// the default entry state.
				if (defaultState == true)
				{
					m_nInitialState = id;
					m_nCurrentState = id;
					m_pCurrentState = state;
				}

				nStatus = 1;
			}
		}
		return nStatus;
	}



	bool FSM::DelState(State* state)
	{
		bool bRet = false;

		if (StateExists(state))
		{
			m_States.erase(state->GetID());
			bRet = true;
		}
		return bRet;
	}



	bool FSM::ChangeState(UniqueID id)
	{
		bool bRet = false;
		if (id != STATEID_UNKNOWN && m_nCurrentState != id && m_pCurrentState->GetID() != id)
		{
			State* state = m_States.at(id);
			if (state != NULL)
			{
				m_pCurrentState->Exit(m_pOwner);
				m_pCurrentState = state;
				m_nCurrentState = id;
				m_pCurrentState->Enter(m_pOwner);
				bRet = true;
			}
#if _DEBUG
			else
			{
				std::wcout << "[FSM ERROR] stateID not found: " << std::to_wstring(id) << std::endl;
			}
#endif
		}
		return bRet;
	}
}


