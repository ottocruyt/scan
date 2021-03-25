#ifndef SCANSTATE_H
#define SCANSTATE_H
// interface for context - specific scans communication
#include <string>

class Scan;
class ScanState
{
	private:	
	protected:
		std::string m_name;
		Scan* m_scan;
	public:
		ScanState();
		virtual ~ScanState(){};
		void set_context(Scan* scan);
		virtual void start() = 0;
		virtual void stop() = 0;
		std::string name();
};

#endif