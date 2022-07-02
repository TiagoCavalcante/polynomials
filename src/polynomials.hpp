#pragma once

#include <functional>
#include <vector>
#include "constants.hpp"

void simplifyPolynomial(std::vector<double>& polynomial) {
  while (-epsilon < polynomial.front() < epsilon) {
    polynomial.erase(polynomial.begin());
  }
  while (-epsilon < polynomial.back() < epsilon) {
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