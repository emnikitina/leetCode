#include <iostream>
#include <vector>
#include <algorithm>

void comb(int N, int K)
{
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
				std::cout << " " << i;
        }
        std::cout << std::endl;
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

bool NextSet(int *a, int n, int k) {
	std::cout << "gere\n";
	for (int i = k - 1; i >= 0; --i) {
		if (a[i] < n - k + i + 1) {
			++a[i];
			for (int j = i + 1; j < k; ++j) {
				a[j] = a[j - 1] + 1;
				// std::cout << a[j];
			}
			//std::cout << std::endl;
			return true;
		}
	}
	return false;
}

void Print(int *a, int n) 
{
	static int num = 1; 
	std::cout.width(3);
	std::cout << num++ << ": ";
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

std::vector<std::vector<int> > getCombinations(std::vector<int> nums) {
	std::vector<std::vector<int> > combinations;

	nums.clear();
    for (size_t i = 1; i <= nums.size(); i++) {
        
    }
	comb(4, 2);
	return combinations;
}

int main() {
    /* std::cout << (16 & 17) << std::endl;
    std::cout << (16 & 71) << std::endl;
    std::cout << (16 & 62) << std::endl;
    std::cout << (17 & 71) << std::endl;
    std::cout << (17 & 62) << std::endl;
    std::cout << (71 & 62) << std::endl;
    std::cout << (16 & 17 & 71) << std::endl;
    std::cout << (16 & 17 & 62) << std::endl;
    std::cout << (16 & 71 & 62) << std::endl;
    std::cout << (17 & 71 & 62) << std::endl;
    std::cout << (16 & 17 & 71 & 62) << std::endl;*/


    std::vector<int> candidates = {16, 17, 71, 62};
	int* a;
	a = new int[4];
	a[0] = 16; 
	a[1] =	17;
	a[2] = 71;
	a[3] = 62;
    std::vector<std::vector<int> > combinations;
    // size_t maxSize = 0;
    // combinations = getCombinations(candidates);
	for (size_t i = 1; i <= 4; i++) {
		while (NextSet(a, 4, i))
			Print(a, i);
	}
	delete[] a;
    return 0;
}