/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>

using std::priority_queue;
using std::list;
using std::map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::stack;
using std::vector;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    bool operator< (const ListNode* a) const  //重载 < 运算符自定义排序准则；
    {
        return a->val < val;
    }
};

class Solution {
public:
    // my accepted solution, 366ms
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL ) return l2;
        else if(l2 == NULL) return l1;
        else {
            if(l1->val < l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    }
    //更好理解的递归版本，但实质上和上面是一样的，只是借助了自己创建的head节点，
    // 谁小就让head等于谁，然后继续开始查找下一个，查找到最后以后，再回溯，每次head往前走， 回到最开始的位置
    // 上面回溯则不是通过head，而是让l1，l2逐步往回走
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        if(l1 == NULL ) return l2;
        else if(l2 == NULL) return l1;
        else {
            if(l1->val < l2->val) {
                head = l1;
                head->next = mergeTwoLists1(l1->next, l2);
            }
            else {
                head = l2;
                head->next = mergeTwoLists1(l1, l2->next);
            }
        }
        return head;
    }
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        size_t listSize = lists.size();
        if(lists.empty())
            return NULL;
        if(listSize == 1)
            return lists[0];
        for(int i = 0; i < listSize-1; i++) {
            lists[i+1] = mergeTwoLists(lists[i], lists[i+1]);
        }
        return lists[listSize-1];
    }

    // better C++ solution, 56ms
    // also need merge Two lists function
    // but this solution is better,我之前那样处理是处理1 2，2 3，3 4
    //这样就是相当于处理1 2， 3 4， 5 6 ,divide and conquer
    ListNode* mergeKLists1(std::vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }

    // a solution based on priority queue
    // this solutio need 29 ms
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    ListNode *mergeKLists2(std::vector<ListNode *> &lists) { //priority_queue
        priority_queue<ListNode *, std::vector<ListNode *>, compare> q;
        for(auto l : lists) {
            if(l)  q.push(l);
        }
        if(q.empty())  return NULL;

        ListNode* result = q.top();
        q.pop();
        if(result->next) q.push(result->next);
        ListNode* tail = result;
        //因为是k个有序链表，先把所有链表第一个放进去，最小的肯定就是所有中最小的，然后放进去最小的next，和之前那些去比
        // 依次类推，遍历所有的节点
        while(!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if(tail->next) q.push(tail->next);
        }
        return result;
    }

};
int main() {
    Solution s;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(4);
    l3->next->next = new ListNode(6);
    std::vector<ListNode* > vec{l1,l2,l3};
    ListNode* result = s.mergeKLists2(vec);
    while(result) {
        cout<<result->val<<'\t';
        if(result->next) {
            result = result->next;
        } else
            result = NULL;
    }
    return 0;
}