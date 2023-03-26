#include <iostream>
#include <vector>
using namespace std;

// Time Complexity = O(n^2)
/**
 * The time complexity of this program is O(n^2) or quadratic. The outer loop runs n times, and the inner loop runs n-1, n-2, n-3, ..., 1 
 * times in each iteration. 
 * So the total number of iterations is n + (n-1) + (n-2) + ... + 1 = n(n+1)/2. As a result, the time complexity is O(n^2).
*/

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            //Bruteforce Method
            int n=nums.size();
            for(int i=0; i<n; i++)
            {
                for(int j=i+1; j<n; j++)
                {
                    if(nums[i]+nums[j]==target)
                    {
                        return {i,j};
                    }
                }
            }
            return {-1,-1};
        }
};

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    cout << "Indices of the two elements that add up to target: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
