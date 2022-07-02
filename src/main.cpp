#include <iostream>
#include <sstream>
#include <vector>
#include "couchy.hpp"
#include "falsePosition.hpp"
#include "linear.hpp"
#include "polynomials.hpp"
#include "quadratic.hpp"

int main() {
  std::vector<double> polynomial;

  std::string buffer;
  std::getline(std::cin, buffer);

  std::stringstream stream(buffer);

  double coefficient;

  while (stream >> coefficient) {
    polynomial.push_back(coefficient);
  }

  simplifyPolynomial(polynomial);

  std::vector<double> roots;

  if (polynomial.size() == 2) {
    getLinearRoots(polynomial, roots);
  } else if (polynomial.size() == 3) {
    getQuadraticRoots(polynomial, roots);
  } else if (polynomial.size() > 3) {
    const auto f = getF(polynomial);
    const auto upperBound = bound(polynomial);

    // Negatives first so it is ordered.
    auto numberOfNegativeRoots = maximumNumberOfPositiveRoots(polynomial);

    if (numberOfNegativeRoots) {
      auto interval = std::pair{-upperBound, 0.0};
      getRoots(f, interval, roots, numberOfNegativeRoots);
    }

    auto numberOfPositiveRoots = maximumNumberOfPositiveRoots(polynomial);

    if (numberOfPositiveRoots) {
      auto interval = std::pair{0.0, upperBound};
      getRoots(f, interval, roots, numberOfPositiveRoots);
    }
  }

  // Print the roots.
  std::cout << "{ ";

  for (auto& x : roots) {
    std::cout << x << "; ";
  }

  std::cout << "}\n";
}