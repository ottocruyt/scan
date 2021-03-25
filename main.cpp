#include <iostream>
#include <string>
#include ".\Scans\ScanUtils\Dim.h"
#include ".\Scans\ScanUtils\Roi.h"
#include ".\Scans\ScanUtils\CanCom.h"
#include ".\Scans\ScanUtils\ScanState\IdleScanState.h"
#include ".\Scans\PocketScan.h"
#include ".\Scans\UprightScan.h"
#include "Globals.h"

using namespace std;

int main(int argc, char* argv[]){

	string strMytestString("Start of program\n");
  cout << strMytestString;


	while (ms<max_ms)
	{
		static Dim dimX(1000,2000);
		static Dim dimY(-500,500);
		static Dim dimZ(-20,150);
		static Dim dimW(200,400);
		static Dim dimH(100,200);
		static Filter filter(dimW,dimH);
		static Roi roi(dimX,dimY,dimZ);
		static Averaging averaging(49, true);
		static PocketScan myScan(roi, filter, averaging, new IdleScanState);
		static CanCom canCom(37);
		static CanCom* p_canCom = &canCom;
		//static UprightScan myScan2(roi, filter, averaging, new IdleScanState);
		if(ms == 0)
		{
			myScan.setCom(p_canCom);
		}
		canCom.update();
		
		if(ms==500)
		{
			myScan.start();
		}

		if(ms==8000)
		{
			myScan.stop();
		}



		ms++;
	}
	

	string strMytest2String("End of program\n");
  cout << strMytest2String;
  return 0;
}