#ifndef POCKETSCAN_H
#define POCKETSCAN_H

#include ".\ScanUtils\Scan.h"


class PocketScan: public Scan
{
private:
public:
	PocketScan(Roi roi, Filter filter, Averaging averaging, ScanState* state);
	Type getType();
};

#endif