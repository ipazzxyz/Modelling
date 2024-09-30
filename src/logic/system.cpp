#include "system.hpp"

System::System(int month_count, double capitalization, double tax,
               double spread)
    : month_count_(month_count),
      tax_(tax),
      fund_(capitalization),
      market_(spread) {}