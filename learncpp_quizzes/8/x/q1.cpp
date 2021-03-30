#include <iostream>

enum class MonsterType {
    ogre,
    dragon,
    orc,
    giant_spider,
    slime
};

struct Monster {
    MonsterType type {};
    std::string name {};
    int health {};
};

std::string type_to_string(MonsterType type) {
    switch (type) {
        case MonsterType::ogre:
            return "ogre";
        case MonsterType::dragon:
            return "dragon";
        case MonsterType::orc:
            return "orc";
        case MonsterType::giant_spider:
            return "giant spider";
        case MonsterType::slime:
            return "slime";
    }
    return "unknown";
}

void print_monster(Monster monster) {
    std::string type {type_to_string(monster.type)};
    std::cout << "This " << type << " is named " << monster.name
              << " and has health " << monster.health << '\n';
}

int main() {
    Monster torg {MonsterType::ogre, "Torg", 145};
    Monster blurp {MonsterType::slime, "Blurp", 23};
    print_monster(torg);
    print_monster(blurp);
    return 0;
}
