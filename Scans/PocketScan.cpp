#include "PocketScan.h"

PocketScan::PocketScan(Roi roi, Filter filter, Averaging averaging, ScanState* state):Scan(roi, filter, averaging, state)
{
	m_type = Scan::pocket;
	printDefinition();
}

Scan::Type PocketScan::getType()
{
	return m_type;
}