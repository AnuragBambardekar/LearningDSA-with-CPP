# Good Array
Given an array nums of positive integers. Your task is to select some subset of nums, multiply each element by an integer and add all these numbers. The array is said to be good if you can obtain a sum of 1 from the array by any possible subset and multiplicand. <br>

Return True if the array is good otherwise return False. <br>

**Example 1:** <br>

Input: nums = [12,5,7,23] <br>
Output: true <br>
Explanation: Pick numbers 5 and 7. <br>
5*3 + 7*(-2) = 1 <br>

**Example 2:** <br>

Input: nums = [29,6,10] <br>
Output: true <br>
Explanation: Pick numbers 29, 6 and 10. <br>
29*1 + 6*(-3) + 10*(-1) = 1 <br>

**Example 3:** <br>

Input: nums = [3,6] <br>
Output: false <br>
 

**Constraints:** <br>

1 <= nums.length <= 10^5 <br>
1 <= nums[i] <= 10^9 <br>
