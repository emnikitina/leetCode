#include <iostream>
#include <vector>


char nextGreatestLetter(std::vector<char>& letters, char target) {
    int r = letters.size() - 1, l = 0, m;

    while (l < r) {
        m = (l + r) / 2;
        if (letters[m] > target)
            r = m;
        else
            l = m + 1;
    }
    return ((letters[r] > target) ? letters[r] : letters[0]);
}

int main(/*int argc, char** argv*/) {
    std::vector<char> letters = {'x', 'x', 'y', 'y'};
    char target = 'z';

    std::cout << nextGreatestLetter(letters, target) << std::endl;
    return 0;
}