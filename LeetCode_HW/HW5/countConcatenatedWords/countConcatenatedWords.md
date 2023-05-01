# Find Concatenated Words
Given an array of strings words (without duplicates), return all the concatenated words in the given list of words. <br>
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array. <br>
 
**Example 1:** <br>
Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"] <br>
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"] <br>
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";  <br>
"dogcatsdog" can be concatenated by "dog", "cats" and "dog";  <br>
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat". <br>

**Example 2:** <br>
Input: words = ["cat","dog","catdog"] <br>
Output: ["catdog"] <br>

 
**Constraints:** <br>
●	1 <= words.length <= 104 <br>
●	0 <= words[i].length <= 30 <br>
●	words[i] consists of only lowercase English letters. <br>
●	0 <= sum(words[i].length) <= 105 <br>

```
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
    }
};
```