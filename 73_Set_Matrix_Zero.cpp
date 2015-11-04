///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Set Matrix Zero
// Algorithm: try to do in space
// Data:      10/24/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int cur = 0, next = 0;
        vector<int> tmp(c,0);
        bool first_r = false, first_c = false;
        for(int i = 0; i < r; ++i){
            if(matrix[i][0] == 0){
                first_c = true;
                break;
            }
        }
        for(int i = 0; i < c; ++i){
            if(matrix[0][i] == 0){
                first_r = true;
                break;
            }
        }
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 0; i < r; ++i){
            if(matrix[i][0] == 0) matrix[i] = tmp;
        }
        for(int i = 0; i < c; ++i){
            if(matrix[0][i] == 0){
                for(int j = 1; j < r; ++j) matrix[j][i] = 0;
            }
        }
        if(first_r) matrix[0] = tmp;
        if(first_c){
            for(int j = 1; j < r; ++j) matrix[j][0] = 0;
        }
    }
};
