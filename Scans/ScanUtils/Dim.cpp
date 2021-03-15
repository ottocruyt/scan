#include "Dim.h"

Dim::Dim(int p1, int p2):m_p1(p1), m_p2(p2)
{
	m_p1 = p1;
	m_p2 = p2;
}

Dim::Dim()
{
	m_p1 = 0;
	m_p2 = 0;

}

Dim::~Dim()
{
}

std::string Dim::toString()
{
	std::ostringstream oss;
	oss << std::setfill(' ') << std::setw(4) << m_p1 << " --> " << m_p2;
	return  oss.str();
}

