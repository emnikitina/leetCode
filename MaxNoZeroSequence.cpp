#include <iostream>
#include <vector>

int main() {
    int n, len = 0, max = 0;
    int* sequence;
    std::vector<int> zeros;

    std::cout << "Please, input sequence size:\n";
    std::cin >> n;
    sequence = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
        if (i && sequence[i - 1] == sequence[i])
            len++;
        else {
            if (len)
                zeros.push_back(len);
            len = 1;
        }
    }
    zeros.push_back(len);
    for (size_t i = sequence[0]; i < zeros.size(); i += 2) {
        if (zeros[i] == 1)
            max = std::max(max, zeros[i - 1] + zeros[i + 1]);
    }
    std::cout << max << std::endl;
    delete[] sequence;
    return 0;
}