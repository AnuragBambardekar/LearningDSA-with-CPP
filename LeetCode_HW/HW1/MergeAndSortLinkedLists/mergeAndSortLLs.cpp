#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct mycmp{
    bool operator() (ListNode* a, ListNode* b)
    {
        return a->val > b->val; //reverse the sign (>) and return
    }
};
 
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            //mycmp to sort in ascending order and convert max heap to min heap
            priority_queue<ListNode*, vector<ListNode*>, mycmp>pq; //Priority Queue is a max heap by default
            for(ListNode*x :lists)
            {
                if(x)
                {
                    pq.push(x); //push head node in priority queue
                }
            }

            ListNode* head = NULL;
            ListNode* tail = NULL;

            while(!pq.empty())
            {
                ListNode* x = pq.top();
                pq.pop(); //got the smallest values

                if(head == NULL)
                {
                    tail = x;
                    head = tail;
                }
                else
                {
                    tail->next = x;
                    tail = x;
                }

                if(x->next)
                {
                    pq.push(x->next);
                }
            }

            return head;

        }
};


int main()
{
    // Create the linked lists
    ListNode n1(1);
    ListNode n2(4);
    ListNode n3(5);
    n1.next = &n2;
    n2.next = &n3;

    ListNode m1(1);
    ListNode m2(3);
    ListNode m3(4);
    m1.next = &m2;
    m2.next = &m3;

    ListNode k1(2);
    ListNode k2(6);
    k1.next = &k2;

    // Add the linked lists to the vector
    vector<ListNode*> lists = {&n1, &m1, &k1};

    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    // Print the result
    while(result)
    {
        cout<<result->val<<" ";
        result = result->next;
    }

    return 0;
}
