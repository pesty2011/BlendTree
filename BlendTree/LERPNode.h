#pragma once
#include "BaseNode.h"
#include <string>
#include <vector>

namespace BlendTree
{
	class LERPNode :
		public BaseNode
	{
	protected:
		BlendFlag				m_nFlags;
		std::vector<BaseNode*>	m_BaseNodes;

	public:
		LERPNode();
		~LERPNode();
	};

}

