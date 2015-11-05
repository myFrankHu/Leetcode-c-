///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Unique binary search trees
// Algorithm: DP
// Data:      11/05/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int cnt[n+1];
        memset(cnt,0,sizeof(cnt));
        cnt[0] = 1;
        cnt[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 0; j < i; ++j){
                cnt[i] = cnt[i] + cnt[j]*cnt[i-j-1];
            }
        }
        return cnt[n];
    }
};