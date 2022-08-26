#include <string>
#include <iostream>

using namespace std;

bool rotateString(string s, string goal) {
    if (s.length() == goal.length()) {
        for (size_t i = 0; i < goal.length(); i++)
            if (goal == (s.substr(i) + s.substr(0, i)))
                return true;
    }
    return false;        
};

int main(int argc, char** argv) {
    if (argc == 3)
        cout << "result: " << rotateString(argv[1], argv[2]) << endl;
    return 0;
}