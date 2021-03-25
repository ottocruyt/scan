#ifndef SETTINGUPSCANSTATE_H
#define SETTINGUPSCANSTATE_H

#include "..\..\..\Globals.h"
#include <sstream>
#include <iostream>
#include <string>
#include "ScanState.h"
#include "IdleScanState.h"
#include "ScanningState.h"

class Observer;
class SettingUpScanState : public ScanState {
 public:
    SettingUpScanState();
    ~SettingUpScanState();
    void start();
    void stop();
    void onComReady();
  private:
    Observer *m_ComObserver;
};

#endif