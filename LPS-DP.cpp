#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	int n = s.size();

	int arr[n][n];
	for(int i=0; i < n; ++i){
		arr[i][i] = 1; 
	}

	for(int i=1; i < n; ++i){
		arr[i][i-1] = 0;
	}
	
	for(int k = 1; k < n; ++k){
		
		for(int i=0; i < n - k; ++i){
			int j = i+k;
			if(s[i] == s[j]){
				arr[i][j] = arr[i+1][j-1]+2;
			}else{
				arr[i][j] = max(arr[i+1][j], arr[i][j-1]);
			}
			// cout << i <<'-' << j <<':' << arr[i][j] << '\t';			
		}		
		// cout << endl;
	}


	cout << arr[0][n-1];

	
}