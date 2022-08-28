#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool myFind() {

};

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    size_t size = edges.size();
    int sourceIndex = -1;
    for (size_t i = 0; i < size; i++) {
        if (edges[i][0] == source || edges[i][1] == source) {
            sourceIndex = i;
            break ;
        }
    }
    if (sourceIndex != -1) {
        for (size_t i = 0; i < size; i++) {

        }
    }
    return false;
};

int main(int argc, char** argv) {
    vector<vector<int>> edges;
    int n = atoi(argv[1]);
    for (size_t i = 0; i < n; i += 2)
        edges.push_back(atoi(argv[2 + i]));
    cout << "valid path: " << validPath(n, edges, atoi(argv[argc - 1]), atoi(argv[argc - 2])) << endl;
    return 0;
}