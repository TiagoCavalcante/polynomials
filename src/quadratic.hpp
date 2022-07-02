#pragma once

#include <cmath>
#include <vector>

void getQuadraticRoots(const std::vector<double>& polynomial,
                       std::vector<double>& roots) {
  auto a = polynomial[2];
  auto b = polynomial[1];
  auto c = polynomial[0];
  auto delta = b * b - 4 * a * c;

  if (delta == 0) {
    roots.push_back(-b / (2 * a));
  } else if (delta > 0) {
    roots.push_back((-b + std::sqrt(delta)) / (2 * a));
    roots.push_back((-b - std::sqrt(delta)) / (2 * a));
  }
}