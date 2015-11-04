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
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(search(i,j,0,board,word)) return ture;
            }
        }
        return false;
    }
    bool search(int i, int j, int t, vector<vector<char>> board, string word) {
        if(t >= word.length()) return true;
        if(i<0||i==board.size()||j<0||j==board[0].size()) return false;
        if(board[i][j] == word[t]){
            char tmp = board[i][j];
            board[i][j] = '*';
            bool cur = search(i-1,j,t+1,board,word)||search(i+1,j,t+1,board,word)||search(i,j-1,t+1,board,word)||search(i,j+1,t+1,board,word);
            board[i][j] = tmp;
            return cur;
        }
        return false;
    }
    
};

int main()
{
	vector<vector<char>> board;
	vector<char> row1(3,'A');
	row1[0] = 'C';
	vector<char> row2(3,'A');
	vector<char> row3(3,'B');
	row3[1] = 'C';
	row3[2] = 'D';
	board.push_back(row1);
	board.push_back(row2);
	board.push_back(row3);
	Solution sol;
	bool ans = sol.exist(board,"AAB");
	return 0;
}