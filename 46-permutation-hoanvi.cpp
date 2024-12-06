#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void hoan_vi(int n , vector<int> &current, vector<int> &UCV, vector<vector<int>>&loi_giai){
		
		if(current.size() == n){
			loi_giai.push_back(current);
			return;
		}

		for(auto x : UCV){
			current.push_back(x);
			vector<int> tmp;
			tmp.assign(UCV.begin(), UCV.end());
			auto it = find(tmp.begin(), tmp.end(), x);
			tmp.erase(it);
			hoan_vi(n, current, tmp, loi_giai);
			current.pop_back();
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        vector<int> current;
		// cout << n << endl;
        hoan_vi(n, current, nums, result);
        return result;
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

	int n; cin >> n;


	vector<int> nums;
	for(int i=0; i < n; ++i){
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	
	// for(auto x : nums){
	// 	cout << x;
	// }

	// vector<int> UCV;
	// UCV.assign(a);
	Solution a = Solution();

	vector<vector<int>> loi_giai;
	// cout << 'c';
	loi_giai = a.permute(nums);

	for(auto i: loi_giai){
		for(auto j:i){
			cout << j;
		}
		cout << endl;
	}
	return 0;	
}