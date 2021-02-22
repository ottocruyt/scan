#ifndef DIM_H
#define DIM_H
#include <string>
 
class Dim
{
private:
    int m_p1;
    int m_p2;
 
public:
    Dim();
    Dim(int p1, int p2);
	~Dim();
    std::string toString();
};
 
#endif