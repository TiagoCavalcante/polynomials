#pragma once

#include "constants.hpp"

namespace math {
  inline bool isZero(double number) {
    return -epsilon < number && number < epsilon;
  }
}