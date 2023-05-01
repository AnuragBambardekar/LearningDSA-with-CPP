#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class FreqStack {
public:
    FreqStack() {
        max_freq = 0;
        stacks.push_back(stack<int>());
    }
    
    void push(int val) {
        freq[val]++;
        int f = freq[val];
        if (f > max_freq) {
            max_freq = f;
            stacks.push_back(stack<int>());
        }
        stacks[f].push(val);
    }
    
    int pop() {
        int val = stacks[max_freq].top();
        stacks[max_freq].pop();
        freq[val]--;
        if (stacks[max_freq].empty()) {
            max_freq--;
            stacks.pop_back();
        }
        return val;
    }
    
private:
    int max_freq;
    std::unordered_map<int, int> freq;
    std::vector<std::stack<int>> stacks;
};

int main()
{
    FreqStack* obj = new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);
    std::cout << obj->pop() << std::endl; // Output: 5
    std::cout << obj->pop() << std::endl; // Output: 7
    std::cout << obj->pop() << std::endl; // Output: 5
    std::cout << obj->pop() << std::endl; // Output: 4
    return 0;
}
