#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    int gcd(int a,int b){
        if(b == 0)return a;
        return gcd(b, a % b);
    }
    int getMax(vector<int>&nums, int mask, int k){
        if(mask == 0)return 0;
       
        int ans = 0;

        /**
         * We use bit manipulation to represent the mask of available elements. 
         * We start with a mask of all ones (i.e., all elements are available), and we use the bitwise OR operator to combine the 
         * masks of the pairs of elements we choose in each operation. 
         * We can then use the bitwise XOR operator to remove these pairs from the mask and get the mask of remaining elements.
        */
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int nmask = 1<<i | 1<<j;
                int temp = 0;
                if((mask & nmask) == nmask){
                    temp = k * gcd(nums[i],nums[j]) + getMax(nums, mask ^ nmask, k + 1);
                   }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int mask = pow(2, n)- 1;
        
        return getMax(nums, mask, 1);
    }
};


int main() {
    Solution s;
    vector<int> nums1 = {1, 2};
    cout << s.maxScore(nums1) << endl; // Output: 1

    vector<int> nums2 = {3, 4, 6, 8};
    cout << s.maxScore(nums2) << endl; // Output: 11

    vector<int> nums3 = {1, 2, 3, 4, 5, 6};
    cout << s.maxScore(nums3) << endl; // Output: 14

    return 0;
}

