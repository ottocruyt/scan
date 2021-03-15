#include "CanCom.h"

CanCom::CanCom(int node):m_node(node)
{
	if(node)
	{
		std::cout << "Communication with node " << m_node << " initialized." << std::endl;
	}
	m_subject = new Subject;
}

CanCom::~CanCom()
{
	delete m_subject;
}

std::string CanCom::toString(DETAIL detail)
{
	std::ostringstream oss;
	switch (detail)
	{
	case DETAIL::NONE:
		break;
	case DETAIL::LOW:
		break;
	case DETAIL::HIGH:
		break;
	case DETAIL::FULL:
		break;
	}
	return oss.str();
}

bool* CanCom::send(int bits)
{
	m_sending = true;
	m_startSendingTime = ms;
	m_currentBits = bits;
	m_confirmation = false;
	std::cout << "Start sending " << m_currentBits << " to node " << m_node << "." << std::endl;
	return &m_confirmation;
}

bool CanCom::ready()
{
	return !m_sending;
}

void CanCom::update()
{
	if (m_node)
	{
		if (m_startSendingTime + 10 < ms)
		{
			if (m_sending)
			{
				std::cout << m_currentBits << " sent to node " << m_node << "." << std::endl;
				m_sending = false;
				m_confirmation = true;
				m_subject->CreateMessage(std::string("CanCom: Message sent. Done with comm."));
			}
		}
	}
}