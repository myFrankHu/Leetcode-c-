///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Remove Duplicates from Sorted List II
// Algorithm: fast and slow pointer
// Data:      10/27/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* Pre_head = new ListNode(0);
        Pre_head->next = head;
        ListNode *Cur = Pre_head, *Nxt = Pre_head->next;
        while(Nxt){
            while(Nxt->next && Nxt->val == Nxt->next->val) Nxt = Nxt->next;
            if(Nxt != Cur->next){
                Cur->next = Nxt->next;
                Nxt = Cur->next;
            }else{
                Cur = Nxt;
                Nxt = Nxt->next;
            }
        }
        return Pre_head->next;
    }
};