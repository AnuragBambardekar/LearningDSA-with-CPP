#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int findGCD(int a, int b) {
    if (a == 0) {
        return b;
    }
    return findGCD(b % a, a);
}

int findGCDofMinMax(std::vector<int>& nums) {
    int minNum = nums[0];
    int maxNum = nums[0];
    for (int num : nums) {
        if (num < minNum) {
            minNum = num;
        }
        if (num > maxNum) {
            maxNum = num;
        }
    }
    return findGCD(minNum, maxNum);
}

int main() {
    std::vector<int> nums = {2, 5, 6, 9, 10};
    int gcd = findGCDofMinMax(nums);
    std::cout << "The greatest common divisor of the smallest and largest numbers in nums is: " << gcd << std::endl;

    nums = {7, 5, 6, 8, 3};
    gcd = findGCDofMinMax(nums);
    std::cout << "The greatest common divisor of the smallest and largest numbers in nums is: " << gcd << std::endl;

    nums = {3, 3};
    gcd = findGCDofMinMax(nums);
    std::cout << "The greatest common divisor of the smallest and largest numbers in nums is: " << gcd << std::endl;

    return 0;
}


