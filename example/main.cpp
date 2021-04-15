#include <iostream>
#include <vector>
#include "../src/string.h"
#include "../src/vector.h"
#include "../src/collection.h"
#include "../src/avec.h"

struct p {
};


int main() {

    ftl::collection<int> collection = {15};
    collection.append(10);
    std::cout << "collection: " << collection[0] << std::endl;
    collection.remove(15);
    std::cout << "collection: " << collection[0] << std::endl;

    ftl::collection<p> m = {};

    ftl::vector<float> vec = {10.1f, 20.2f};
    vec.clone().for_each([&](auto &e) {
        e += 1.f;
        std::cout << "Element: " << e << std::endl;
    });

    ftl::string b = "TEST";
    ftl::string str = "te";

    ftl::string c = b + str;
    std::cout << c.length() << std::endl;
    std::cout << c.data() << std::endl;
    std::cout << c[0] << std::endl;

    ftl::vector<int> numbers = {1, 2, 3, 4, 10, 20, 30};

    const auto filtered_numbers = numbers.stream()
            .compute_if(
                    [](const auto &number) { return number <= 10; },
                    [](const auto &number) { std::cout << number << " Will be removed" << std::endl; }
            )
            .filter([](const auto &number) {
                return number > 10;
            })
            .collect<decltype(numbers)>();

    const auto outliers = numbers.stream()
            .filter([](const auto &number) { return number < 4 || number > 10; })
            .count();

    std::cout << "Filtered: " << filtered_numbers.size() << std::endl;
    std::cout << "Outliers: " << outliers << std::endl;

    ftl::avec<int, 3> avec = {10, 20, 30};
    ftl::avec<int, 3> avec2 = {20, 30, 40};
    std::cout << "Dist: " << avec.distance(avec2) << std::endl;

    const auto newvec = ftl::vector<int>::comprehend(
            numbers.begin(),
            numbers.end(),
            [](const auto &e) { return e >= 3; }
    );
    std::cout << newvec.get(0) << std::endl;

    ftl::string s1 = "hlloe";
    s1 << "goodbye";

    std::cout << s1.data() << std::endl;
    return 0;
}
