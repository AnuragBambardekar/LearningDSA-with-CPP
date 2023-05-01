# Max Score
You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array. <br>

In the ith operation (1-indexed), you will: <br>

Choose two elements, x and y. <br>
Receive a score of i * gcd(x, y). <br>
Remove x and y from nums. <br>
Return the maximum score you can receive after performing n operations. <br>

The function gcd(x, y) is the greatest common divisor of x and y. <br>

 

**Example 1:** <br>

Input: nums = [1,2] <br>
Output: 1 <br>
Explanation: The optimal choice of operations is: <br>
(1 * gcd(1, 2)) = 1 <br>

**Example 2:** <br>

Input: nums = [3,4,6,8] <br>
Output: 11 <br>
Explanation: The optimal choice of operations is: <br>
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11 <br>

**Example 3:** <br>

Input: nums = [1,2,3,4,5,6] <br>
Output: 14 <br>
Explanation: The optimal choice of operations is: <br>
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14 <br>
 

**Constraints:** <br>

1 <= n <= 7 <br>
nums.length == 2 * n <br>
1 <= nums[i] <= 106 <br>

