#include <iostream>
#include <sstream>
#include <vector>
#include "falsePosition/falsePosition.hpp"
#include "linear/linear.hpp"
#include "polynomials.hpp"
#include "quadratic/quadratic.hpp"

int main() {
  std::vector<double> polynomial;

  std::string buffer;
  std::getline(std::cin, buffer);

  std::stringstream stream(buffer);

  double coefficient;

  while (stream >> coefficient) {
    polynomial.push_back(coefficient);
  }

  // We may "loose" the root 0 when simplifying the polynomial, e.g.:
  // 0 is a root of x² - x = 0, but isn't a root of the equivalent polynomial
  // x - 1 = 0.
  bool hasZero = -epsilon < getF(polynomial)(0) < epsilon;

  simplifyPolynomial(polynomial);

  std::vector<double> roots;

  if (polynomial.size() == 2) {
    roots = linear::getRoots(polynomial, hasZero);
  } else if (polynomial.size() == 3) {
    roots = quadratic::getRoots(polynomial, hasZero);
  } else if (polynomial.size() > 3) {
    roots = falsePosition::getRoots(polynomial, hasZero);
  }

  // Print the roots.
  std::cout << "{ ";

  for (auto& x : roots) {
    std::cout << x << "; ";
  }

  std::cout << "}\n";
}