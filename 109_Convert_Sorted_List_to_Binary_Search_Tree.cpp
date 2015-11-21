///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Convert Sorted List to Binary Search Tree
// Algorithm: Linked list
// Data:      11/20/2015
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
 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        int n = 0;
        ListNode* tmp = head;
        while(tmp->next){
			++n;
			tmp = tmp->next;
		}
        return ListToBST(head,0,n);
    }
    TreeNode* ListToBST(ListNode* head, int s, int e){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        ListNode* midNode = head;
        while(mid-- > 0) midNode = midNode->next;
        TreeNode* root = new TreeNode(midNode->val);
        root->left = ListToBST(head,s,(s+e)/2-1);
        root->right = ListToBST(midNode->next,0,e-(s+e)/2-1);
        return root;
    }
};