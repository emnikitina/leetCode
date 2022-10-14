#include <iostream>

int main() {
    int n;
    bool* primes;

    std::cout << "Please, input n:\n";
    std::cin >> n;
    primes = new bool[n + 1];
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i <= n; i++)
        primes[i] = true;
    for (int i = 0; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i)
                primes[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (primes[i])
            std::cout << i << " ";
    }
    delete[] primes;
    return 0;
}