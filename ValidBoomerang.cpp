#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isBoomerang(vector<vector<int>>& points) {
    if (points[0] == points[1] || points[1] == points[2] || points[2] == points[0])
        return false;

    if (points[1][0] == points[0][0]) {
        if (points[2][0] == points[0][0])
            return false;
    }
    else if (points[1][1] == points[0][1]) {
        if (points[2][1] == points[0][1])
            return false;
    }
    else if ((float(points[2][0] - points[0][0]) / float(points[1][0] - points[0][0])) == (float(points[2][1] - points[0][1]) / float(points[1][1] - points[0][1])))
        return false;
    return true;
};

int main(int argc, char** argv) {
    vector<vector<int>> points;
    vector<int> p1, p2, p3;
    if (argc == 7) {
        p1.push_back(atoi(argv[1]));
        p1.push_back(atoi(argv[2]));
        p2.push_back(atoi(argv[3]));
        p2.push_back(atoi(argv[4]));
        p3.push_back(atoi(argv[5]));
        p3.push_back(atoi(argv[6]));
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        cout << "num is happy: " << isBoomerang(points) << endl;
    }
    return 0;
}