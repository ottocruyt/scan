#ifndef SCANNINGSTATE_H
#define SCANNINGSTATE_H

#include "..\..\..\Globals.h"
#include <sstream>
#include <iostream>
#include <string>
#include "ScanState.h"
#include "IdleScanState.h"
#include "../Subscriptions/Subscriptions.h"

class ScanningState : public ScanState {
 public:
    ScanningState();
    ~ScanningState();
    void start();
    void stop();
  private:
};

#endif