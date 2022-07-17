#pragma once

#include <cmath>
#include <functional>
#include "../constants.hpp"
#include "../math.hpp"
#include "../polynomials.hpp"
#include "couchy.hpp"

namespace falsePosition {
  int sign(double x) {
    if (x < 0) {
      return -1;
    } else if (x > 0) {
      return 1;
    } else {
      return 0;
    }
  }

  // Get x0 with the false position method
  double falsePosition(std::function<double(double)> f, double a, double b) {
    auto fa = f(a);
    auto fb = f(b);
    return (a * fb - b * fa) / (fb - fa);
  }

  double getRoot(std::function<double(double)> f, double a, double b) {
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

  void getRootsInInterval(std::vector<double>& roots,
                          std::function<double(double)> f,
                          double a,
                          double b,
                          int remainingRoots) {
    for (auto i = a; i < b;) {
      auto current = i;
      i += partitionSize;

      // If one value is bellow the y=0 line and the other value is over it,
      // certainly it crossed the y=0 line.
      if (sign(f(current)) != sign(f(i))) {
        auto x = getRoot(f, current, i);

        // Check if x really is a root.
        if (math::isZero(f(x))) {
          // Just add this root if it's different of the last one.
          roots.push_back(x);
          remainingRoots--;

          if (!remainingRoots) break;
        }
      }
    }
  }

  std::vector<double> getRoots(const std::vector<double>& polynomial,
                              bool hasZero) {
    std::vector<double> roots;

    const auto f = getF(polynomial);
    const auto upperBound = bound(polynomial);

    // Negatives first so it is ordered.
    auto negativeRoots = negativeVariations(polynomial);
    if (negativeRoots) {
      getRootsInInterval(roots, f, -upperBound, partitionSize, negativeRoots);
    }

    if (hasZero) {
      roots.push_back(0);
    }

    auto positiveRoots = variations(polynomial);
    if (positiveRoots) {
      getRootsInInterval(roots, f, 0, upperBound + epsilon, positiveRoots);
    }

    return roots;
  };
}