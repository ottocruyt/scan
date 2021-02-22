#include "Dim.h"

Dim::Dim()
{
	m_p1 = 0;
	m_p2 = 0;
}

Dim::Dim(int p1, int p2)
{
	m_p1 = p1;
	m_p2 = p2;
}

Dim::~Dim()
{
}

std::string Dim::toString()
{
	char buff[100];
  snprintf(buff, sizeof(buff), "%4d --> %4d",m_p1,m_p2);
  std::string myString = buff;
	return  myString;
}

