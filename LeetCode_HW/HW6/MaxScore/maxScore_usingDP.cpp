#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
    int gcd(int a,int b){
        if(b == 0)return a;
        return gcd(b, a % b);
    }
    int getMax(vector<int>&nums, int mask, int k, unordered_map<int, int>& memo){
        if(mask == 0)return 0;
        if(memo.count(mask)) return memo[mask];
       
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int nmask = 1<<i | 1<<j;
                int temp = 0;
                if((mask & nmask) == nmask){
                    temp = k * gcd(nums[i],nums[j]) + getMax(nums, mask ^ nmask, k + 1, memo);
                }
                ans = max(ans, temp);
            }
        }
        memo[mask] = ans;
        return ans;
    }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int mask = pow(2, n)- 1;
        unordered_map<int, int> memo;
        return getMax(nums, mask, 1, memo);
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
