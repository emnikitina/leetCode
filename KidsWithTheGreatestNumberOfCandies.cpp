#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int max = *(max_element(candies.begin(), candies.end()));
    size_t size = candies.size();
    vector<bool> res(size);

    for (size_t i = 0; i < size; i++)
        res[i] = ((candies[i] + extraCandies) >= max ? true : false);
    return res; 
};

int main(int argc, char** argv) {
    vector<int> candies;
    vector<bool> res;
    size_t size;
    for (int i = 2; i < argc; i++)
        candies.push_back(atoi(argv[i]));
    res = kidsWithCandies(candies, atoi(argv[1]));
    size = res.size();
    for (size_t i = 0; i < size; i++)
        cout << candies[i] << " ";
    cout << endl;
    for (size_t i = 0; i < size; i++)
        cout << res[i] << " ";
    return 0;
}