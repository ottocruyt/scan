
#include "SettingUpScanState.h"
#include "..\Scan.h"
#include "..\Subscriptions\Subscriptions.cpp"

SettingUpScanState::SettingUpScanState()
{
  m_name = std::string("Setting up State");
}

SettingUpScanState::~SettingUpScanState()
{
  
}

void SettingUpScanState::start()
{
  std::ostringstream oss;
  oss << "SettingUpState handles start.\n";
  oss << " at " << ms << " ms.\n";
  std::cout << oss.str();
  m_scan->transmitSetup();
  Observer *m_observer = new Observer(*(m_scan->getComSubcriber()));
}

void SettingUpScanState::stop()
{
  std::ostringstream oss;
  oss << "SettingUpState handles stop.\n";
  oss << " at " << ms << " ms.\n";
  std::cout << oss.str();
  this->m_scan->transitionTo(new IdleScanState);
}