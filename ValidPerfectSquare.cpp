#include <iostream>

bool isPerfectSquare(int num) {
    long l = 0, r = num, m;

    while (l < r) {
        m = (r + l) / 2;
        if (m * m >= num)
            r = m;
        else
            l = m + 1;
    }
    return (r * r == num);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Wrong num of args\n";
        return -1;
    }
    std::cout << std::boolalpha << isPerfectSquare(std::stoi(argv[1])) << std::endl;
    return 0;
}