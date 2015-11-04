///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Combination Sum
// Algorithm: struct, pointer, map
// Data:      09/20/2015
///////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


vector<vector<int>> combination(vector<int>& candidates, int target, int start){
    int N = candidates.size();    
    vector<vector<int>> out;
    for(int i=start; i < N; i++){
        if(candidates[i] < target){
            vector<vector<int>> sub_out = combination(candidates, target-candidates[i], i);
            for(int j = 0; j < sub_out.size(); j++){
                sub_out[j].insert(sub_out[j].begin(), candidates[i]);
            }
            out.insert(out.end(),sub_out.begin(),sub_out.end());
        }
        else if(candidates[i] == target){
            vector<int> sub_out;
            sub_out.push_back(candidates[i]);
            out.insert(out.end(),sub_out);
        }
        else break;
    }
    return out;
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        return combination(candidates, target, 0);
    }
};

int main()
{
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);
	Solution sol;
	vector<vector<int>> ans = sol.combinationSum(candidates, 7);
	return 0;
}