///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Convert Sorted Array to Binary Search Tree
// Algorithm: Binary tree
// Data:      11/20/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return ArrayToBST(0,nums.size()-1,nums);
    }
    TreeNode* ArrayToBST(int s, int e, vector<int>& nums){
        if(s > e) return NULL;
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = ArrayToBST(s,mid-1,nums);
        root->right = ArrayToBST(mid+1,e,nums);
        return root;
    }
};