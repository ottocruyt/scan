#include "Roi.h"

Roi::Roi(Dim dimX, Dim dimY, Dim dimZ):m_dimX(dimX), m_dimY(dimY), m_dimZ(dimZ)
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
	std::ostringstream oss;
	oss << "ROI:\n";
	oss << "X: " << m_dimX.toString() << "\n";
	oss << "Y: " << m_dimY.toString() << "\n";
	oss << "Z: " << m_dimZ.toString() << "\n";
	return  oss.str();
}