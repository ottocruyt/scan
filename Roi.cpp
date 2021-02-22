#include "Roi.h"
 Roi::Roi(Dim dimX, Dim dimY, Dim dimZ)
{
	m_dimX = dimX;
	m_dimY = dimY;
	m_dimZ = dimZ;
}
 Roi::~Roi()
{
}

std::string Roi::toString()
{
	std::string myString = "ROI:\n" 
													+ m_dimX.toString() + "\n"
													+ m_dimY.toString() + "\n"
													+ m_dimZ.toString() + "\n";
	return  myString;
}