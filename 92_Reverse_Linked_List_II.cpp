///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Reverse linked list II
// Algorithm: 2 pointer
// Data:      10/28/2015
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode *p = new ListNode(0);
        p->next = head;
        ListNode *p1 = p, *p2 = p;
        for(int i = 0; i < m-1; ++i) p1 = p1->next;
        for(int i = 0; i < n; ++i) p2 = p2->next;
        for(int i = m; i < n; ++i){
            ListNode* tmp = p1->next;
            p1->next = tmp->next;
            tmp->next = p2->next;
            p2->next = tmp;
        }
        return p->next;
    }
};