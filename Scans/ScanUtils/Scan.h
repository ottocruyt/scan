#ifndef SCAN_H
#define SCAN_H

#include <string>
#include <sstream>
#include <iostream>

#include "..\..\Globals.h"
#include "Filter.h"
#include "Roi.h"
#include "Averaging.h"
#include "CanCom.h"

class ScanState;
class IdleScanState;

class Scan
{
private:
	ScanState *m_scanState;
	static size_t nrOfScans;
	int m_id;
	Filter m_filter;
	Averaging m_averaging;
	CanCom *m_canCom;
	Scan(const Scan&); // copy constructor
	void operator = (const Scan&); // assignment operator

protected:
	Roi m_roi;
	enum Type
	{
		unknown,
		pocket,
		upright,
		horizontalBeam,
		freespace,
		boundary,
		types
	} m_type;

	std::string typeString[types] = {
			std::string("UNKNOWN"),
			std::string("Pocket"),
			std::string("Upright"),
			std::string("Horizontal Beam"),
			std::string("Freespace"),
			std::string("Boundary"),
	};
	void printDefinition();

public:
	Scan(Roi roi, Filter filter, Averaging averaging, ScanState *m_state, CanCom *p_canCom = nullptr);
	~Scan();
	std::string toString(DETAIL detail = DETAIL::LOW);
	Roi *getRoi();
	void start();
	void stop();
	void setCom(CanCom *canCom);
	Subject *getComSubcriber();
	std::string getTypeStr();
	void transitionTo(ScanState *state);
	Scan::Type getType();
	void transmitSetup();
};

#endif