///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Combinations
// Algorithm: Backtracking, recursion
// Data:      10/25/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine1(int n, int k) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> p(k, 0);
        while (i >= 0) {
            p[i]++;
            if (p[i] > n) --i;
            else if (i == k - 1) result.push_back(p);
            else {
                ++i;
                p[i] = p[i - 1];
            }
        }
        return result;
    }
	vector<vector<int>> combine2(int n, int k){
        vector<vector<int>> result;
        vector<int> sol;
        comb(n,k,1,sol,result);
        return result;
    }
    void comb(int n, int k, int start, vector<int> &sol, vector<vector<int>> &result){
        if(k == 0){
            result.push_back(sol);
            return;
        }
        for(int i = start; i <= n-k+1; ++i){
            sol.push_back(i);
            comb(n,k-1,i+1,sol,result);
            sol.pop_back();
        }
    }
};
