#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Time Complexity: O(nlogn)
/**
 * Sorting the array takes O(n log n) time. The while loop runs in O(n) time in the worst case because it either increases the value of s 
 * or decreases the value of e in each iteration, so it runs n times at most. 
 * Therefore, the total time complexity is O(n log n).
*/

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            int n=nums.size();
            vector<pair<int,int>> v;
            for(int i=0; i<n; i++)
            {
                v.push_back({nums[i],i});       
            }
            
            sort(v.begin(), v.end());
            int s=0,e=n-1;
            /* while(s<n)
            {
                cout<<v[s].first<<" "<<endl;
                s++;
                if(s==n)
                    break;
            } */
            while(s<e)
            {
                //Two Pointer method
                int sum = v[s].first+v[e].first; //first is holding the value
                if(sum == target)
                {
                    return {v[s].second, v[e].second}; //second is storing the index
                }
                else if(sum>target)
                {
                    e--;
                }
                else
                {
                    s++;
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
