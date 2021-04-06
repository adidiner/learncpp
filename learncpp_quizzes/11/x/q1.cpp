#include <cmath>
#include <iostream>

class Point2d {
private:
    double m_x;
    double m_y;

public:
    Point2d(double x=0.0, double y=0.0) : m_x{x}, m_y{y} {}

    void print() const {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    double distance_to(const Point2d& other) const {
        double a = (m_x - other.m_x) * (m_x - other.m_x);
        double b = (m_y - other.m_y) * (m_y - other.m_y);
        return std::sqrt(a + b);
    }

    friend double distance_from(const Point2d& p1, const Point2d& p2);
};

double distance_from(const Point2d& p1, const Point2d& p2) {
    double a = (p1.m_x - p2.m_x) * (p1.m_x - p2.m_x);
    double b = (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y);
    return std::sqrt(a + b);
}

int main() {
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distance_to(second) << '\n';
    std::cout << "Distance between two points: " << distance_from(first, second) << '\n';
 
    return 0;
}
