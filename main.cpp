#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <map>

#include "util.h"

void testToString();

void e23_1();
void e23_2();

int main(int argc, const char** argv) {
    std::map<std::string, std::function<void()>> functions = {
        {"toString", testToString},
        {"e23_1", e23_1},
        {"e23_2", e23_2},
    };

    if (argc < 2) {
        std::cout << "Available functions to run:" << std::endl;

        for (auto pair = functions.cbegin(); pair != functions.cend(); ++pair) {
            std::cout << pair->first << std::endl;
        }
    } else if (argc == 2) {
        auto func = functions.find(argv[1]);

        if (func != functions.cend()) {
            func->second();
        } else {
            std::cout << "Invalid function name: '" << argv[1] << "'" << std::endl;
            std::cout << "Run test without args for available functions." << std::endl;
        }
    } else {
        std::cout << "Invalid arguments: expecting one function name to run.\n"
                     "Run test without args for available functions." << std::endl;
    }

    return 0;
}

void testToString() {
    std::vector<int> nums = {1, 2, 4, 6, 8, 100};

    std::cout << "nums: {" << Util::toString(nums) << "}" << std::endl;
}

struct insensitiveCompare {
    bool operator ()(const std::string& a, const std::string& b) {
        std::string aCopy(a);
        std::string bCopy(b);

        std::transform(a.cbegin(), a.cend(), aCopy.begin(), tolower);
        std::transform(b.cbegin(), b.cend(), bCopy.begin(), tolower);

        return aCopy < bCopy;
    }
};

void e23_1() {
    // TASK: write a binary predicate for case-insensitive string comparison
    std::list<std::string> names = {
        "Judy",
        "Jamal",
        "james",
        "jordan",
        "jimmy",
        "amy",
        "Anne"
    };

    std::cout << "List of names before sort:\n{" << Util::toString(names) << "}" << std::endl;

    names.sort(insensitiveCompare());

    std::cout << "List of names after (case-insensitive) sort:\n{"
              << Util::toString(names) << "}" << std::endl;
}

void e23_2() {
    // TASK: demonstrate how STL containers use iterators as their bridge by
    // copying elements between two dissimilar containers
    std::list<std::string> nameList = { "Bob", "Anne", "Sigmound", "Persephone", "Shira"};

    std::deque<std::string> nameDeque(nameList.size());

    std::copy(nameList.begin(), nameList.end(), nameDeque.begin());

    std::cout << "List: {" << Util::toString(nameList) << "}" << std::endl;
    std::cout << "Set (copied from list): {" << Util::toString(nameDeque) << "}" << std::endl;
}

