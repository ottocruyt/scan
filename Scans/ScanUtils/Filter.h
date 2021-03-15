#ifndef FILTER_H
#define FILTER_H

#include "Dim.h"
#include <sstream>
#include "../../Globals.h"

class Filter
{
private:
	Dim m_dimW;
	Dim m_dimH;
	bool m_active;
public:
	Filter();
	Filter(Dim dimW, Dim dimH);
	~Filter();
	std::string toString(DETAIL detail = DETAIL::LOW);

};
#endif