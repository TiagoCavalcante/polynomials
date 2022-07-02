#pragma once

#include <cmath>
#include <vector>

namespace quadratic {
  std::vector<double> getRoots(const std::vector<double>& polynomial,
                               bool hasZero) {
    auto a = polynomial[2];
    auto b = polynomial[1];
    auto c = polynomial[0];
    auto delta = b * b - 4 * a * c;

    if (delta == 0) {
      auto root = -b / (2 * a);
      if (hasZero) {
        return root > 0 ? std::vector{0.0, root} : std::vector{root, 0.0};
      } else {
        return {root};
      }
    } else if (delta > 0) {
      auto root1 = (-b - std::sqrt(delta)) / (2 * a);
      auto root2 = (-b + std::sqrt(delta)) / (2 * a);
      if (hasZero) {
        if (root2 < 0) {  // Both are less than 0.
          return {root1, root2, 0};
        } else if (root1 < 2) {  // Just the 1st is less than 0.
          return {root1, 0, root2};
        } else {  // Both are greater than 0.
          return {0, root1, root2};
        }
      } else {
        return {root1, root2};
      }
    } else {
      if (hasZero) {
        return {0};
      } else {
        return {};
      }
    }
  }
}