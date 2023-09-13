#include <iostream>
#include <sstream>
#include <tuple>

using namespace std;



const tuple<int, string> square(const int e)
{
  stringstream output;
  int dummy = e;
  int dummy2 = e;
  int result = e;
  for (int i = 1; i < dummy2; i++)
  {
    result = result + dummy;
    output << "i: " << i << " dummy:" << dummy << " e:" << result << endl;
  }
  output << "square:" << result;
  return make_tuple(result, output.str());
}

const double squareroot(const double x)
{ /* computes the square root of x */

  if (x == 0)
    return 0;

  /* the sqrt must be between xhi and xlo */
  double xhi = x;
  double xlo = 0;
  double guess = x / 2;

  /* We stop when guess*guess-x is very small */

  while (abs(guess * guess - x) > 0.00001)
  {
    if (guess * guess > x)
    {
      xhi = guess;
    }

    else
    {
      xlo = guess;
    }

    guess = (xhi + xlo) / 2;
  }
  return guess;
}

const double pythagoras(const double x)
{
  double result = x;
  return result;
}



int main(int argc, char *argv[])
{
  int x = 0;
  int y = 0;
  double z = 0; // double ?
  string output;
  x = 3;
  y = 4;

  auto results = square(x);
  int squareX = get<0>(results);
  cout << get<1>(results) << endl;
  results = square(y);
  int squareY = get<0>(results);
  cout << get<1>(results) << endl;

  double squarerootResult = squareroot(squareX + squareY);

  cout << "guess:" << squarerootResult << endl;

  z = pythagoras(squarerootResult);
  cout << "euklid:" << z << endl;
  cout << z << endl;
  return 0;
}
