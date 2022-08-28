#include <iostream>
#include <string>
#include <set>
#include <cmath>

using namespace std;

bool isHappy(int n) {
    int capacity[10];
    set<long> res;

    while (n != 1) {
        for (int i = 9; i >= 0; i--) {
            capacity[i] = n % 10;
            n /= 10;
        }
        n = 0;
        for (size_t i = 0; i < 10; i++)
            n += pow(capacity[i], 2);
        if (!res.insert(n).second)
            return false;
    }
    return true;
};

int main(int argc, char** argv) {
    if (argc == 2)
        cout << "num is happy: " << isHappy(atoi(argv[1])) << endl;
    return 0;
}