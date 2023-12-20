#include <iostream>
#include <vector>

int main() {
    // Number of faces on each die
    const int faces_A = 6;
    const int faces_B = 6;

    // Vector to store the distribution of sums
    std::vector<int> sum_distribution(2 * faces_A + 1, 0);

    // Calculate distribution
    for (int face_A = 1; face_A <= faces_A; ++face_A) {
        for (int face_B = 1; face_B <= faces_B; ++face_B) {
            int sum = face_A + face_B;
            sum_distribution[sum]++;
        }
    }

    // Total number of combinations
    int total_combinations = faces_A * faces_B;

    // Output the probability distribution
    for (int i = 2; i <= 2 * faces_A; ++i) {
        double probability = static_cast<double>(sum_distribution[i]) / total_combinations;
        std::cout << "P(Sum = " << i << ") = "<<(sum_distribution[i])<<"/"<< total_combinations<<" = "<< probability << std::endl;
    }

    return 0;
}
