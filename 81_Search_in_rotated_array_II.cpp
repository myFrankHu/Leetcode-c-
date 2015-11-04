///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Search in rotated array II
// Algorithm: Binary search
// Data:      10/26/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] == target) return true;
            
            if(nums[left] < nums[mid]){
                if(target < nums[left] || target > nums[mid]) left = mid + 1;
                else right = mid - 1;
            }else if(nums[left] > nums[mid]){
                if(target > nums[right] || target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }else ++left;
        }
        return false;
    }
};