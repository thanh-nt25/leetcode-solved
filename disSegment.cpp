#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<pair<int, int>> segments;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        segments.push_back(make_pair(a, b));
    }

    sort(segments.begin(), segments.end(), [](pair<int, int> x, pair<int, int> y) {
        return x.second < y.second;
    });

    int count = 0;
    pair<int, int> previousSegment = make_pair(-1, -1);

    for (int i = 0; i < n; i++) {
        int a = segments[i].first;
        int b = segments[i].second;
        if (a > previousSegment.second) {
            count++;
            previousSegment = segments[i];
        }
    }

    cout << count << endl;

    return 0;
}
