
#include "..\Scan.h"
#include "ScanState.h"


void ScanState::set_context(Scan *scan) 
{
  this->m_scan = scan;
}

std::string ScanState::name()
{
  return m_name;
}
