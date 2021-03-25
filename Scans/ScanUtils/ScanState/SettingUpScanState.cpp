
#include "SettingUpScanState.h"
#include "..\Scan.h"
#include "..\Subscriptions\Subscriptions.h"

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
  oss << m_name << " handles start.\n";
  oss << " at " << ms << " ms.\n";
  std::cout << oss.str();
  m_scan->transmitSetup();
  Observer *m_ComObserver = new Observer(*(m_scan->getComSubcriber()));
  m_ComObserver->setCallbackOnReady(this);
}

void SettingUpScanState::stop()
{
  std::ostringstream oss;
  oss << "SettingUpState handles stop.\n";
  oss << " at " << ms << " ms.\n";
  std::cout << oss.str();
  this->m_scan->transitionTo(new IdleScanState);
}

void SettingUpScanState::onComReady()
{
  ScanningState* newState = new ScanningState;
  this->m_scan->transitionTo(newState);
  newState->start();
}