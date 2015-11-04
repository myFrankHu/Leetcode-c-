///////////////////////////////////////////////////////////
// Author:    Zhongze Hu
// Subject:   Leetcode_cpp
// Problem:   Text_Justification
// Algorithm: be sure to consider all conditions
// Data:      10/19/2015
///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int L = words.size();
        int idx = 0;
        vector<string> out;
        while (idx < L){
            string line = "";
            int num_words = 0;
            int num_blank = maxWidth;
			int tmp = idx;
			int word_length = 0;
            while((word_length + words[tmp].length() <= maxWidth)){
                ++num_words;
				word_length += (words[tmp].length()+1);
                num_blank -= words[tmp].length();
				++tmp;
				if (tmp >= L){
				    for(int i = 0; i < num_words-1; ++i){
				        line += words[idx++];
				        line += " ";
				    }
				    line += words[idx++];
	                while(line.length() < maxWidth) line += " ";
	                out.push_back(line);
	                return out;
				}
            }
			int blank_each;
			int blank_left;
			if(num_words > 1){
				blank_each = num_blank/(num_words-1);
				blank_left = num_blank%(num_words-1);
				for(int i = 0; i < num_words-1; ++i){
					line += words[idx++];
					string blank(blank_each,' ');
					if(blank_left>i) blank += " ";
					line += blank;
				}
				line += words[idx++];
			}else{
				blank_each = maxWidth - words[idx].length();
				line += words[idx++];
				string blank(blank_each,' ');
				line += blank;
			}
         out.push_back(line);   
        }
    }
};

int main()
{
	vector<string> words;
	words.push_back("test");
	words.push_back("is");
	words.push_back("a");
	words.push_back("nice");
	words.push_back("thing");
	int maxWidth = 6;
	Solution sol;
	vector<string> ans = sol.fullJustify(words,maxWidth);
	return 0;

}