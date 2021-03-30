#include "constants.h"
#include <iostream>

// updated according to chapter 7.x quiz q1

double get_height()  {
    double height {};
    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> height;
    return height;
}

double height_by_time(double initial_height, double seconds) {
    double height {initial_height - (constants::g * (seconds * seconds)) / 2};
    if (height > 0) {
        return height;
    }
    return 0;
}


int main() {
    double initial_height {get_height()};
    double height {initial_height};
    
    for (int seconds { 0 }; height > 0; ++seconds) {
        height = height_by_time(initial_height, seconds);
        std::cout << "At " << seconds << " seconds,"
                  << " the ball is at height: " 
                  << height_by_time(initial_height, seconds) << " meters\n";
    }

    return 0;
}
