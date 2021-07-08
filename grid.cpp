#include<bits/stdc++.h>
using namespace std;
int helper(vector<vector<int>>grid, int i, int j, vector<vector<bool>>& visited ) {
	if (grid[i][j] == 0)return 0;
	if (grid[i][j] == 9)return 1;
	visited[i][j] = true;
	int a = helper(grid, i + 1, j, visited);
	int b = helper(grid, i - 1, j, visited);
	int c = helper(grid, i, j + 1, visited), d = helper(grid, i, j - 1, visited);

}
int getmin(vector<vector<int>>grid) {
	vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(), false));
	return helper(grid, 0, 0, visited, 0);
}
int main()
{

	vector<vector<int>>grid {{1, 0, 0}, {1, 0, 1}, {1, 9, 0}};
	cout << getmin(grid) << endl;
}