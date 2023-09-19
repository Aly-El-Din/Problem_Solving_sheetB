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
#define repe(i,n)   for(int i=0; i<=n; i++)
#define ll	long long



int main() {
	int a,x,y;
	cin >> a >> x >> y;
	int mod = y % a;
	if (mod == 0) {
		cout << -1;
		return 0;
	}
	int yy = y - mod;
	int idx = yy / a;
	if (idx != 0 && idx % 2 == 0) {
		if ((x == 0|| x == a || x==-a)) {
			cout << -1;
			return 0;
		}
		else if (x > a || x < -a) {
			cout << -1;
			return 0;
		}
		else {
			int cont = idx + idx / 2;
			if (x > 0 && x < a) {
				cout << cont + 1;
			}
			else if (x < 0 && x > -a) {
				cout << cont;
			}
		}
	}
	else {
		if ((a % 2 == 0)&&(x == a / 2 || x == -a / 2)) {
			cout << -1;
			return 0;
		}
		else if ((x > (double)a / 2 || x <(double)- a / 2)) {
			cout << -1;
			return 0;
		}
		else {
			if (idx != 1 && idx!=0) {
				cout << idx + ((idx - 1) / 2) + 1;
			}
			else {
				cout << idx+1;
			}
		}
	}
}
