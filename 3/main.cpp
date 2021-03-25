#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    // TODO: print the average price and price range
    std::cout << "The average price is: $" << (std::accumulate(cars.begin(), cars.end(), 0.0, [](double currentTotal, const Car& car) {return car.price() + currentTotal;})/cars.size()) << "\n";
    
    auto comp = [](const Car& c1, const Car& c2) { return (c1.price() < c2.price());};
    auto max = std::max_element(cars.begin(), cars.end(), comp);
    auto min = std::min_element(cars.begin(), cars.end(), comp);
    std::cout << "The range is: $" << (max->price() - min->price()) << "\n";
}
