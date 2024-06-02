#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> movement_table = {3, 5, 7, 1, 13, 27, 3, 7, 1, 11, 13, 8, 7, 32, 13, 6, 28, 19, 10, 3, 3, 5, 7, 1, 13, 27, 3, 7};

std::string decrypt(const std::string &encrypted_code, const std::vector<int> &movement_table) {
    std::string decrypted_chars(encrypted_code.size(), ' ');
    for (size_t i = 0; i < encrypted_code.size(); ++i) {
        int shift = movement_table[i % movement_table.size()];
        decrypted_chars[i] = static_cast<char>((static_cast<int>(encrypted_code[i]) - shift + 256) % 256);
    }
    std::reverse(decrypted_chars.begin(), decrypted_chars.end());
    return decrypted_chars;
}

int main() {
    std::string encrypted_code; // = "\\JUPZ`PTJR";
    std::cin >> encrypted_code;
    std::string decrypted_code = decrypt(encrypted_code, movement_table);
    std::cout << "Decrypted code: " << decrypted_code << std::endl;
    return 0;
}