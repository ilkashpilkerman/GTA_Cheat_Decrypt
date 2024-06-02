#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> movement_table = {3, 5, 7, 1, 13, 27, 3, 7, 1, 11, 13, 8, 7, 32, 13, 6, 28, 19, 10, 3, 3, 5, 7, 1, 13, 27, 3, 7};

std::string encrypt(const std::string &code, const std::vector<int> &movement_table) {
    std::string reversed_code = code;
    std::reverse(reversed_code.begin(), reversed_code.end());
    
    std::string encrypted_chars(reversed_code.size(), ' ');
    for (size_t i = 0; i < reversed_code.size(); ++i) {
        int shift = movement_table[i % movement_table.size()];
        encrypted_chars[i] = static_cast<char>((static_cast<int>(reversed_code[i]) + shift) % 256);
    }
    return encrypted_chars;
}

int main() {
    std::string code;
    std::cout << "Enter the cheat code: ";
    std::cin >> code;
    std::string encrypted_code = encrypt(code, movement_table);
    std::cout << "Encrypted code: " << encrypted_code << std::endl;
    return 0;
}