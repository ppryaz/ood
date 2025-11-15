#pragma once

#include <limits>

class Statictics  {
public:
	void Update(double value) {
		if (value > m_max) m_max = value;
		if (value < m_min) m_min = value;
		m_acc += value;
		m_count++;
	}

	double GetMax() { return m_max; }
	double GetMin() { return m_min; }
	double GetAverage() { return (m_count != 0) ? m_acc / m_count : 0; }
private:
	double m_min		= std::numeric_limits<double>::infinity();
	double m_max		= -std::numeric_limits<double>::infinity();
	double m_acc		= 0;
	uint32_t m_count	= 0;
};