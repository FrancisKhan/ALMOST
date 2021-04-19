#ifndef XSMATRIXKIND_H
#define XSMATRIXKIND_H

#include <iostream>

enum class XSMatrixKind {SCATT00, SCATT01};

inline std::ostream& operator << (std::ostream& stm, XSMatrixKind xsKind)
{
    switch(xsKind)
    {
        case XSMatrixKind::SCATT00  : return stm << "SCATT00";
        case XSMatrixKind::SCATT01  : return stm << "SCATT01";
        default : return stm << "XSMatrixKind{" << int(xsKind) << "}"; 
    }
}

inline std::string get_name(XSMatrixKind xsKind) 
{
  switch (xsKind) 
  {
    case XSMatrixKind::SCATT00  : return std::string("SCATT00");
    case XSMatrixKind::SCATT01  : return std::string("SCATT01");
    default : return std::string("");
  }
}

inline XSMatrixKind operator++(XSMatrixKind& x) 
{ 
    return x = (XSMatrixKind)(((int)(x) + 1)); 
}

inline XSMatrixKind operator*(XSMatrixKind c) 
{
    return c;
}

inline XSMatrixKind begin(XSMatrixKind r) 
{
    return XSMatrixKind::SCATT00;
}

inline XSMatrixKind end(XSMatrixKind r)   
{
    return XSMatrixKind(int(XSMatrixKind::SCATT01) + 1);
}

#endif