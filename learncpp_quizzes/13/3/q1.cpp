#include <iostream>
 
class Fraction {
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };
 
public:
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator} {
        reduce();
    }
 
    void print() const {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    static int gcd(int a, int b) {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }

    void reduce() {
        int fgcd = gcd(m_numerator, m_denominator);
        m_numerator /= fgcd;
        m_denominator /= fgcd;
    }

    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, int b);
    friend Fraction operator*(int a, const Fraction& b);
    friend std::ostream& operator<<(std::ostream &out, const Fraction& f);
    friend std::istream& operator>>(std::istream &in, Fraction& f);
};

Fraction operator*(const Fraction& a, const Fraction& b) {
    return {a.m_numerator * b.m_numerator, a.m_denominator * b.m_denominator};
}

Fraction operator*(const Fraction& a, int b){
    return {a.m_numerator * b, a.m_denominator};

}

Fraction operator*(int a, const Fraction& b){
    return {b.m_numerator * a, b.m_denominator};
}

std::ostream& operator<<(std::ostream &out, const Fraction& f) {
    out << f.m_numerator << '/' << f.m_denominator;
    return out;
}

std::istream& operator>>(std::istream &in, Fraction& f) {
    char slash;
    in >> f.m_numerator;
    in >> slash;
    in >> f.m_denominator;
    f.reduce();
    return in;
}

int main() {
    Fraction f1{};
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;
 
    Fraction f2{};
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;
 
    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value
    return 0;
}
