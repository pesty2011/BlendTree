#pragma once
#include <string>

#include "DataTypes.h"

namespace BlendTree
{
	class BaseNode
	{
	public:
		UniqueID m_nID;									// UniqueID of the node
		std::string	m_strName;							// name of the node

	public:
		BaseNode();
		BaseNode(UniqueID id);
		BaseNode(UniqueID id, std::string name);
		~BaseNode();

		UniqueID GetID() { return m_nID; }
		void SetID(UniqueID id) { m_nID = id; }
		std::string GetString() { return m_strName; }
		void SetString(std::string name) { m_strName = name; }
	};
}

