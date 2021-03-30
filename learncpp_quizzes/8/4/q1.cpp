#include <iostream>

struct Advertising {
    int ads {};
    double clicked_perc {};
    double avg_income {};
};

void print_advertising(Advertising ad) {
    std::cout << "Total ads: " << ad.ads << '\n';
    std::cout << "Percantage of clicked ads: " << ad.clicked_perc << '\n';
    std::cout << "Average earning of clicked ad: " << ad.avg_income << '\n';
    std::cout << "Total income: " 
              << ad.ads * (ad.clicked_perc / 100) * ad.avg_income << '\n';
}


int main() {
    Advertising ad {};
    std::cin >> ad.ads;
    std::cin >> ad.clicked_perc;
    std::cin >> ad.avg_income;
    print_advertising(ad);
    return 0;
}
