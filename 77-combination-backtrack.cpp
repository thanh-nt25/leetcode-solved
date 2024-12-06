#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void backtrack(int k, vector<int> &UCV, vector<int> &current, vector<vector<int>> &result){

		if(current.size() == k){
			result.push_back(current);
			return;
		}

		for(int i=0; i < UCV.size(); ++i){
			current.push_back(UCV[i]);
			// how to gen tmp
			vector<int> subvec(UCV.begin()+i+1, UCV.end());
			backtrack(k, subvec, current, result);
			
			current.pop_back();
		}
	}

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        vector<int> UCV;
        for(int i=1; i <= n; ++i){
        	UCV.push_back(i);
        }
        backtrack(k, UCV, current, result);
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

	int n, k; cin >> n >> k;
	Solution a = Solution();
	vector<vector<int>> result = a.combine(n,k);
	for(auto x: result){
		for(auto i : x){
			cout << i;
		}
		cout << endl;
	}

	return 0;	
}