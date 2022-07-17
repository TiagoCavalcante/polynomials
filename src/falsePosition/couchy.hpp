#pragma once

#include <cmath>
#include <functional>
#include <vector>

namespace falsePosition {
  // Variations of signs of the polynomial p(x), it is the maximum number
  // of positive roots.
  int variations(const std::vector<double>& polynomial) {
    int v = 0;
    for (auto i = 0; i < polynomial.size();) {
      auto current = polynomial[i];
      auto next = polynomial[++i];
      if ((current < 0 && next > 0) || (current > 0 && next < 0)) {
        v++;
      }
    }
    return v;
  }

  // Variations of signs of the polynomial p(-x), it is the maximum number
  // of negative roots.
  int negativeVariations(const std::vector<double>& polynomial) {
    int v = 0;
    for (auto i = 0; i < polynomial.size();) {
      auto current = polynomial[i];
      auto next = polynomial[++i];
      // If i is odd.
      // (-k)^n, where k is a positive number is -k, so instead of checking if
      // the signs are opposite we are going to check if the signs are the same
      // as either the sign of current is negated or the sign of next is
      // negated.
      if ((current < 0 && next < 0) || (current > 0 && next > 0)) {
        v++;
      }
    }
    return v;
  }

  // Biggest in terms of modulo, the last coefficient is the one that
  // accompanies the term a^n.
  double biggestNonLastCoefficient(const std::vector<double>& polynomial) {
    auto biggest = std::abs(polynomial[0]);
    for (auto i = 0; i < polynomial.size() - 2; i++) {
      if (std::abs(polynomial[i]) > biggest) {
        biggest = std::abs(polynomial[i]);
      }
    }
    return biggest;
  }

  double bound(const std::vector<double>& polynomial) {
    // Cauchy's bound.
    return std::abs(1 +
                    biggestNonLastCoefficient(polynomial) / polynomial.back());
  }
}