
/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
	// my answer 8ms, beats 98.61%
	ListNode* deleteDuplicates(ListNode* head) {
		auto result = head;
		if(head == nullptr || head->next == nullptr)
			return head;
		while(head ) {
			while(head->next && head->val == head->next->val) {
				head->next = head->next->next;
			}
			head = head->next;
		}
		return result;
	}
};


int main(){
	ListNode * a = new ListNode(1);
	ListNode * b = new ListNode(1);
	ListNode * c = new ListNode(1);
	ListNode * d = new ListNode(3);
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