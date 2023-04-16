# Count Of Range Sums
## Problem Description
Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.

Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.
 
**Example 1:** <br>
Input: nums = [-2,5,-1], lower = -2, upper = 2 <br>
Output: 3 <br>
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2. <br>

**Example 2:** <br>
Input: nums = [0], lower = 0, upper = 0 <br>
Output: 1 <br>

 
**Constraints:** <br>
●	1 <= nums.length <= 105 <br>
●	-231 <= nums[i] <= 231 - 1 <br>
●	-105 <= lower <= upper <= 105 <br>
●	The answer is guaranteed to fit in a 32-bit integer. <br>

```
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
    }
};
```