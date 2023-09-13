#include <iostream>
#include <sstream>

// Global variables
//double a, b, c;

//using namespace std;

// Silly square function that is not immutable and not pure
const std::tuple<double, std::string> silly_square(const double x)
{
    std::stringstream output;
    output << "Calculating the silly square of " << x << "\n";
    double result = 0;
    for (int i = 0; i < x; ++i)
    {
        result = result + x;
        output << "Iteration " << i + 1 << ": Current result = " << result << "\n";
    }
    return std::make_tuple(result, output.str());
}

// Helper function to calculate square root without using std::sqrt()
/*const double square_root(const double x, const double epsilon = 1e-10, const int max_iterations = 1000)
{
    std::cout << "Calculating the square root of " << x << "\n";
    if (x < 0)
    {
        return -1; // Invalid input
    }
    if (x == 0)
    {
        return 0;
    }

    double low = 0, high = x;
    double mid;
    for (int i = 0; i < max_iterations; ++i)
    {
        mid = (low + high) / 2.0;
        double mid_square = mid * mid;
        std::cout << "Iteration " << i + 1 << ": Midpoint = " << mid << ", Midpoint squared = " << mid_square << "\n";

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

    return mid;
}*/


std::tuple<double, std::string> square_root(const double x, const double epsilon = 1e-10, const int max_iterations = 1000)
{
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
    std::stringstream messageStream;

    for (int i = 0; i < max_iterations; ++i)
    {
        mid = (low + high) / 2.0;
        double mid_square = mid * mid;
        messageStream << "Iteration " << i + 1 << ": Midpoint = " << mid << ", Midpoint squared = " << mid_square << "\n";

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

/*double calculate_median(const double a, const double b, const double c)
{
    std::cout << "Calculating the median of a triangle with sides a = " << a << ", b = " << b << ", c = " << c << "\n";
    double result = 0.5 * square_root(2 * silly_square(b) + 2 * silly_square(c) - silly_square(a));
    return result;
}*/

double calculate_median(const double a, const double b, const double c)
{
    auto squaredB = silly_square(b);
    auto squaredC = silly_square(c);
    auto squaredA = silly_square(a);

    auto square_rootResult = square_root(2 * (std::get<0>(squaredB) + std::get<0>(squaredC)) - std::get<0>(squaredA));

    double result = 0.5 * std::get<0>(square_rootResult);

    return result;
}

int main()
{

    using namespace std;

    double a = 3;
    double b = 4;
    double c = 5;
    std::cout << "Triangle sides: a = " << a << ", b = " << b << ", c = " << c << "\n";

    auto squaredB = silly_square(b);
    auto squaredC = silly_square(c);
    auto squaredA = silly_square(a);
    auto output = square_root(2 * (get<0>(squaredB) + get<0>(squaredC)) - get<0>(squaredA));
    std::cout << "Calculating the median of a triangle with sides a = " << a << ", b = " << b << ", c = " << c << "\n";
    std::cout << get<1>(squaredB) << std::endl;
    std::cout << get<1>(squaredC) << std::endl;
    std::cout << get<1>(squaredA) << std::endl;
    std::cout << get<1>(output) << std::endl;
    double median_a = calculate_median(a, b, c);

    a = 4, b = 3, c = 5;
    squaredB = silly_square(b);
    squaredC = silly_square(c);
    squaredA = silly_square(a);
    output = square_root(2 * (get<0>(squaredB) + get<0>(squaredC)) - get<0>(squaredA));
    std::cout << "Calculating the median of a triangle with sides a = " << a << ", b = " << b << ", c = " << c << "\n";
    std::cout << get<1>(squaredB) << std::endl;
    std::cout << get<1>(squaredC) << std::endl;
    std::cout << get<1>(squaredA) << std::endl;
    std::cout << get<1>(output) << std::endl;
    double median_b = calculate_median(a, b, c);

    a = 5, b = 3, c = 4;
    squaredB = silly_square(b);
    squaredC = silly_square(c);
    squaredA = silly_square(a);
    output = square_root(2 * (get<0>(squaredB) + get<0>(squaredC)) - get<0>(squaredA));
    std::cout << "Calculating the median of a triangle with sides a = " << a << ", b = " << b << ", c = " << c << "\n";
    std::cout << get<1>(squaredB) << std::endl;
    std::cout << get<1>(squaredC) << std::endl;
    std::cout << get<1>(squaredA) << std::endl;
    std::cout << get<1>(output) << std::endl;
    double median_c = calculate_median(a, b, c);

    std::cout << "Medians:\n";
    std::cout << "Median from vertex A: " << median_a << "\n";
    std::cout << "Median from vertex B: " << median_b << "\n";
    std::cout << "Median from vertex C: " << median_c << "\n";

    return 0;
}
