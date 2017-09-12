#pragma once
#include "BaseNode.h"


namespace BlendTree
{
	class ClipNode :
		public BaseNode
	{
		UniqueID		m_nClipID;					// animation clip ID
		std::string		m_strClipName;				// name of the animation clip
		BlendFlag		m_nFlags;					// what are the unique flags for this clip


	public:
		ClipNode();
		~ClipNode();
	};

}
