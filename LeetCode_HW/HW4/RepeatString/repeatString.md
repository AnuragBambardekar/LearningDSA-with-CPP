# Repeat String
## Problem Description
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".
 
**Example 1:** <br>
Input: a = "abcd", b = "cdabcdab" <br>
Output: 3 <br>
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it. <br>

**Example 2:** <br>
Input: a = "a", b = "aa" <br>
Output: 2 <br>

 
**Constraints:**
●	1 <= a.length, b.length <= 104
●	a and b consist of lowercase English letters.

```
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
    }
};
```