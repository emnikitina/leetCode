#include <iostream>
#include <string>

using namespace std;

string capitalizeTitle(string title) {
    size_t len = 0;
    size_t size = title.size();
    for (size_t i = 0; i < size; i++) {
        title[i] = std::tolower(title[i]);
        if (title[i] == ' ') {
            if (len > 2)
                title[i - len] = std::toupper(title[i - len]);
            len = 0;
        }
        else if (i == size - 1) {
            if (len > 1)
                title[i - len] = std::toupper(title[i - len]);
            len = 0;
        }
        else
            len++;
    }
    return title;
};

int main(int argc, char** argv) {
    for (int i = 1; i <= argc; i++)
        cout << capitalizeTitle(argv[i]) << endl;
    return 0;
}