#include <bits/stdc++.h>
using namespace std;
// #define ROW 8
// #define COL 12
int ROW, COL;
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };
 
bool isValid(int **grid, bool **vis,
             int row, int col)
{
    if (grid[row][col] == 1) return false;
    if (row < 0 || col < 0
        || row >= ROW || col >= COL)
        return false;
    if (vis[row][col])
        return false;
    return true;
}
 
int BFS(int **grid, bool **vis, int row, int col)
{
    queue<pair<pair<int, int> , int> > q;
    pair<int, int> start = {row, col};
    q.push({start, 1});
    vis[row][col] = true;
 	// int step = 0;
    while (!q.empty()) {
 
        pair<pair<int, int> , int> cell = q.front();
        int x = cell.first.first;
        int y = cell.first.second;
        int distan = cell.second;
        // cout << x << "-" << y << "\n";
 		if (x == 0 || x == ROW -1 || y == 0 || y == COL -1) {
             return distan;
        }
 
        q.pop();
 
        for (int i = 0; i < 4; i++) {
 
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];
            pair<int, int> insert_ = {adjx, adjy};
            if (isValid(grid, vis, adjx, adjy)) {
                q.push({ insert_ , distan + 1});
                vis[adjx][adjy] = true;
            }
        }
    }
    return -1;
}
 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    
    cin >> ROW >> COL;
    int x, y;
    cin >> x >> y;
    int **grid = new int*[ROW];
    for (int i = 0; i < ROW; i++) {
        grid[i] = new int[COL];
    }

    for (int i=0; i<ROW; ++i){
        for(int j=0; j<COL; ++j){
            cin >> grid[i][j];
        }
    }
    // cout << ROW << COL << x << y;

    bool **vis = new bool*[ROW];
    // memset(vis, false, sizeof vis);
    for (int i = 0; i < ROW; i++) {
        vis[i] = new bool[COL];
    }
    for (int i=0; i<ROW; ++i){
        for(int j=0; j<COL; ++j){
            vis[i][j] = false;
        }
    }

 
    cout << BFS(grid, vis, x-1, y-1);

    for (int i = 0; i < ROW; i++) {
        delete[] grid[i];
    }
    delete[] grid;    
 
    return 0;
}
    // int grid[ROW][COL]={{1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    //                  {1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1},
    //                  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
    //                  {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    //                  {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0},
    //                  {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    //                  {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1}};
    // int grid[ROW][COL]={{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    //                     {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
    //                     {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36},
    //                     {37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48},
    //                     {49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    //                     {61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72},
    //                     {73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84},
    //                     {85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96}};
