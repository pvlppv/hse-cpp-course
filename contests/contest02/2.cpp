#include <iostream>

std::string check_palindrome(std::string palindrome) {
    std::string newPalindrome;
    for (int i = 0; i < palindrome.length(); ++i) {
        if (std::isspace(palindrome[i]) == false) newPalindrome += palindrome[i];
    }

    for (int i = 0; i < newPalindrome.length(); ++i) {
        int start = i;
        int end = newPalindrome.length() - 1 - i;
        if (newPalindrome[start] != newPalindrome[end]) {
            return "no";
        };
    }

    return "yes";
}

int main() {
    std::string palindrome;
    std::getline(std::cin, palindrome);
    
    std::cout << check_palindrome(palindrome) << std::endl;

    return 0;
}