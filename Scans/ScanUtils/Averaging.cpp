#include "Averaging.h"

Averaging::Averaging(int frames, bool active):m_frames(frames),m_active(active)
{
	m_active = true;
	m_frames = frames;
}

Averaging::~Averaging()
{
}

std::string Averaging::toString(DETAIL detail)
{
	std::ostringstream oss;
	switch (detail)
	{
	case DETAIL::NONE:
		break;
	case DETAIL::LOW:
		if(m_active)
		{
			oss << "Averaging on." << std::endl;
		}
		break;
	case DETAIL::HIGH:
		oss << "Averaging: " << BoolToString(m_active) << std::endl;
		break;
	case DETAIL::FULL:
		oss << "Averaging: " << BoolToString(m_active) << std::endl;
		if(m_active)
		{
			oss << "  over " << m_frames << " frames" << std::endl;
		}
		break;
	}
	return oss.str();
}