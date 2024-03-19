#include <iostream>

std::string check_password(std::string password) {
    int countIsupper = 0, countIslower = 0, countIsdigit = 0, countIspunct = 0;
    
    if (8 <= password.length() && password.length() <= 14) {
    for (size_t i = 0; i < password.length(); ++i) {
        char c = password[i];            
        if (c < 127) {
                if (std::isupper(c)) countIsupper++;
                else if (std::islower(c)) countIslower++;
                else if (std::isdigit(c)) countIsdigit++;
                else if (std::ispunct(c)) countIspunct++;
            }
        }
    }
    
    int count_conditions = 0;
    if (countIsupper > 0) count_conditions++;
    if (countIslower > 0) count_conditions++;
    if (countIsdigit > 0) count_conditions++;
    if (countIspunct > 0) count_conditions++;
        
    if (count_conditions >= 3) return "YES";
    else return "NO";
}

int main() {
    std::string password;
    std::cin >> password;

    std::cout << check_password(password) << std::endl;

    return 0;
}