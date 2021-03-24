#include "circuits/circuits.hh"
#include "grammar/driver/driver.hh"

extern std::vector<CTS::Edge> Edges_;

int main()
{
  yy::Driver driver;

  if (!driver.parse())
    return 1;

  CTS::Circuit crc{driver.get_inc(), driver.get_res(), driver.get_eds()};
  // crc.dump("large_norm.png", "norm.dot");

  try
  {
    crc.curs_calc();
    crc.curs_out();
  }
  catch (const MX::rank_lack &er)
  {
    std::cerr << "I CAN'T CALCULATE THIS CIRCUIT, SORRY :'(" << std::endl;
  }

  return 0;
}