///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Partition List
// Algorithm: Two pointer, In place?
// Data:      10/27/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *larger = new ListNode(0), *larger_pre = new ListNode(0);
        larger->next = head;
        ListNode *p1 = larger, *p2 = larger_pre;
        while(p1->next){
            if(p1->next->val >= x){
                ListNode* tmp = p1->next;
                p2->next = tmp;
                p1->next = tmp->next;
                p2 = p2->next;  
            }else p1 = p1->next;
        }
        p1->next = larger_pre->next;
        return larger->next;
    }
};

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	Solution sol;
	ListNode* ans = sol.partition(head, 3);
	return 0;
}