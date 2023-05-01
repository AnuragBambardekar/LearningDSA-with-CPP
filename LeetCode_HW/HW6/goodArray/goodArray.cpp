#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * The reason behind this approach is that if the GCD of all the elements is 1, 
 * then any combination of positive and negative values of the elements can be used to obtain a sum of 1. 
 * This is because any positive integer can be expressed as a linear combination of the GCD and any other positive integer, 
 * and similarly, any negative integer can be expressed as a linear combination of the GCD and any other negative integer. 
 * Therefore, it is possible to obtain a sum of 1 from the array by any possible subset and multiplicand.
 * On the other hand, if the GCD of all the elements is not 1, then it is not possible to obtain a sum of 1 from the array by 
 * any possible subset and multiplicand, because the GCD restricts the possible values that can be obtained by multiplying the 
 * elements by integers.
*/

class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
    
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        for(int i=0; i<n; i++){
            a = gcd(a,nums[i]);
            if(a==1)
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {12,5,7,23};
    cout << boolalpha << s.isGoodArray(nums1) << endl; // Output: true

    vector<int> nums2 = {29,6,10};
    cout << boolalpha << s.isGoodArray(nums2) << endl; // Output: true

    vector<int> nums3 = {3,6};
    cout << boolalpha  << s.isGoodArray(nums3) << endl; // Output: false

    return 0;
}
