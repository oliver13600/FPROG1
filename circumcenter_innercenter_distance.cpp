#include <iostream>
#include <tuple>
#include <sstream>

// Global variables
//double a, b, c;
//double s, area, circumradius, inradius, distance;

struct Triangle
{
    double s, area, circumradius, inradius, distance;
    std::string output;
};

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



Triangle calculate_area_and_radii(const double a, const double b, const double c)
{
    Triangle triangle;
    triangle.s = (a + b + c) / 2;
    auto resultArea = square_root(triangle.s * (triangle.s - a) * (triangle.s - b) * (triangle.s - c));
    triangle.area = std::get<0>(resultArea);
    triangle.inradius = triangle.area / triangle.s;
    triangle.circumradius = (a * b * c) / (4 * triangle.area);
    triangle.output = std::get<1>(resultArea);
    return triangle;
}

const std::tuple<double ,std::string> calculate_distance(const double circumradius, const double inradius)
{
    auto distance = square_root(circumradius * circumradius - 2 * circumradius * inradius);
    return std::make_tuple(std::get<0>(distance), std::get<1>(distance));
}


int main()
{
    double a = 3;
    double b = 4;
    double c = 5;
    std::cout << "Triangle sides: a = " << a << ", b = " << b << ", c = " << c << "\n";

    Triangle triangle;
    triangle = calculate_area_and_radii(a,b,c);
    std::cout << triangle.output << "\n";
    std::cout << "Inradius: " << triangle.inradius << "\n";
    std::cout << "Circumradius: " << triangle.circumradius << "\n";

    //calculate_distance(triangle.circumradius, triangle.inradius);
    auto distance = calculate_distance(triangle.circumradius,triangle.inradius);
    std::cout << std::get<1>(distance) << "\n";
    triangle.distance = std::get<0>(distance);
    std::cout << "Distance between circumcenter and incenter: " << triangle.distance << "\n";

    return 0;
}
