#include <iostream>

int main() {
    int hexAsDecimal, octalAsDecimal;
    std::cout << "Enter two space-separated positive integer numeric values. The first must be in hexadecimal while the second must be in octal.  Do not precede the values with 0x or 0" << std::endl;
    std::cin >> std::hex >> hexAsDecimal;
    std::cin >> std::oct >> octalAsDecimal;

    
    std::cout 
        << "   H " << std::hex << hexAsDecimal 
        << " = O " << std::oct << hexAsDecimal 
        << " = D " << std::dec << hexAsDecimal
        << std::endl
        
        << "   H " << std::hex << octalAsDecimal 
        << " = O " << std::oct << octalAsDecimal 
        << " = D " << std::dec << octalAsDecimal
        << std::endl;

    return 0;
}
