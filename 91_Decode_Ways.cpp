///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Decode Ways
// Algorithm: DP
// Data:      10/27/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    int numDecodings(string s){
        int l = s.length();
        if(l == 0 || s[0] == '0') return 0;
        int cnt[l+1];
        memset(cnt,0,sizeof(int)*(l+1));
        cnt[0] = 1;
        cnt[1] = 1;
        for(int i = 2; i <= l; ++i){
            if(s[i-1] != '0') cnt[i] = cnt[i-1];
            int tmp = (s[i-2] - '0')*10 + (s[i-1] - '0');
            if(tmp < 27 && tmp > 9) cnt[i] = cnt[i] + cnt[i-2];
        }
        return cnt[l];
    }
};