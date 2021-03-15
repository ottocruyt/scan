#ifndef AVERAGING_H
#define AVERAGING_H

#include <sstream>
#include "../../Globals.h"


class Averaging
{
private:
	bool m_active;
	int m_frames;
public:
	Averaging(int frames = defaultAveragingFrames, bool active = false);
	~Averaging();
	std::string toString(DETAIL detail = DETAIL::LOW);
	void setFrames(int frames);
	void activate();
	void deactivate();
};
#endif