#ifndef SETTINGUPSCANSTATE_H
#define SETTINGUPSCANSTATE_H

#include "..\..\..\Globals.h"
#include <sstream>
#include <iostream>
#include <string>
#include "ScanState.h"
#include "IdleScanState.h"
#include "..\Subscriptions\Subcriptions.h"

class SettingUpScanState : public ScanState {
 public:
    SettingUpScanState();
    ~SettingUpScanState();
    void start();
    void stop();
  private:
    Observer *m_observer;
};

#endif