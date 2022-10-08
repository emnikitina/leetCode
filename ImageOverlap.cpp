#include <iostream>
#include <vector>

int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int overlap = 0;

        for (size_t i = 0; i < img1.size(); i++) {
            for (size_t j = 0; j < img1[i].size(); j++) {
                std::cout << "im1: " << img1[i][j] << " im2: " << img2[i][j] << std::endl;
                if (img1[i][j] == 1 && img2[i][j] == 1)
                    overlap++;
            }
        }
        return overlap;
    }

int main(/*int argc, char** argv*/) {
    std::vector<std::vector<int>> img1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    std::vector<std::vector<int>> img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};

    std::cout << largestOverlap(img1, img2) << std::endl;
    
    return 0;
}