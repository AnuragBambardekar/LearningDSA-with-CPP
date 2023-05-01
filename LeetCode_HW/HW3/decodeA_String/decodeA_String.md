# P9 - Decode An Encoded String
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
 
**Example 1:** <br>
Input: s = "3[a]2[bc]" <br>
Output: "aaabcbc" <br>

**Example 2:** <br>
Input: s = "3[a2[c]]" <br>
Output: "accaccacc" <br>

**Example 3:** <br>
Input: s = "2[abc]3[cd]ef" <br>
Output: "abcabccdcdcdef" <br>

 
**Constraints:** <br>
●	1 <= s.length <= 30 <br>
●	s consists of lowercase English letters, digits, and square brackets '[]'. <br>
●	s is guaranteed to be a valid input. <br>
●	All the integers in s are in the range [1, 300]. <br>

```
class Solution {
public:
    string decodeString(string s) {
        
    }
};
```