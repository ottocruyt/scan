#include ".\ScanState\ScanState.h"
#include ".\ScanState\IdleScanState.h"

#include "Scan.h"

size_t Scan::nrOfScans = 0;

Scan::Scan(Roi roi, Filter filter, Averaging averaging, ScanState* scanState, CanCom *p_canCom) : m_roi(roi), m_filter(filter), m_averaging(averaging), m_canCom(p_canCom), m_scanState(nullptr)
{
	nrOfScans++; // count the active scans
	m_id = nrOfScans;
	m_type = Scan::unknown;
	this->transitionTo(scanState);
}

Scan::~Scan()
{
	nrOfScans--;
	delete m_scanState;
}

std::string Scan::toString(DETAIL detail)
{
	std::ostringstream oss;
	switch (detail)
	{
	case DETAIL::NONE:
		break;
	case DETAIL::LOW:
		oss << getTypeStr() << " Scan";
		break;
	case DETAIL::HIGH:
		oss << getTypeStr() << " Scan" << std::endl;
		oss << m_filter.toString(detail);
		oss << m_averaging.toString(detail);
		break;
	case DETAIL::FULL:
		oss << getTypeStr() << " Scan"
				<< " with id " << m_id << std::endl;
		oss << m_roi.toString();
		oss << m_filter.toString(detail);
		oss << m_averaging.toString(detail);
		break;
	}
	return oss.str();
}

Roi *Scan::getRoi()
{
	return &m_roi;
}

void Scan::start()
{
	std::ostringstream oss;
	oss << this->toString() << " start command. \n";
	std::cout << oss.str();

	this->m_scanState->start();
}

void Scan::stop()
{
	std::ostringstream oss;
	oss << this->toString() << " stop command. \n";
	std::cout << oss.str();

	m_scanState->stop();
}

Scan::Type Scan::getType()
{
	return m_type;
}


std::string Scan::getTypeStr()
{
	return typeString[(int)(this->getType())];
}

void Scan::printDefinition()
{
	std::cout << this->toString() << " defined at " << ms << " ms" << std::endl;
}

void Scan::setCom(CanCom *canCom)
{
	m_canCom = canCom;
}

void Scan::transitionTo(ScanState *state)
{
	std::ostringstream oss;
	oss << "Scan: Transition to " << state->name() << ".\n";
	std::cout << oss.str();
	if (this->m_scanState != nullptr)
	{
		delete this->m_scanState;
	}
	this->m_scanState = state;
	this->m_scanState->set_context(this);
}

void Scan::transmitSetup()
{
	m_canCom->send(101101); // random bits.
}


Subject* Scan::getComSubcriber()
{
	return m_canCom->m_subject;
}