#include <iostream>
#include <vector>
#include <algorithm>

void comb(std::vector<int>* combinations, std::vector<int> nums, int N, int K)
{
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do {
        for (size_t i = 0; i < nums.size(); ++i) // [0..N-1] integers
		{
            if (bitmask[i])
				combinations->push_back(nums[i]);
        }
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
	std::vector<std::vector<int> > combinations(nums.size() + 1);

	for (size_t i = 0; i <= nums.size(); i++) {
		combinations[i] = std::vector<int>();
        if (i > 1)
			comb(&combinations[i], nums, nums.size(), i);
    }

	/* for (size_t i = 0; i < combinations.size(); i++) {
		for (size_t j = 0; j < combinations[i].size(); j++) {
			if (!(j % i))
				std::cout << std::endl;
			std::cout << combinations[i][j] << " ";
		}
		std::cout << std::endl;
	} */
	
	return combinations;
}

int main() {
    std::vector<int> candidates = {16,17,71,62,12,24,14};
	std::vector<std::vector<int> > combinations;
	int res = 0, ans = 0;
    
	if (candidates.size() == 1)
		std::cout << candidates[0] << std::endl;
    combinations = getCombinations(candidates);
	for (size_t i = 2; i < combinations.size(); i++) {
		res = 0;
		for (size_t j = 0; j < combinations[i].size(); j++) {
			if (!(j % i)) {
				// if (res)
				// 	std::cout << "res: " << res << " i: " << i << std::endl;
				if (res > 0)
                	ans = i;
				res = combinations[i][j];
			}
			res = res & combinations[i][j];
		}
		if (res > 0)
			ans = i;
		//std::cout << std::endl;
	}
	std::cout << ans << std::endl;
    return 0;
}