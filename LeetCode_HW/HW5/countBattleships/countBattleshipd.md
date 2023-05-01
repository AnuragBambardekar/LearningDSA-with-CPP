# Count Battleships
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board. <br>

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships). <br>
 
**Example 1:** <br>
 
Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]] <br>
Output: 2 <br>

**Example 2:** <br>
Input: board = [["."]] <br>
Output: 0 <br>

 
**Constraints:** <br>
●	m == board.length <br>
●	n == board[i].length <br>
●	1 <= m, n <= 200 <br>
●	board[i][j] is either '.' or 'X'. <br>
 
Follow up: Could you do it in one-pass, using only O(1) extra memory and without modifying the values board? <br>

```
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
    }
};
```