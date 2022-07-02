#pragma once

#include <cmath>
#include <functional>
#include "constants.hpp"
#include "math.hpp"

const double partitionSize = 1;

// Get x0 with the false position method
double falsePosition(std::function<double(double)> f, double a, double b) {
  auto fa = f(a);
  auto fb = f(b);
  return (a * fb - b * fa) / (fb - fa);
}

double solve(std::function<double(double)> f, double a, double b) {
  auto x = falsePosition(f, a, b);

  for (auto i = 0; i < iterations; i++) {
    if (f(x) < 0 && f(b) > 0) {
      a = x;
    } else {
      b = x;
    }

    x = falsePosition(f, a, b);
  }

  return x;
}

void getRoots(std::function<double(double)> f,
              std::pair<double, double> interval,
              std::vector<double>& roots,
              int remainingRoots) {
  auto floor = std::floor(interval.first);
  auto ceil = std::ceil(interval.second);

  for (auto i = floor; remainingRoots && i < ceil + epsilon;) {
    auto current = i;
    i += partitionSize;
    if (sign(f(current)) != sign(f(i))) {
      auto x = solve(f, current, i);

      // Check if x is a root,
      // and if it is a root, check if it wasn't added before
      if (std::abs(f(x)) < epsilon &&
          (roots.size() == 0 || std::abs(roots.back() - x) > epsilon)) {
        // Just add this root if it's different of the last one.
        roots.push_back(x);
        remainingRoots--;
      }
    }
  }
}