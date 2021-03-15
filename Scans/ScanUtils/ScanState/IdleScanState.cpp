
#include "IdleScanState.h"
#include "..\Scan.h"

IdleScanState::IdleScanState()
{
  m_name = std::string("Idle State");
}

IdleScanState::~IdleScanState()
{
  
}

void IdleScanState::start()
{
  std::ostringstream oss;
  oss << "IdleState handles start.\n";
  oss << " at " << ms << " ms.\n";
  std::cout << oss.str();
  this->m_scan->transitionTo(new SettingUpScanState);
  this->m_scan->start(); // call start again in new setting up state state.
}

void IdleScanState::stop()
{
  std::ostringstream oss;
  oss << "IdleState handles stop.\n";
  oss << " at " << ms << " ms.\n";
  std::cout << oss.str();
}