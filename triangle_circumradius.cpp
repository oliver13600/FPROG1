#include <iostream>
#include <tuple>
#include <sstream>


// Global variables
//double a, b, c;
//double s, area, circumradius;

// Helper function to calculate square root without using std::sqrt()
std::tuple<double, std::string> square_root(const double x, const double epsilon = 1e-10, const int max_iterations = 1000)
{
    std::stringstream messageStream;
    messageStream << "Calculating square root of " << x << "\n";
    if (x < 0)
    {
        return std::make_tuple(-1.0, "Invalid input"); // Invalid input
    }
    if (x == 0)
    {
        return std::make_tuple(0.0, "Square root of 0 is 0");
    }

    double low = 0, high = x;
    double mid;
    

    for (int i = 0; i < max_iterations; ++i)
    {
        mid = (low + high) / 2.0;
        double mid_square = mid * mid;
        messageStream << "Iteration " << i + 1 << ": mid = " << mid << ", mid_square: " << mid_square << "\n";

        if (mid_square > x)
        {
            high = mid;
        }
        else if (mid_square < x)
        {
            low = mid;
        }

        if (high - low < epsilon)
        {
            break;
        }
    }

    return std::make_tuple(mid, messageStream.str());
}

std::tuple<double, std::string> calculate_circumradius(const double a, const double b, const double c)
{
    double s = (a + b + c) / 2;
    auto area = square_root(s * (s - a) * (s - b) * (s - c));
    double circumradius = (a * b * c) / (4 * std::get<0>(area));
    return std::make_tuple(circumradius, std::get<1>(area));

}

int main()
{
    double a = 3, b = 4, c = 5;
    std::cout << "Triangle sides: a = " << a << ", b = " << b << ", c = " << c << "\n";

    auto result = calculate_circumradius(a,b,c);

    std::cout << std::get<1>(result) << "\n";

    std::cout << "Circumradius: " << std::get<0>(result) << "\n";

    return 0;
}
