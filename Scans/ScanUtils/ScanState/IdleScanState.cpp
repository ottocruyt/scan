
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
  oss << m_name << " handles start.\n";
  oss << " at " << ms << " ms.\n";
  std::cout << oss.str();
  SettingUpScanState* newState = new SettingUpScanState();
  this->m_scan->transitionTo(newState);
  newState->start(); // call state on the new state to continue.
  // cant call start on this because this is not current any more!
}

void IdleScanState::stop()
{
  std::ostringstream oss;
  oss << m_name << " handles stop.\n";
  oss << " at " << ms << " ms.\n";
  std::cout << oss.str();
}