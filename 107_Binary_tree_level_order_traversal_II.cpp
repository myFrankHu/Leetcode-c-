///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Binary tree level order traversal II
// Algorithm: Tree level order traversal
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> updown;
        vector<vector<int>> bottomup;
        if(!root) return bottomup;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        int cur = 0, last = 0;
        while(cur < nodes.size()){
            last = nodes.size();
            vector<int> tmp;
            while(cur < last){
                tmp.push_back(nodes[cur]->val);
                if(nodes[cur]->left) nodes.push_back(nodes[cur]->left);
                if(nodes[cur]->right) nodes.push_back(nodes[cur]->right);
                ++cur;
            }
            updown.push_back(tmp);
        }
        for(int i = updown.size()-1; i >= 0; --i) bottomup.push_back(updown[i]);
        return bottomup;
    }
};