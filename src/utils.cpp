#include <string_view>

#include <utils.hpp>

bool Utils::startsWith(std::string_view main, std::string_view sub) {
    // Loop through the entire sub string from the start
    for (std::string_view::iterator i = sub.begin(), j = main.begin(); i != sub.end(); i++, j++) {
        if (*i != *j) {
            return false;
        }
    }
    
    return true;
}