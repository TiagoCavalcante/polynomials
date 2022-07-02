#pragma once

#include <vector>

void getLinearRoots(const std::vector<double>& polynomial,
                    std::vector<double>& roots) {
  roots.push_back(-polynomial.back() / polynomial.front());
}