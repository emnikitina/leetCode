#include <string>
#include <iostream>

using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int bottles = numBottles;
        int exchBottles = numBottles / numExchange;
 
        while (exchBottles >= 1) {
            bottles += exchBottles;
            numBottles = (numBottles % numExchange) + exchBottles;
            exchBottles = numBottles / numExchange;
        }
        return bottles;
};

int main(int argc, char** argv) {
    if (argc == 3)
        cout << "result: " << numWaterBottles(stoi(argv[1]), stoi(argv[2])) << endl;
    return 0;
}