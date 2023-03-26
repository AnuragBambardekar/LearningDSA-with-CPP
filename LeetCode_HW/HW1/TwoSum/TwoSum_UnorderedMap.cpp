#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time Complexity = O(n)
/**
 * The for loop runs n times, and looking up an element in a hash map (unordered_map in C++), on average, takes O(1) time. 
 * So the total time complexity is O(n). This is a significant improvement over the previous solution, 
 * which had a time complexity of O(n^2).
*/

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            //UnorderedMap Method
            int n=nums.size();
            unordered_map<int,int> m;

            for(int i=0; i<n; i++)
            {
                int x=nums[i];
                int y=target-x;
                if(m.find(y)!=m.end())
                {
                    return {i,m[y]};
                }
                m[nums[i]]=i;
            }
            return {-1,-1};


            /* vector<int> indices(2); //to be returned (2 numbers that sum up to target)
            unordered_map<int,int> visitedElements;

            for(int i=0; i<nums.size(); i++)
            {
                int currElem = nums[i];
                int numToFind = target - currElem;

                //check if numToFind in map or not
                if(visitedElements.count(numToFind))
                {
                    indices[0] = visitedElements[numToFind]; //store the index
                    indices[1] = i;
                    return indices;
                }

                visitedElements[currElem] = i;
            }
            return {-1,-1};  */
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
