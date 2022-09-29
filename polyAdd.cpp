#include <functional>
#include <iostream>
#include <map>
#include <string>

int main() {
  using Exponent = int;
  using Coefficient = int;

  std::map<Exponent, Coefficient, std::greater<Exponent>> terms;

  constexpr int num_polynomials = 2;
  for (int i = 0; i < num_polynomials; i += 1) {
    std::string input;
    std::cin >> input;

    for (int j = 0; j < input.size(); j += 2) {
      const int coefficient = static_cast<int>(input[j] - '0');
      const int exponent = static_cast<int>(input[j + 1] - '0');

      terms[exponent] += coefficient;
    }
  }

  bool is_first_term = true;
  for (const auto term : terms) {
    const auto exponent = term.first;
    const auto coefficient = term.second;

    if (is_first_term) {
      is_first_term = false;
    } else {
      std::cout << " ";
    }

    std::cout << coefficient << "X^" << exponent;
  }
  std::cout << "\n";
}
