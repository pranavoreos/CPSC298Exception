//
//  main.cpp
//  Exception
//
//  Created by Pranav Saravanan.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <exception>

// Function to compute the sum of the numbers from 1 to n
unsigned long sigma(unsigned long n) {
  // Check if the input argument is valid (n >= 1)
  // and report an error if it isn't by raising a std::runtime_exception exception
  if (n < 1) {
    throw std::runtime_exception(
        (std::string("Invalid input: n = ") + std::to_string(n) +
         std::string(" (precondition: n >= 1) [") + std::string(__FILE__) +
         std::string(":") + std::to_string(__LINE__) + std::string("]")
         ).c_str());
  }

  // Compute the sum of the integers from 1 to n, inclusive
  unsigned long sum = 0;
  for (unsigned long i = 1; i <= n; i++) {
    sum += i;
  }

  // Check that the sum computed in the for loop is identical to
  // the sum expected from the formula n(n+1)/2
  if (sum != n * (n + 1) / 2) {
    throw std::runtime_exception(
        (std::string("Invalid output: sum = ") + std::to_string(sum) +
         std::string(" (postcondition: sum == n * (n + 1) / 2) [") + std::string(__FILE__) +
         std::string(":") + std::to_string(__LINE__) + std::string("]")
         ).c_str());
  }

  return sum;
}

int main() {
  try {
    // Call the sigma function with the actual argument 5 (which is valid)
    std::cout << "sigma(5) = " << sigma(5) << std::endl;
  } catch (std::runtime_error& e) {
    // Catch and print the error message if the sigma function throws a std::runtime_error exception
    std::cerr << "Error: " << e.what() << std::endl;
  }

  try {
    // Call the sigma function with the actual argument 0 (which is invalid)
    std::cout << "sigma(0) = " << sigma(0) << std::endl;
  } catch (std::runtime_error& e) {
    // Catch and print the error message if the sigma function throws a std::runtime_error exception
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
