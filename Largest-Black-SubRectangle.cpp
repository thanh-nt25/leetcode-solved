#include <bits/stdc++.h>
using namespace std;

int maxHist(int row[], int COL){
	stack<int> result;
	int max_area = 0;

	// int i=0;
	for(int i=0; i < COL; i++)
	{
		if(result.empty() || row[i] >= row[result.top()]){
			result.push(i);
		}else{
			int temp = row[result.top()];
			result.pop();
			max_area = max(max_area, temp * (result.empty() ? i : i - 1 - result.top()));
			i--;
		}
	}
	return max_area;

}

int solve(int **A, int ROW, int COL){
	
	int max_area = maxHist(A[0], COL);
	for(int i=1; i < ROW; ++i){
		for(int j = 0; j < COL; ++j){
			if(A[i][j] == 1) A[i][j] += A[i-1][j];
		}
		max_area = max(max_area, maxHist(A[i], COL));
	}
	return max_area;

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ROW, COL;
	cin >> ROW >> COL;
	int **A = new int*[ROW];
    for(int i = 0; i < ROW; i++)
        A[i] = new int[COL];

    for (int i=0; i<ROW; ++i){
        for(int j=0; j<COL; ++j){
            cin >> A[i][j];
        }
    }

    cout << solve(A, ROW, COL);

}