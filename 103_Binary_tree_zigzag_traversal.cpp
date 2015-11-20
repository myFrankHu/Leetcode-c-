///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Binary tree zigzag traversal
// Algorithm: level order traversal
// Data:      11/17/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        vector<vector<int>> out;
        if(!root) return out;
        int start = 0, end = 1, zigzag = 1, cnt = 0;
        while(start != end){
            vector<int> tmp;
            if(zigzag == 1){
                for(int i = start; i < end; ++i){
                    tmp.push_back(nodes[i]->val);
                    if(nodes[i]->left){
                        nodes.push_back(nodes[i]->left);
                        cnt++;
                    }
                    if(nodes[i]->right){
                        nodes.push_back(nodes[i]->right);
                        cnt++;
                    }
                }
                out.push_back(tmp);
                zigzag = 2;
                start = end;
                end = end + cnt;
                cnt = 0;
            }else{
                for(int i = end-1; i >= start; --i){
                    tmp.push_back(nodes[i]->val);
                }
                for(int i = start; i < end; ++i){
                    if(nodes[i]->left){
                        nodes.push_back(nodes[i]->left);
                        cnt++;
                    }
                    if(nodes[i]->right){
                        nodes.push_back(nodes[i]->right);
                        cnt++;
                    }
                }
                out.push_back(tmp);
                zigzag = 1;
                start = end;
                end = end + cnt;
                cnt = 0;
            }
        }
        return out;
    }
};