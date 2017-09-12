#include "ClipNode.h"

#include <string>

namespace BlendTree
{
	ClipNode::ClipNode() :
		m_nClipID(0),
		m_strClipName("Unknown"),
		m_nFlags(0)
	{
	}


	ClipNode::~ClipNode()
	{
	}
}
