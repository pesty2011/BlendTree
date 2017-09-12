#pragma once
namespace BlendTree
{
	class Condition
	{
	public:
		Condition();
		~Condition();

	public:
		virtual bool Test(void* pParam);
	};
}
