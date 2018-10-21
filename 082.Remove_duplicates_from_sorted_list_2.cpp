
/*
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
 */

#include <iostream>
#include <string>
#include <memory>
using namespace std;

/**
 * Definition for singly-linked list.
 *
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	// see answer, can't get the accepted answer
	// this answer beats 100%, cost 4 ms!
	ListNode* deleteDuplicates(ListNode* head) {
		if(head == nullptr) return nullptr;
		ListNode *FakeHead = new ListNode(0);
		FakeHead->next = head;
		ListNode *pre = FakeHead;
		ListNode *cur = head;
		while(cur != nullptr){
			while(cur->next != nullptr && cur->val == cur->next->val){
				cur = cur->next;
			}
			if(pre->next == cur){
				pre = pre->next;
			}
			else{
				pre->next = cur->next;
			}
			cur = cur->next;
		}
		return FakeHead->next;
	}
};


int main(){
	ListNode * a = new ListNode(1);
	ListNode * b = new ListNode(1);
	ListNode * c = new ListNode(2);
	ListNode * d = new ListNode(2);
	ListNode * e = new ListNode(3);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	Solution s;
	a = s.deleteDuplicates(a);
	while(a) {
		cout << a->val << "->";
		a = a->next;
	}
	delete a;
	delete b;
	delete c;
	return 0;
}