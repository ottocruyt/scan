#ifndef CANCOM_H
#define CANCOM_H

#include <sstream>
#include <iostream>
#include "../../Globals.h"
#include "./Subscriptions/Subscriptions.cpp"

class CanCom
{
private:
	int m_node;
	int m_startSendingTime;
	int m_currentBits;
	bool m_sending;
	bool m_confirmation;
public:
	Subject *m_subject;
	CanCom(int node = 0);
	~CanCom();
	std::string toString(DETAIL detail = DETAIL::LOW);
	bool *send(int bits);
	bool ready();
	void update();
};
#endif