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

int main() {
    Fraction f1{2, 5};
    f1.print();
 
    Fraction f2{3, 8};
    f2.print();
 
    Fraction f3{ f1 * f2 };
    f3.print();
 
    Fraction f4{ f1 * 2 };
    f4.print();
 
    Fraction f5{ 2 * f2 };
    f5.print();
 
    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();
 
    Fraction f7{0, 6};
    f7.print();
    return 0;
}
