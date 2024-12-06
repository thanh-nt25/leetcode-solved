#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool timDuong(vector<vector<char>>& board, string word, vector<vector<int>> &pass,
		int i, int j, int idx){
		
		if(idx == word.size()){	
			return true;
		}

		if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1 || pass[i][j] == 1 
			|| board[i][j] != word[idx]) return false;


		pass[i][j] = 1;
		bool check = false;

		check =  timDuong(board,word,pass,i+1,j,idx+1) || 
						timDuong(board,word,pass,i-1,j,idx+1) ||
						timDuong(board,word,pass,i,j-1,idx+1) ||
						timDuong(board,word,pass,i,j+1,idx+1);
		
		pass[i][j] = 0;
		
		return check;
		

		
	}

    bool exist(vector<vector<char>>& board, string word) {
    	vector<vector<int>> pass(board.size(), vector<int>(board[0].size(), 0));	
    	
    	for(int i= 0; i < board.size(); ++i){
			for(int j=0; j < board[0].size(); ++j){
				if(board[i][j] == word[0]){
					  if(timDuong(board,word,pass, i,j,0)) return true;
				}
			}
		}
        return false;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Solution a = Solution();

	string s; cin >> s;
	int m,n; cin >> m>>n;
	vector<vector<char>> board(m, vector<char>(n));
	for(int i=0; i < m; ++i){
		for(int j=0; j <n; ++j){
			char c;
			cin >> c;
			board[i][j] = c;
		}
	}

	// cout <<  <<endl;
	bool check = a.exist(board, s);
	cout <<"ket qua cuoi cung" << check;

	return 0;	
}

// ADC
// 3 4
// A B C E
// S F C S
// A D E E





// ABCCED
// 3 4
// A B C E
// S F C S
// A D E E