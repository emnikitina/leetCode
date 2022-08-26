#include <string>
#include <vector>
#include <iostream>

bool checkZero(int x) {
    std::string str = std::to_string(x);
    if (str.find_first_of("0") != std::string::npos)
        return false;
    return true;
};    
    
std::vector<int> getNoZeroIntegers(int n) {
    std::vector<int> couple;
    int a = 1, b = n - a;

    std::cout << "check a: " << checkZero(a) << std::endl;
    std::cout << "check b: " << checkZero(b) << std::endl; 
    while (!checkZero(a) || !checkZero(b)) {

        a++;
        b = n - a;
        std::cout << "new a: " << a << " new b: " << b << std::endl;
    }
    
    couple.push_back(a);
    couple.push_back(b);
    return couple;
};


int main (int argc, char** argv) {
    if (argc == 2)
        getNoZeroIntegers(std::stoi(argv[1]));
    return 0;
}