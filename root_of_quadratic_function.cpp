#include <iostream>
#include <utility>
#include <complex>
#include <sstream>
#include <stdint.h>



typedef std::complex<double> complex;

const std::tuple<double, std::string> square(const double e)
{
  std::stringstream output;
  double dummy = e;
  double dummy2 = e;
  double result = e;
  for (int i = 1; i < dummy2; i++)
  {
    result = result + dummy;
    output << "i: " << i << " dummy:" << dummy << " e:" << result << std::endl;
  }
  output << "square:" << result;
  return make_tuple(result, output.str());
}

const inline float squareroot(const float number)
{
  union Conv
  {
    float f;
    uint32_t i;
  };
  Conv conv;
  conv.f = number;
  conv.i = 0x5f3759df - (conv.i >> 1);
  conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);
  return 1 / conv.f;
}

const std::pair<complex, complex> solve_quadratic_equation(const double a, const double x, const double y, const double squareOfB)
{
  double b = x;
  double c = y;
  b /= a;
  c /= a;
  double discriminant = squareOfB - 4 * c;
  if (discriminant < 0)
    return std::make_pair(complex(-b / 2, squareroot(-discriminant) / 2),
                          complex(-b / 2, -squareroot(-discriminant) / 2));

  double root = std::sqrt(discriminant);
  double solution1 = (b > 0) ? (-b - root) / 2
                             : (-b + root) / 2;

  return std::make_pair(solution1, c / solution1);
}

int main()
{
  double x = 4;
  x /= 3;
  auto results = square(x);
  std::cout << std::get<1>(results) << std::endl;
  std::pair<complex, complex> result = solve_quadratic_equation(3, 4, 5, std::get<0>(results));
  std::cout << result.first << ", " << result.second << std::endl;
}