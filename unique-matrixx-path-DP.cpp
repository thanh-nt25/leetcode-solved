#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n){
	vector<vector<int>> path(m, vector<int>(n, 0));
	for(int i=0; i < m; ++i){
		for(int j=0; j < n; ++j){
			if(i-1 < 0 && j-1 < 0){
				path[i][j] = 0;
			}else if(i-1 < 0){
				path[i][j] += 1;
			}else if(j-1 < 0){
				path[i][j] += 1;
			}else{
				path[i][j] = path[i-1][j] + path[i][j-1];
			}
		}
	}
	return path[m-1][n-1];
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
	cin >> m >>n;

	cout << uniquePaths(m,n);

	return 0;	
}