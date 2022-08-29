#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkZeroOnes(string s) {
    size_t zero = 0, one = 0, max0 = 0, max1 = 0, size = s.size();
    
    for (size_t i = 0; i < size;) {
        while (s[i] == '1') {
            one++;
            i++;
        }
        max1 = (one > max1) ? one : max1;
        one = 0;
        if (i >= size)
            break ;
        while (s[i] == '0') {
            zero++;
            i++;
        }
        max0 = (zero > max0) ? zero : max0;
        zero = 0;
        if (i >= size)
            break ;
    }
    return (max1 > max0) ? true : false;
};

int main(int argc, char** argv) {
    vector<int> gain;
    if (argc == 2)
        cout << "check Zero Ones: " << checkZeroOnes(argv[1]) << endl;
    return 0;
}