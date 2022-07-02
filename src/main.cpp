#include <iostream>
#include <sstream>
#include <vector>
#include "polynomials.hpp"
#include "falsePosition/falsePosition.hpp"
#include "linear/linear.hpp"
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

  simplifyPolynomial(polynomial);

  std::vector<double> roots;

  if (polynomial.size() == 2) {
    roots = linear::getRoots(polynomial);
  } else if (polynomial.size() == 3) {
    roots = quadratic::getRoots(polynomial);
  } else if (polynomial.size() > 3) {
    roots = falsePosition::getRoots(polynomial);
  }

  // Print the roots.
  std::cout << "{ ";

  for (auto& x : roots) {
    std::cout << x << "; ";
  }

  std::cout << "}\n";
}