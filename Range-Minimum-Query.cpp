#include <bits/stdc++.h>
using namespace std;

// vector<int> arr;


// tinh log2
int log2_floor(unsigned long long n) 
{
    // Số bit 0 đứng đầu của 1 trừ đi số bit 0 đứng đầu của n.
    return n ? __builtin_clzll(1) - __builtin_clzll(n) : -1;
}

// long long query(int l, int r)
// {
//     int i = log2_floor(r - l + 1); // int i = (int) log2((double) r - l + 1);
//     return min(table[i][l], table[i][r - (1 << i) + 1]);
// }



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	
	// vector<int> arr;
	long long arr[n + 1];
	int temp;
	for(int i=0; i<n; ++i){
		cin >> temp;
		 arr[i] = temp;
	}
	int m;
	cin >> m;
	int sumidx[m][2];
	for(int i=0; i<m; ++i){
		for (int j=0; j<2; ++j){
			cin >> sumidx[i][j];
		}
	}

	// solve
	// double maxk = log2_floor(n);
	// int k = static_cast<int>(maxk);
	int k = 25;
	long long table[k + 1][n + 1];

	
    for (int j = 1; j <= n; ++j){
        table[0][j] = arr[j];
    }
		
    for (int i = 1; i <= k; ++i){
        for (int j = 1; j + (1 << i) - 1 <= n; ++j){
            table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        }
    }
	
	// query
	int minsum = 0;
	for(int j=0; j < m; ++j){
		int l = sumidx[j][0]; 
		int r = sumidx[j][1];
		int i = log2_floor(r - l + 1); // int i = (int) log2((double) r - l + 1);
		// cout << min(table[i][l], table[i][r - (1 << i) + 1]) << "\n";
    	minsum += min(table[i][l], table[i][r - (1 << i) + 1]);
	}
	cout << minsum;

}

