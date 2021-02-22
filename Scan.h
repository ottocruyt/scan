#ifndef SCAN_H
#define SCAN_H

#include "Roi.h"

class Scan
{
private:
	Roi m_roi;
public:
	Scan(Roi roi);
	~Scan();
};

#endif