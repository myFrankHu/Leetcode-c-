///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Binary tree zigzag traversal
// Algorithm: level order traversal
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps > pe) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int i = is;
        while(inorder[i] != preorder[ps]) ++i;
        root->left = build(preorder,inorder,ps+1,ps+i-is,is,i-1);
        root->right = build(preorder,inorder,ps+i+1-is,pe,i+1,ie);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};

int main()
{
	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(5);
	preorder.push_back(3);
	preorder.push_back(6);
	vector<int> inorder;
	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(3);
	inorder.push_back(6);
	Solution sol;
	TreeNode* ans = sol.buildTree(preorder,inorder);
	return 0;
}