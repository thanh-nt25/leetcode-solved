#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void backtrack(int target, vector<int> &nums, int idx,
		vector<int>& current, vector<vector<int>> &result){
		if(target == 0){
			result.push_back(current);
			return;
		}
		for(int i =idx; i < nums.size(); ++i){
			if (nums[i] > target) continue;
			current.push_back(nums[i]);
			backtrack(target-nums[i], nums,i, current, result);
			current.pop_back();
		}
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        int n = candidates.size();
        vector<vector<int>> result;
        backtrack(target, candidates, 0, current, result);
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

	int target; cin >> target;
	int n; cin >> n;
	vector<int> nums;
	for(int i = 0; i < n; ++i){
		int tmp; 
		cin >> tmp;
		nums.push_back(tmp);
	}

	Solution a = Solution();
	vector<vector<int>> result;
	result = a.combinationSum(nums, target);

	for(auto x: result){
		for(auto i: x){
			cout << i;
		}
		cout << endl;
	}
	
	return 0;	
}