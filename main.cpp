#include <iostream>
#include <string>
#include "Dim.h"
#include "Roi.h"


using namespace std;

int main(int argc, char* argv[]){

	string strMytestString("Start of program\n");
  cout << strMytestString;
	int i = 0;
	while (i<10)
	{
		static Dim dimX(1000,2000);
		static Dim dimY(-500,500);
		static Dim dimZ(-20,150);
		static Roi roi(dimX,dimY,dimZ);
		static Scan myScan(roi);
		cout << roiInString;


		i++;
	}
	

	string strMytest2String("End of program\n");
  cout << strMytest2String;
  return 0;
}