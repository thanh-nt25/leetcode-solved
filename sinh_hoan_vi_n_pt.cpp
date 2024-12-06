#include <bits/stdc++.h>
using namespace std;

bool sinh_ke_tiep(vector<int> &a){
	int n = a.size();
	// phan tu cuoi la n-1
	for(int j = (n-1) - 1; j >= 0; j--){
		if(a[j] < a[j+1]){
			//j+1 den n-1, be nhat lon hon a[j]
			int min_aj = j+1;
			for(int i =j+1; i <= n-1; ++i){
				if(a[j] < a[i] && a[i] < a[min_aj]){
					min_aj = i; //index
				}
			}
			//swap j va min_aj
			int tmp = a[j];
			a[j] = a[min_aj];
			a[min_aj] = tmp;

			reverse(a.begin()+j+1, a.end());
			return true;
		}
	}
	return false;
}

void hoan_vi(vector<int> &a){
	int n= a.size();
	bool check = true;
	do{	
		for(auto x : a){
			cout << x;
		}
		cout << endl;
		check = sinh_ke_tiep(a);

	}while(check);
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
	hoan_vi(a);



	return 0;	
}