#ifndef UPRIGHTSCAN_H
#define UPRIGHTSCAN_H

#include ".\ScanUtils\Scan.h"


class UprightScan: public Scan
{
private:
public:
	UprightScan(Roi roi, Filter filter, Averaging averaging, ScanState* state);
	Type getType();
};

#endif