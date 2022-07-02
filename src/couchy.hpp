#pragma once

#include <cmath>
#include <functional>
#include <vector>
#include "math.hpp"

int variations(const std::vector<double>& polynomial) {
  int v = 0;
  for (auto i = 0; i < polynomial.size();) {
    if (sign(polynomial[i]) != sign(polynomial[++i])) {
      v++;
    }
  }
  return v;
}

// Variations of the polynomial p(-x)
int negativeVariations(const std::vector<double>& polynomial) {
  auto v = variations(polynomial);

  // If their signs are equal, they should be different as x is negated.
  if (sign(polynomial[0]) == sign(polynomial[1])) {
    v++;
  }

  return v;
}

// Biggest in terms of modulo.
double biggestNonLastCoefficient(const std::vector<double>& polynomial) {
  auto biggest = std::abs(polynomial[0]);
  for (auto i = 0; i < polynomial.size() - 1; i++) {
    if (std::abs(polynomial[i]) > biggest) {
      biggest = std::abs(polynomial[i]);
    }
  }
  return biggest;
}

int maximumNumberOfPositiveRoots(const std::vector<double>& polynomial) {
  return min(variations(polynomial), polynomial.size() - 1);
}

int maximumNumberOfNegativeRoots(const std::vector<double>& polynomial) {
  return min(negativeVariations(polynomial), polynomial.size() - 1);
}

double bound(const std::vector<double>& polynomial) {
  // Cauchy's bound.
  return 1 + biggestNonLastCoefficient(polynomial) / polynomial.back();
}