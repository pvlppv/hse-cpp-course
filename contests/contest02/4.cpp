#include <iostream>

std::string soundex(std::string word) {
    std::string code = "";
    code += std::tolower(word[0]);
    char previous = std::tolower(word[0]);

    for (int i = 1; i < word.length() && code.length() < 4; i++) {
        char current = std::tolower(word[i]);

        if (current == 'b' || current == 'f' || current == 'p' || current == 'v') {
            if (code.back() != '1')
                code += '1';
        }
        else if (current == 'c' || current == 'g' || current == 'j' || current == 'k' || current == 'q' || current == 's' || current == 'x' || current == 'z') {
            if (code.back() != '2')
                code += '2';
        }
        else if (current == 'd' || current == 't') {
            if (code.back() != '3')
                code += '3';
        }
        else if (current == 'l') {
            if (code.back() != '4')
                code += '4';
        }
        else if (current == 'm' || current == 'n') {
            if (code.back() != '5')
                code += '5';
        }
        else if (current == 'r') {
            if (code.back() != '6')
                code += '6';
        }
    
        previous = current;
    }

    while (code.length() < 4)
        code += '0';

    return code;
}

int main() {
    std::string word;
    std::cin >> word;

    std::cout << soundex(word) << std::endl;


    return 0;
}
