#include <array>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

class Monster {
public:
    enum class Type {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,

        total_types
    };

private:
    Type m_type;
    std::string m_name;
    std::string m_roar;
    int m_hit_points;

public:
    Monster(Type type, const std::string& name, const std::string& roar, int hit_points)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hit_points{hit_points} {};

    std::string_view get_type_string() {
        switch(m_type) {
            case Type::dragon:      return "dragon";
            case Type::goblin:      return "goblin";
            case Type::ogre:        return "ogre";
            case Type::orc:         return "orc";
            case Type::skeleton:    return "skeleton";
            case Type::troll:       return "troll";
            case Type::vampire:     return "vampire";
            case Type::zombie:      return "zombie";
            default:                return "unknown";
        }
    }

    void print() {
        std::cout << m_name << " the " << get_type_string()
                  << " has " << m_hit_points << " hit points and says " 
                  << m_roar << '\n';
    }
};

class MonsterGenerator {
private:
    static int get_random_number(int min, int max) {
        static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
        return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
    }
public:
    static Monster generate_monster() {
        static constexpr std::array NAMES{"Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans"};
        static constexpr std::array ROARS{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};

        int total_types = static_cast<int>(Monster::Type::total_types);
        auto type = static_cast<Monster::Type>(get_random_number(0, total_types - 1));
        int hit_points = get_random_number(1, 100);
        auto name{NAMES[get_random_number(0, NAMES.size() - 1)]};
        auto roar{ROARS[get_random_number(0, ROARS.size() - 1)]};

        return {type, name, roar, hit_points};
    }
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Monster m{MonsterGenerator::generate_monster()};
    m.print();
    return 0;
}
