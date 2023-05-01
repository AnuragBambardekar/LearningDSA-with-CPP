# freqStack
Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack. <br>
Implement the FreqStack class: <br>
●	FreqStack() constructs an empty frequency stack. <br>
●	void push(int val) pushes an integer val onto the top of the stack. <br>
●	int pop() removes and returns the most frequent element in the stack. <br>
○	If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned. <br>
 
**Example 1:** <br>
Input <br>
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"] <br>
[[], [5], [7], [5], [7], [4], [5], [], [], [], []] <br>
Output <br>
[null, null, null, null, null, null, null, 5, 7, 5, 4] <br>

Explanation <br>
FreqStack freqStack = new FreqStack(); <br>
freqStack.push(5); // The stack is [5] <br>
freqStack.push(7); // The stack is [5,7] <br>
freqStack.push(5); // The stack is [5,7,5] <br>
freqStack.push(7); // The stack is [5,7,5,7] <br>
freqStack.push(4); // The stack is [5,7,5,7,4] <br>
freqStack.push(5); // The stack is [5,7,5,7,4,5] <br>
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4]. <br>
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4]. <br>
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4]. <br>
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7]. <br>

 
**Constraints:** <br>
●	0 <= val <= 109 <br>
●	At most 2 * 104 calls will be made to push and pop. <br>
●	It is guaranteed that there will be at least one element in the stack before calling pop. <br>
```
class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        
    }
    
    int pop() {
        
    }
};
```
```
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
```