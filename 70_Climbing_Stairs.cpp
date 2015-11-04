///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Climbing_Stairs
// Algorithm: Recursion(time limit), math, DP
// Data:      10/19/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        else if(n == 2) return 2;
        int cnt[3], now = 2, pre1 = 1, pre2 = 0;
        cnt[0] = 1; cnt[1] = 2;
        for(int i = 2; i < n-1; ++i){
            cnt[now] = cnt[pre1] + cnt[pre2];
            pre2 = pre1;
            pre1 = now;
            now = (now+1)%3;
        }
		cnt[now] = cnt[pre1] + cnt[pre2];
        return cnt[now];
    }
};


int main()
{
	int n = 10;
	Solution sol;
	int ans = sol.climbStairs(n);
	return 0;
}