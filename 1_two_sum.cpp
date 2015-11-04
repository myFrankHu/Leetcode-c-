///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Two_sum
// Algorithm: struct, pointer, map
// Data:      10/12/2015
///////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <algorithm>
#include <hash_map>
using namespace std;

struct node
{
	int val;
	int idx;
	node(int v,int i):val(v),idx(i){}
};

bool cmp(node &a, node &b){
	return a.val < b.val;
};

class Solution {
public:

	//vector<int> twoSum(vector<int>& nums, int target) {
 //       map<int, int> m;
 //       vector<int> out;
 //       for(int i = 0; i < nums.size(); ++i){
 //           if(m.find(target - nums[i]) != m.end()){
 //               out.push_back(min(i+1, m[i] + 1));
 //               out.push_back(max(i+1, m[i] + 1));
 //               break;
 //           }
 //           m.insert(pair<int,int>(nums[i], i));
 //       }
 //       return out;
 //   }


    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> index;
		vector<node> P_number;		//potential numbers
        int L = numbers.size();
		for(int i = 0;i < L;i ++){
				P_number.push_back(node(numbers[i], i+1));
		}
		sort(P_number.begin(),P_number.end(),cmp);
		int head = 0;
		int end = L - 1;
		while(head <= end){
			int sum = P_number[head].val + P_number[end].val;
			if(sum == target){
				index.push_back(min(P_number[head].idx,P_number[end].idx));
				index.push_back(max(P_number[head].idx,P_number[end].idx));
				break;
			}else if(sum > target){
				end--;
			}else{
				head++;
			}
		}
		return index;
    }

};


int main()
{
	Solution sol;
	vector<int> numbers;
	numbers.push_back(0);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(0);
	int target = 0;
	vector<int> idx = sol.twoSum(numbers,target);
	cout<<idx[0]<<" "<<idx[1]<<endl;
	return 0;
}