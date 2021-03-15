#ifndef IDLESCANSTATE_H
#define IDLESCANSTATE_H

#include "..\..\..\Globals.h"
#include <sstream>
#include <iostream>
#include <string>
#include "ScanState.h"
#include "SettingUpScanState.h"


class IdleScanState : public ScanState {
 public:
  IdleScanState();
  ~IdleScanState();
  void start();
  void stop();
};

#endif