#include <bits/stdc++.h>
using namespace std;
// 9
// -2 1 -3 4 -1 2 1 -5 4

int maxSubArray(vector<int>& nums){
	int n = nums.size();
	int mx = INT_MIN;

	for(int i=0; i < n; ++i){
		int currentSum = 0;
		for(int j=i; j < n; ++j){
			currentSum += nums[j];
			mx = max(mx, currentSum);
		}
	}
	return mx;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> nums;
	for(int i=0; i < n; ++i){
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}

	cout << maxSubArray(nums);

	return 0;	
}