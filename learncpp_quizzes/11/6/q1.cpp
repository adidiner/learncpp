#include <cstdint>
#include <iostream>

class RGBA {
public:
    using component_t = std::uint_fast8_t;
    
private:
    component_t m_red;
    component_t m_green;
    component_t m_blue;
    component_t m_alpha;

public:
    RGBA(component_t red=0, component_t green=0, component_t blue=0, component_t alpha=255) 
        : m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha } {}

    void print() {
        std::cout << "r=" << static_cast<int>(m_red) 
                  << " g=" << static_cast<int>(m_green)
                  << " b=" << static_cast<int>(m_blue) 
                  << " a=" << static_cast<int>(m_alpha) <<'\n';
    }
    
};

int main() {
    RGBA teal{0, 127, 127};
    teal.print();

    return 0;
}
