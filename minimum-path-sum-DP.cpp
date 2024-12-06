// 2 3
// 1 2 3
// 4 5 6
#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid){

	int m=grid.size();
	
	int n=grid[0].size();

	vector<vector<int>>	point(m, vector<int>(n, 0));

	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++){
			if(i-1 < 0 && j-1 < 0){
				point[i][j] = grid[i][j];
			}else if(i-1 < 0 && j-1 >= 0){
				point[i][j] = grid[i][j] + point[i][j-1];	
			}else if(j-1 < 0 && i-1 >= 0){
				point[i][j] = grid[i][j] + point[i-1][j];	
			}else{
				point[i][j] = grid[i][j] + min(point[i][j-1], point[i-1][j]);	
			}
		}
	}
	return point[m-1][n-1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int m,n;
	cin >> m >> n;

	vector<vector<int>> grid(m, vector<int>(n));


	for(int i = 0; i < m; ++i){
		for(int j=0; j < n; ++j){
			cin >> grid[i][j];
		}
	}

	cout << minPathSum(grid);

	return 0;	
}