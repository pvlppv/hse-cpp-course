#include <vector>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> v;
    
    int i = 0;
    std::string s = "";
    while (i != str.size()) {
        if (str[i] == delimiter) {
            v.push_back(s);
            s = "";
        }
        else {
            s += str[i];
        }
        i++;
    }

    if (i == str.size()) {
        v.push_back(s);
    }

    return v;
}