#include "Filter.h"

Filter::Filter()
{
	m_dimH = Dim();
	m_dimW = Dim();
	m_active = false;
}

Filter::Filter(Dim dimW, Dim dimH):m_dimW(dimW), m_dimH(dimH)
{
	m_dimW = dimW;
	m_dimH = dimH;
	m_active = true;
}

Filter::~Filter()
{
}

std::string Filter::toString(DETAIL detail)
{
	std::ostringstream oss;
	switch (detail)
	{
	case DETAIL::NONE:
		break;
	case DETAIL::LOW:
		if(m_active)
		{
			oss << "Object Filter active." << std::endl;
		}
		break;
	case DETAIL::HIGH:
		oss << "Object Filter active: " << BoolToString(m_active) << std::endl;
		break;
	case DETAIL::FULL:
		oss << "Object Filter active: " << BoolToString(m_active) << std::endl;
		if(m_active)
		{
			oss << "W: " << m_dimW.toString() << std::endl;
			oss << "H: " << m_dimH.toString() << std::endl;	
		}
		break;
	}
	return  oss.str();
}