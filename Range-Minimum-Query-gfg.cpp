#include <bits/stdc++.h>
using namespace std;
// #define MAX 100000

// int lookup[MAX][MAX];

struct Query {
	int L, R;
};

int RMQ(vector<int> arr, int n, vector<Query> q, int m)
{

	int** lookup = new int*[n];
    for (int i = 0; i < n; i++) {
        lookup[i] = new int[n];
    }

	for (int i = 0; i < n; i++)
		lookup[i][i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
			if (arr[lookup[i][j - 1]] < arr[j])
				lookup[i][j] = lookup[i][j - 1];
			else
				lookup[i][j] = j;
	}


	// preprocess(arr, n);
	int sum = 0;
	for (int i = 0; i < m; i++) 
	{
		int L = q[i].L, R = q[i].R;
		cout << arr[lookup[L][R]] << "\n";
		sum += arr[lookup[L][R]];
	}
	return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	
	int n;
	cin >> n;
	vector<int> a;
	int ig;
	for(int i=0; i < n; ++i){
		cin >> ig;
		a.push_back(ig);
	}
	
	int m; cin >> m;

	 vector<Query> q;
    for (int i = 0; i < n; ++i) {
        Query query;
        cin >> query.L >> query.R;
        q.push_back(query);
    }
	cout << RMQ(a, n, q, m);
	
}
