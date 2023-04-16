# Longest prefix
## Problem Description
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
 
**Example 1:** <br>
Input: s = "level" <br>
Output: "l" <br>
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l". <br>

**Example 2:** <br>
Input: s = "ababab" <br>
Output: "abab" <br>
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string. <br>

 
**Constraints:** <br>
●	1 <= s.length <= 105 <br>
●	s contains only lowercase English letters. <br>

```
class Solution {
public:
    string longestPrefix(string s) {
        
    }
};
```