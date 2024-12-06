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

	int n1;
	cin >> n1;
	vector<char> s1(n1);
	for(int i=0; i < n1; ++i){
		cin >> s1[i];
	}
	int n2;
	cin >> n2;
	vector<char> s2(n2);
	for(int i=0; i < n2; ++i){
		cin >> s2[i];
	}

	int arr[n1+1][n2+1];
	for(int i=0; i <= n1; ++i){
		arr[0][i] = 0;
		arr[i][0] = 0;
	}

	
	for(int i=1; i <= n1; ++i){
		for(int j=1; j <= n2; ++j){
			if(s1[i-1] == s2[j-1]){
				arr[i][j] = arr[i-1][j-1] + 1;
			}else{
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
			}
		}
	}

	cout << arr[n1][n2];
	return 0;
	
}