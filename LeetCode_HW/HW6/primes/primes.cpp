#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> prime(n + 1, true);
		prime[0] = false;
		prime[1] = false;
		for (int i = 2; i * i <= n; i++) {
			if (prime[i]) {
				for (int j = i * i; j <= n; j += i) {
					prime[j] = false;
				}
			}
		}
		//counting prime numbers
		int primeCount = 0;
		for (int i = 2; i < n; i++) {
			if (prime[i]) {
				primeCount++;
			}
		}
		return primeCount;
	}
};

int main() {
    Solution s;
    std::cout << "Number of primes less than 20: " << s.countPrimes(20) << std::endl;
    std::cout << "Number of primes less than 10: " << s.countPrimes(10) << std::endl;
    std::cout << "Number of primes less than 0: " << s.countPrimes(0) << std::endl;
    return 0;
}