#pragma once

#include <vector>

namespace linear {
  std::vector<double> getRoots(const std::vector<double>& polynomial) {
    return {-polynomial.back() / polynomial.front()};
  }
}