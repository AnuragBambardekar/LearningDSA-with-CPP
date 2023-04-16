#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// // This is the interface that allows for creating nested lists.
// // You should not implement it, or speculate about its implementation
// class NestedInteger {
//     public:
//         // Return true if this NestedInteger holds a single integer, rather than a nested list.
//         bool isInteger() const;

//         // Return the single integer that this NestedInteger holds, if it holds a single integer
//         // The result is undefined if this NestedInteger holds a nested list
//         int getInteger() const;

//         // Return the nested list that this NestedInteger holds, if it holds a nested list
//         // The result is undefined if this NestedInteger holds a single integer
//         const vector<NestedInteger> &getList() const;
// };


class NestedInteger {
private:
    int value;
    vector<NestedInteger> list;
    bool isInt;
public:
    NestedInteger(int val) {
        value = val;
        isInt = true;
    }
    
    NestedInteger(vector<NestedInteger> nestedList) {
        list = nestedList;
        isInt = false;
    }
    
    bool isInteger() const {
        return isInt;
    }
    
    int getInteger() const {
        return value;
    }
    
    const vector<NestedInteger>& getList() const {
        return list;
    }
};


class NestedIterator {
    vector<int> output; // create a global output vector
    int i=0;
    public:
        void helper(const vector<NestedInteger> &nestedList)
        {
            for(int i=0; i<nestedList.size();i++)
            {
                if(nestedList[i].isInteger())
                {
                    output.push_back(nestedList[i].getInteger());
                }
                else{
                    //recursion
                    helper(nestedList[i].getList());
                }
            }
        }
        NestedIterator(vector<NestedInteger> &nestedList) {
            helper(nestedList);
        }
        
        int next() {
            int ans = output.at(i);
            i++;
            return ans;
        }
        
        bool hasNext() {
            return i!=output.size();
        }
};

int main() {
    // vector<NestedInteger> nestedList = {NestedInteger({NestedInteger(1), NestedInteger(1)}), NestedInteger(2), NestedInteger({NestedInteger(1), NestedInteger(1)})};
    vector<NestedInteger> nestedList = {NestedInteger({NestedInteger(1),NestedInteger({NestedInteger(4),NestedInteger({NestedInteger(6)})})})};
    NestedIterator iter(nestedList);
    cout << "[";
    while (iter.hasNext()) {
        cout << iter.next();
        if (iter.hasNext()) {
            cout << ", ";
        }
    }
    cout << "]";
    // Output should be: 1 1 2 1 1
    return 0;
}
