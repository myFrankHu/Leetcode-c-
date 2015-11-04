///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Eidt_Distance
// Algorithm: DP
// Data:      10/24/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int Dis[3][3];
        Dis[0][0] = 0;
        for(int i = 1; i <= l1; ++i) Dis[0][i] = i;
        for(int i = 1; i <= l2; ++i) Dis[i][0] = i;
        for(int i = 1; i <= l2; ++ i){
            for(int j = 1; j <= l1; ++ j){
                if(word1[j-1] == word2[i-1]) Dis[i][j] = Dis[i-1][j-1];
                else Dis[i][j] = min(min(Dis[i-1][j], Dis[i][j-1]),Dis[i-1][j-1]) + 1;
            }
        }
        return Dis[l2][l1];
    }
};

int main()
{
	string s1 = "ab", s2 = "be";
	Solution sol;
	int ans = sol.minDistance(s1,s2);

	return 0;
}