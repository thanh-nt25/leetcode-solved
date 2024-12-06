#include <bits/stdc++.h>
using namespace std;

int T;
string sms;
string keyboard[12]= {
	"" , "abc" , "def" ,
	"ghi" , "jkl" , "mno" ,
	"pqrs" , "tuv" , "wxyz" ,
	"" , " " , ""
};

int solve(string sms){
	int push_ = 0;
	int leng = sms.length();
	for(int i=0; i<leng; i++){
		int cpush_ = 0;
		for(int j=0; j<12; j++){
			cpush_ += keyboard[j].find(sms[i]) + 1;
		}
		push_ += cpush_;
	}
	return push_;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	char sp;
	cin >> T; cin.get(sp);
	int case_ = 1;
	while(T > 0){
		getline(cin, sms);
		cout << "Case #" << case_ <<": "<< solve(sms) << "\n";
		T--; case_ ++;
	}

}