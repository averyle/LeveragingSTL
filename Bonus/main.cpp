#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>
#include <string>
#include "Utility.h"
#include "Car.h"
#include <stack>

std::vector<int> createElevationMap();

int countWater(std::vector<int>& range, std::stack<int>& lefts, int currentIndex) {
    if (currentIndex >= range.size()) {
        return 0;
    }
    int count = 0;
    if (lefts.size() == 0) {
        lefts.push(currentIndex);
        return countWater(range, lefts, currentIndex + 1);
    }
    if (range[currentIndex] < range[lefts.top()]) {
        lefts.push(currentIndex);
        return countWater(range, lefts, currentIndex + 1);
    }
    while (!range.empty() && !lefts.empty() && range[currentIndex] > range[lefts.top()]) {
        int top = lefts.top();
        lefts.pop();
        if (!lefts.empty()) {
            count += (std::min(range[currentIndex], range[lefts.top()]) - range[top]) * (currentIndex - lefts.top() - 1);
        }
    }
    lefts.push(currentIndex);
    return count + countWater(range, lefts, currentIndex + 1);
}

int main() {
    auto range = createElevationMap();
    std::cout << "Elevation Map: " << range << "\n";

    // TODO: print out the amount of trapped water after it rains
    std::stack<int> lefts;
    
//    std::vector test = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//    std::cout << test;
//    std::cout << "\n" << countWater(test, lefts, 0);
    
    std::cout << "The amount of trapped water after it rains: " << countWater(range, lefts, 0) << "\n";
}

std::vector<int> createElevationMap() {
    // generate elevation data
    std::mt19937 generator{ std::random_device{}() };
    std::exponential_distribution<> elevationDist{ 0.5 };
    auto elevationCreator = [&generator, &elevationDist]() { 
        return static_cast<int>(elevationDist(generator));
    };
    auto elevationMap = randomVectorOfObjects<int, decltype(elevationCreator)>(elevationCreator);

    // ensure there is only one highest peak
    auto firstMaxPeakIt = std::max_element(elevationMap.begin(), elevationMap.end());
    *firstMaxPeakIt += 1;

    return elevationMap;
}
