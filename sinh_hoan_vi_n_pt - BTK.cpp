#include <bits/stdc++.h>
using namespace std;



void hoan_vi(int n ,int subL, vector<int> &UCV, vector<int> &a, vector<vector<int>>&loi_giai){

	if(subL == n){
		loi_giai.push_back(UCV);
		return;
	}

	for(int i=0; i < a.size(); ++i){
		int tmp = a[i];
		UCV.push_back(a[i]);
		subL++;
		auto it = a.begin() + i;
		a.erase(it);
		
		hoan_vi(n, subL, UCV, a, loi_giai);

		a.insert(it, tmp);
		
		UCV.pop_back();
		subL--;
	}
	
}

int main()
{
#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r",  stdin);
	freopen("../output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> a = {1,2,3,4};
	int n = a.size();
	vector<vector<int>> loi_giai;

	vector<int> UCV;
	// UCV.assign(a);

	hoan_vi(n, 0, UCV, a, loi_giai);
	for(auto i: loi_giai){
		for(auto j:i){
			cout << j;
		}
		cout << endl;
	}
		return 0;	
}