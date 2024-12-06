#include <bits/stdc++.h>
using namespace std;

string strparen;
// char paren;
stack<char> paren_stack;

int solve(){
	cin >> strparen;
	for(char paren : strparen){
		if(paren_stack.empty()){
			paren_stack.push(paren);
			continue;
		}
		if( (paren == ')' && paren_stack.top() == '(') 
			|| (paren == '}' && paren_stack.top() == '{')
			|| (paren == ']' && paren_stack.top() == '[')) paren_stack.pop();
		else paren_stack.push(paren);
		// cout << paren_stack.top() << "\n";
	}
k
	if (paren_stack.empty()) return 1;
	else return 0;
}	

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solve() << "\n";
	
	
	return 0;
}