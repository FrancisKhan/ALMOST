#ifndef XSKIND_H
#define XSKIND_H

#include <iostream>

enum class XSKind {NTOT0, NELAS, NINEL, N2N, N3N, NNP, NG, NP, ND, NT, NA, SCAT00};

inline std::ostream& operator << (std::ostream& stm, XSKind geom)
{
    switch(geom)
    {
        case XSKind::NTOT0  : return stm << "NTOT0";
        case XSKind::NELAS  : return stm << "NELAS";
        case XSKind::NINEL  : return stm << "NINEL";
        case XSKind::N2N    : return stm << "N2N";
        case XSKind::N3N    : return stm << "N3N";
        case XSKind::NNP    : return stm << "NNP";
        case XSKind::NG     : return stm << "NG";
        case XSKind::NP     : return stm << "NP";
        case XSKind::ND     : return stm << "ND";
        case XSKind::NT     : return stm << "NT";
        case XSKind::NA     : return stm << "NA";
        case XSKind::SCAT00 : return stm << "SCAT00";
        default : return stm << "XSKind{" << int(geom) << "}"; 
    }
}

inline std::string get_name(XSKind solver) 
{
  switch (solver) 
  {
    case XSKind::NTOT0  : return std::string("NTOT0");
    case XSKind::NELAS  : return std::string("NELAS");
    case XSKind::NINEL  : return std::string("NINEL");
    case XSKind::N2N    : return std::string("N2N");
    case XSKind::N3N    : return std::string("N3N");
    case XSKind::NNP    : return std::string("NNP");
    case XSKind::NG     : return std::string("NG");
    case XSKind::NP     : return std::string("NP");
    case XSKind::ND     : return std::string("ND");
    case XSKind::NT     : return std::string("NT");
    case XSKind::NA     : return std::string("NA");
    case XSKind::SCAT00 : return std::string("SCAT00");
    default : return std::string("");
  }
}

inline XSKind operator++(XSKind& x) 
{ 
    return x = (XSKind)(((int)(x) + 1)); 
}

inline XSKind operator*(XSKind c) 
{
    return c;
}

inline XSKind begin(XSKind r) 
{
    return XSKind::NTOT0;
}

inline XSKind end(XSKind r)   
{
    return XSKind(int(XSKind::SCAT00) + 1);
}

#endif