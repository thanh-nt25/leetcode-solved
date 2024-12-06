/*
START
0132465789 0123456789 2023-10-25 10:15:30 10:20:30
0132465789 0123456789 2023-10-25 11:00:00 11:05:00
0123456789 0132465789 2023-10-25 12:00:00 12:10:00
0132465789 0123456789 2023-10-25 13:00:00 13:02:00
#
?check_phone_number
?number_calls_from 0132465789
?number_calls_from 0123456789
?number_total_calls
?count_time_calls_from 0132465789
?count_time_calls_from 0123456789
#
*/
#include <bits/stdc++.h>
using namespace std;

int check_pnumber = 1;
int total_calls = 0;

map<string, int> calls_frNumber, calls_time;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string ignor;
	char dash;
	// var
	string std1, std2;
	int y1,mm1,d1,h1,m1,s1,h2,m2,s2;
	cin >> ignor;
	while(ignor != "#"){
		// if () cout << "true" << "\n";
		cin >> std1; if (std1.length() != 10) check_pnumber = 0;
		if(calls_frNumber.find(std1) == calls_frNumber.end()) calls_frNumber[std1] = 1;
		else calls_frNumber[std1] += 1;
		cin >> std2; if (std2.length() != 10) check_pnumber = 0;
		cin >> y1;
		cin >> dash;
		cin >> mm1;
		cin >> dash;
		cin >> d1;
		// nhap thoi gian goi
		cin >> h1; cin >> dash; cin >> m1; cin >> dash; cin >> s1;
		cin >> h2; cin >> dash; cin >> m2; cin >> dash; cin >> s2;
		if(calls_time.find(std1) == calls_time.end()) calls_time[std1] = h2 * 3600 + m2 * 60 + s2 - (h1 * 3600 + m1 * 60 + s1);
		else calls_time[std1] += h2 * 3600 + m2 * 60 + s2 - (h1 * 3600 + m1 * 60 + s1);

		cin >> ignor;
		// dk
		// cout << std1 << " " << std2 <<  " " << y1 << " " << mm1 << " "
		// 	<< d1  << " " << h1 << " " << m1 << " " << s1 << " " 
		// 	<< h2 << " " << m2 << " " <<  s2 << " " << "\n";
		total_calls += 1;
	}
	string querry;
	string num_check;
	while(querry != "#"){
		cin >> querry;
		if (querry == "?check_phone_number") {cout << check_pnumber << "\n"; continue;}
		if (querry == "?number_calls_from") {cin >> num_check; cout << calls_frNumber[num_check] << "\n"; continue;}
		if (querry == "?number_total_calls") {cout << total_calls << "\n"; continue;}
		if (querry == "?count_time_calls_from") {cin >> num_check; cout << calls_time[num_check] << "\n"; continue;}
	}
	// cout << check_pnumber << total_calls  << calls_frNumber["0132465789"]<< "\n";
}