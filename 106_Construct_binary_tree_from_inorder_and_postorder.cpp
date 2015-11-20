///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Construct binary tree from inorder and postorder traversal
// Algorithm: Tree traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder);
    }
    TreeNode* build(int is, int ie, int ps, int pe, vector<int>& inorder, vector<int>& postorder){
        if(is > ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int idx = is;
        while(inorder[idx] != root->val) idx++;
        root->left = build(is,idx-1,ps,ps+idx-is-1,inorder,postorder);
        root->right = build(idx+1,ie,pe-ie+idx,pe-1,inorder,postorder);
        return root;
    }
};

int main()
{
	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(3);
	preorder.push_back(2);
	vector<int> inorder;
	inorder.push_back(3);
	inorder.push_back(2);
	inorder.push_back(1);
	Solution sol;
	TreeNode* ans = sol.buildTree(preorder,inorder);
	return 0;
}