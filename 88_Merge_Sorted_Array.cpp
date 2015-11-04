///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Merge Sorted Array
// Algorithm: Two pointer, In place?
// Data:      10/27/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        if(m == 0){
            for(int i = 0; i < n; ++i) nums1[i] = nums2[i];
            return;
        }
        int i1 = m-1, i2 = n-1;
        while(i1>=0 && i2>=0){
            nums1[i1+i2+1] = nums1[i1]>nums2[i2]?nums1[i1--]:nums2[i2--];
        }
        while(i2>=0) nums1[i2] = nums2[i2];
    }
};

int main()
{
	vector<int> nums1;
	nums1.push_back(2);
	nums1.push_back(0);
	vector<int> nums2;
	nums2.push_back(1);
	Solution sol;
	sol.merge(nums1,1,nums2,1);

	return 0;

}