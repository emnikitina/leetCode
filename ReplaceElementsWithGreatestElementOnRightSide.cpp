#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    int size = arr.size(), max = arr[size - 1], tmp;
        
    arr[size - 1] = -1;
    for (int i = size - 2; i >= 0; i--) {
        tmp = arr[i];
        arr[i] = max;
        if (tmp > max)
            max = tmp;
    }
    return arr;
};

int main(int argc, char** argv) {
    vector<int> arr;
    size_t size;
    for (int i = 1; i < argc; i++)
        arr.push_back(atoi(argv[i]));
    arr = replaceElements(arr);
    size = arr.size();
    for (size_t i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}