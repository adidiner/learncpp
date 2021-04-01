#include <iostream>
#include <array>

namespace Items {
    constexpr int total_items{3};

    enum Item {
        health_potion,
        torch,
        arrow
    };
}

using inventory_t = std::array<int, Items::total_items>;

int count_total_items(const inventory_t& item_count) {
    int total{0};
    for (const auto& count : item_count) {
        total += count;
    }
    return total;
}

int main() {
    inventory_t item_count{2, 5, 10};
    std::cout << "Total items: " << count_total_items(item_count) << '\n';
    return 0;
}
