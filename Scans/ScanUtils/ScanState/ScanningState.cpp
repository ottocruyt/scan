
#include "ScanningState.h"
#include "..\Scan.h"

ScanningState::ScanningState()
{
  m_name = std::string("Scanning State");
}

ScanningState::~ScanningState()
{
  
}

void ScanningState::start()
{
  std::ostringstream oss;
  oss << m_name << " handles start.\n";
  oss << " at " << ms << " ms.\n";
  std::cout << oss.str();
}



void ScanningState::stop()
{
  std::ostringstream oss;
  oss << m_name << " handles stop.\n";
  oss << " at " << ms << " ms.\n";
  std::cout << oss.str();
  this->m_scan->transitionTo(new IdleScanState);
}