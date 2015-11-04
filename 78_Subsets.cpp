///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Subsets
// Algorithm: Recursion
// Data:      10/26/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        result.push_back(subset);
        sort(nums.begin(),nums.end());
        getSubsets(0,nums,subset,result);
        return result;
    }
    void getSubsets(int idx, vector<int> &nums, vector<int> &subset, vector<vector<int>> &result){
        if(idx >= nums.size()) return;
        subset.push_back(nums[idx]);
        result.push_back(subset);
        getSubsets(idx+1,nums,subset,result);
        subset.pop_back();
        getSubsets(idx+1,nums,subset,result);
    }
};