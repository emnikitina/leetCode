#include <iostream>
#include <unordered_set>

int main() {
    int n, maxX, minX, maxY, minY;
    double axis;
    int* points;
    std::unordered_set yPoints;

    std::cout << "Please, input number of points: \n";
    std::cin >> n;
    points = new int[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> points[i];
        if (i == 0) {
            maxX = points[i];
            minX = points[i];
        }
        else if (i == 1) {
            maxY = points[i];
            minY = points[i];
        }
        if (i % 2) {
            maxY = std::max(maxY, points[i]);
            minY = std::min(minY, points[i]);
            yPoints.insert(points[i]);
        }
        else {
            maxX = std::max(maxX, points[i]);
            minX = std::min(minX, points[i]);
        }
    }
    axis = double(minX) / 2 + double(maxX) / 2;
    for (int i = 0; i < 2 * n; i++) {
        
    }
    

    delete[] points;
    return 0;
}