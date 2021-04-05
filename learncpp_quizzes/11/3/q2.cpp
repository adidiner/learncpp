#include <iostream>

class Point3d {
private:
    int m_x;
    int m_y;
    int m_z;

public:
    void set_values(int x, int y, int z) {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print() {
        std::cout << '<' << m_x << ", " << m_y << ", " << m_z << '>';
    }

    bool is_equal(const Point3d& other) {
        return (m_x == other.m_x && m_y == other.m_y && m_z == other.m_z);
    }
};

int main() {
    Point3d point1;
    point1.set_values(1, 2, 3);
 
    point1.print();
    std::cout << '\n';
 
    Point3d point2;
    point2.set_values(1, 2, 3);
 
    if (point1.is_equal(point2)) {
        std::cout << "point1 and point2 are equal\n";
    } else {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3;
    point3.set_values(3, 4, 5);
 
    if (point1.is_equal(point3)) {
        std::cout << "point1 and point3 are equal\n";
    } else {
        std::cout << "point1 and point3 are not equal\n";
    }

    return 0;
}
