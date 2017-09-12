#pragma once
#include <chrono>


template <typename Period>
class HPTimer
{
public:
	HPTimer();
	Period GetElapsedTime() const;
	Period Restart();
	Period Now();

private:
	std::chrono::time_point<std::chrono::high_resolution_clock>	m_TimePoint;
};

template<typename Period>
HPTimer<Period>::HPTimer()
	: m_TimePoint(std::chrono::high_resolution_clock::now()) 
{
}


template<typename Period>
Period HPTimer<Period>::GetElapsedTime() const 
{
	const Period elapsedTime = std::chrono::high_resolution_clock::now() - m_TimePoint;
	return elapsedTime;
}


template<typename Period>
Period HPTimer<Period>::Now()
{
	auto ns = chrono::high_resolution_clock::now();
	long lastTime = ns.time_since_epoch;
	double nsPerTick = 1000000000 / 60.0f;

	return currTime;
}


template<typename Period>
Period HPTimer<Period>::Restart()
{
	const Period period = GetElapsedTime();
	m_TimePoint = std::chrono::high_resolution_clock::now();

	return period;
}
