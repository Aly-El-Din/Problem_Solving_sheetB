#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <stack>
#include <set>
#include <unordered_set>
#include <assert.h>
#include <deque>
#include <math.h>
#include <list>
#include <queue>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;
#define all(v)      (v.begin()), (v.end())
#define rep(i,n)   for(int i=0; i<n; i++)
#define repe(i,n)   for(int i=1; i<=n; i++)
#define ll	long long

int n, m,cnt=0;
int arr_row[4] = { 0,0,1,-1 };
int arr_col[4] = { 1,-1,0,0 };

bool sort_vec(const pair<char, int> &p1, const pair<char, int> &p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}


bool valid(int r, int c) {
	if (r < 0 || c < 0 || r >= n || c >= m) {
		return false;
	}
	return true;
}

void DFS(vector<vector<char>>map, vector<vector<bool>>&visited,int r,int c) {
	if (visited[r][c]) {
		return;
	}
	visited[r][c] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int new_r = r + arr_row[i], new_c = c + arr_col[i];
		if (valid(new_r, new_c) && map[new_r][new_c] == map[r][c] && !visited[new_r][new_c]) {
			DFS(map, visited, new_r, new_c);
		}
	}

}
vector<pair<char,int>> DFS_util(vector<vector<char>>map) {
	vector<bool>vis(m);
	vector<vector<bool>>visited(n,vis);
	vector<pair<char, int>>ans;
	int i, j;
	rep(i, n) {
		rep(j, m) {
			if (map[i][j] != '.' && !visited[i][j]) {
				DFS(map, visited, i, j);
				ans.push_back({ map[i][j],cnt });
				cnt = 0;
			}
		}
	}
	sort(all(ans), sort_vec);
	return ans;
}
int main() {
	vector<vector<pair<char, int>>>final_res;
	int t = 1;
	while (true) {
		int i, j;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		string s;
		vector<string>v(n);
		vector<char>vec(m);
		vector<vector<char>>map(n, vec);
		rep(i, n) {
			cin >> v[i];
		}
		rep(i, n) {
			rep(j, m) {
				map[i][j] = v[i][j];
			}
		}
		vector<pair<char, int>>res = DFS_util(map);
		final_res.push_back(res);
	}

	for (auto e : final_res) {
		cout << "Problem " << t << ":" << endl;
		t++;
		for (auto p : e) {
			cout << p.first << " " << p.second << endl;
		}
	}
}