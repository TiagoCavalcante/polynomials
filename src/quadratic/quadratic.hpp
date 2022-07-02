#pragma once

#include <cmath>
#include <vector>

namespace quadratic {
  std::vector<double> getRoots(const std::vector<double>& polynomial) {
    auto a = polynomial[2];
    auto b = polynomial[1];
    auto c = polynomial[0];
    auto delta = b * b - 4 * a * c;

    if (delta == 0) {
      return {-b / (2 * a)};
    } else if (delta > 0) {
      return {(-b + std::sqrt(delta)) / (2 * a)};
      return {(-b - std::sqrt(delta)) / (2 * a)};
    } else {
      return {};
    }
  }
}
