#include "UprightScan.h"

UprightScan::UprightScan(Roi roi, Filter filter, Averaging averaging, ScanState* state):Scan(roi, filter, averaging, state)
{
	m_type = Scan::upright;
	printDefinition();
}

Scan::Type UprightScan::getType()
{
	return m_type;
}