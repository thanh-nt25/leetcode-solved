#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	int n = numbers.size();
    	int i=0, j=numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                return {i+1, j+1};
            }else if(numbers[i]+numbers[j]<target){
                i++;
            }else{
                j--;
            }
        }
        return {};
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
	vector<int> a;
	for(int i=0; i < n; ++i){
		int tm; cin >> tm;
		a.push_back(tm);
	}
	int tg; cin >> tg;

	Solution b = Solution();
	vector<int> c;
	c=b.twoSum(a, tg);
	for(auto x:c){
		cout << x;
	}

	
	return 0;	
}