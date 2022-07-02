#pragma once

#include <vector>

namespace linear {
  std::vector<double> getRoots(const std::vector<double>& polynomial,
                               bool hasZero) {
    auto root = -polynomial.back() / polynomial.front();

    if (hasZero) {
      // Ensure the roots are ordered.
      return root > 0 ? std::vector{0.0, root} : std::vector{root, 0.0};
    } else {
      return {root};
    }
  }
}