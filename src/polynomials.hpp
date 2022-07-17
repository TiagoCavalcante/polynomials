#pragma once

#include <functional>
#include <vector>
#include "constants.hpp"
#include "math.hpp"

void simplifyPolynomial(std::vector<double>& polynomial) {
  while (math::isZero(polynomial.front())) {
    polynomial.erase(polynomial.begin());
  }
  while (math::isZero(polynomial.back())) {
    polynomial.erase(polynomial.end());
  }
}

std::function<double(double)> getF(std::vector<double> polynomial) {
  return [polynomial](double x) {
    double result = 0;
    double xPow = 1;

    for (auto& coefficient : polynomial) {
      result += coefficient * xPow;
      xPow *= x;
    }

    return result;
  };
}