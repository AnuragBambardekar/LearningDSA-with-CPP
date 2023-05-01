# Minimum Deletions
You are given a string s consisting only of characters 'a' and 'b'. <br>
You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'. <br>
Return the minimum number of deletions needed to make s balanced. <br>
 
**Example 1:** <br>
Input: s = "aababbab" <br>
Output: 2 <br>
Explanation: You can either: <br>
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or <br>
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb"). <br>

**Example 2:** <br>
Input: s = "bbaaaaabb" <br>
Output: 2 <br>
Explanation: The only solution is to delete the first two characters. <br>

 
**Constraints:** <br>
●	1 <= s.length <= 105 <br>
●	s[i] is 'a' or 'b'. <br>

```
class Solution {
public:
    int minimumDeletions(string s) {
        
    }
};
```