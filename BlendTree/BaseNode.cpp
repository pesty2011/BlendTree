#include "BaseNode.h"

namespace BlendTree
{
	BaseNode::BaseNode() :
		m_strName("Undefined"),
		m_nID(STATEID_UNKNOWN)
	{
	}

	BaseNode::BaseNode(UniqueID id) :
		m_strName("Undefined"),
		m_nID(id)
	{
	}


	BaseNode::BaseNode(UniqueID id, std::string name) :
		m_strName(name),
		m_nID(id)
	{
	}


	BaseNode::~BaseNode()
	{
	}
}

