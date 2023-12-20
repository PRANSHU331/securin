#include <iostream>

int main() {
    // Number of faces on each die
    const int faces_A = 6;
    const int faces_B = 6;

    // Calculate total combinations
    int total_combinations = faces_A * faces_B;

    // Output the result
    std::cout << "Total combinations: " << total_combinations << std::endl;

    return 0;
}
