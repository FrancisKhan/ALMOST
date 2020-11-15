#include "HeatCodeFactory.h"

std::shared_ptr<BaseHeatCode> HeatCodeFactory::setHeatCode(Reactor &reactor, Library &library)
{
  return std::make_shared<BaseHeatCode>(reactor, library);
}