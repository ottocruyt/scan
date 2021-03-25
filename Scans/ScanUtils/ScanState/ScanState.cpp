
#include "..\Scan.h"
#include "ScanState.h"

ScanState::ScanState()
{
  
}

void ScanState::set_context(Scan* scan) 
{
  this->m_scan = scan;
}

std::string ScanState::name()
{
  return m_name;
}
