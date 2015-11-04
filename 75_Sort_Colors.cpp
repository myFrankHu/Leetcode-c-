///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Sort Colors
// Algorithm: Counting sort
// Data:      10/25/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color[3];
        memset(color,0,sizeof(color));
        for(int i = 0; i < nums.size(); ++i) ++color[nums[i]];
        for(int i = 0; i < color[0]; ++i) nums[i] = 0;
        for(int i = color[0]; i < color[0] + color[1]; ++i) nums[i] = 1;
        for(int i = color[0]+color[1]; i < nums.size(); ++i) nums[i] = 2;
    }
};