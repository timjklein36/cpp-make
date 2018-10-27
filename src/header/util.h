#ifndef UTIL_H
#define UTIL_H

#include <sstream>
#include <string>
#include <algorithm>

class Util {
    public:
        template<typename T>
        static const std::string toString(const T& container) {
            std::ostringstream stream;

            for (auto iter = container.cbegin(); iter != container.cend(); ++iter) {
                stream << *iter;
                if (iter != --container.cend()) {
                    stream << ", ";
                }
            }

            return stream.str();
        }
};

#endif