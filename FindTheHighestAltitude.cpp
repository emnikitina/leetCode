#include <iostream>
#include <string>
#include <vector>

using namespace std;

int largestAltitude(vector<int>& gain) {
    int maxHigh = 0;
    int high = 0;
    size_t size = gain.size();
    
    for (size_t i = 0; i < size; i++) {
        high += gain[i];
        maxHigh = max(high, maxHigh);
    }
    return maxHigh;
};

int main(int argc, char** argv) {
    vector<int> gain;
    for (size_t i = 0; i < argc; i++)
        gain.push_back(atoi(argv[i]));
    cout << "largest altitude: " << largestAltitude(gain) << endl;
    return 0;
}