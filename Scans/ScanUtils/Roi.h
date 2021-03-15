#ifndef ROI_H
#define ROI_H

#include "Dim.h"
#include <sstream>

class Roi
{
private:
	Dim m_dimX;
	Dim m_dimY;
	Dim m_dimZ;
public:
	Roi(Dim dimX, Dim dimY, Dim dimZ);
	~Roi();
	std::string toString();

};
#endif