#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

template <typename T>
class Tag {
public:
    Tag(bool isTagged, T value) : _tagged{ isTagged }, _value{ value } {}

    bool isTagged() const { return _tagged; }
    T item() const { return _value; }

private:
    bool _tagged;
    T _value;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Tag<T>& tag) {
    out << "TAG: tagged(" << (tag.isTagged() ? "true" : "false") << "), item(" << tag.item() << ")";
    return out;
}

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    std::vector<Tag<Car>> taggedCars;
    // TODO: populate 'taggedCars' with elements of type Tag<Car> where the tag is set to true
    //  only if the price < 10,000 or if the vin starts with a letter in A...F

    auto pop = [&taggedCars](Car car){
        if (car.price() < 10000 || (car.vin()[0] >= 'A' && car.vin()[0] <= 'F')) {
            taggedCars.push_back(Tag<Car>{true, car});
        } else {
            taggedCars.push_back(Tag<Car>{false, car});
        }
    };
    std::for_each(cars.begin(), cars.end(), pop);
    
    // TODO: arrange `taggedCars` so that the elements tagged `true` are at the beginning
    //  and `false` elements are at the ened
    std::partition(taggedCars.begin(), taggedCars.end(), [](const Tag<Car>& tagged){return tagged.isTagged();});
    std::cout << "Tagged Cars: " << taggedCars << "\n";
}
