// 3 3
// 0 0 0
// 0 1 0
// 0 0 0

// 2 2
// 0 1
// 0 0
#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
	//base case
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	if(obstacleGrid[m-1][n-1] == 1) return 0;

	vector<vector<int>> a(m, vector<int>(n, 0));

	for(int i=0; i < m; ++i){
		for(int j=0; j < n; ++j){
			// ko co duong di
			if(i-1 < 0 && j-1 < 0 && obstacleGrid[i][j] == 1){
				a[i][j] = 0; // miss case
			}else if(i-1 < 0 && j-1 < 0 && obstacleGrid[i][j] != 1){
				a[i][j] = 1; // miss case
				continue;
			}else if(i-1 < 0 && obstacleGrid[i][j-1] == 1){
				a[i][j] = 0;	
			}else if(j-1 < 0 && obstacleGrid[i-1][j] == 1){
				a[i][j] = 0;
				
			}// co 1 duong di 
            else if(i-1<0 && obstacleGrid[i][j-1] != 1){
				a[i][j] += a[i][j-1];
				
			}else if(j-1<0 && obstacleGrid[i-1][j] != 1){
				a[i][j] += a[i-1][j];
				
			}else if(obstacleGrid[i-1][j] == 0  && obstacleGrid[i][j-1] == 1){
				// a[i][j] += 1;
				a[i][j] += a[i-1][j];	
			}else if(obstacleGrid[i][j-1] == 0  && obstacleGrid[i-1][j] == 1){
				// a[i][j] += 1;
				a[i][j] += a[i][j-1];
				
			}else if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] == 1){
				a[i][j] = 0;
			}else{
                // co 2 duong di
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
		}
	}
	// for(int i=0; i < m; ++i){
	// 	for(int j=0; j < n; ++j){
	// 		cout << a[i][j] << '\t';
	// 	}
	// 	cout << endl;
	// }
	return a[m-1][n-1];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m,n;
	cin >> m >> n;

	vector<vector<int>> a(m, vector<int>(n));
	for(int i=0; i < m; ++i){
		for(int j=0; j < n; ++j){
			cin >> a[i][j];
		}
	}

	// for(int i=0; i < m; ++i){
	// 	for(int j=0; j < n; ++j){
	// 		cout << a[i][j];
	// 	}
	// }

	cout << uniquePathsWithObstacles(a);


	return 0;	
}