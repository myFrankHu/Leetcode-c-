///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Binary tree level order traversal
// Algorithm: level order traversal
// Data:      11/10/2015
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out; 
        if(root == NULL) return out;
        vector<TreeNode*> treenode;
        int cur = 0, last = 0;
        treenode.push_back(root);
        while(cur < treenode.size()){
            last = treenode.size();
            vector<int> tmp;
            while(cur < last){
                tmp.push_back(treenode[cur]->val);
                if(treenode[cur]->left) treenode.push_back(treenode[cur]->left);
                if(treenode[cur]->right) treenode.push_back(treenode[cur]->right);
                ++cur;
            }
            out.push_back(tmp);
        }
        return out;
    }
};