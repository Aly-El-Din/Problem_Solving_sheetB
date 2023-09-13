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
using namespace std;
#define all(v)      ((houses).begin()), ((houses).end())
#define rep(i,n)   for(int i=0; i<n; i++)
#define repe(i,n)   for(int i=0; i<=n; i++)
#define ll	long long
vector<ll>memor(1000001,-1);
ll d(ll n) {
	ll count = 0;
	if (memor[n] != -1) {
		return memor[n];
	}
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (n / i == i) {
				count++;
			}
			else {
				count += 2;
			}
		}
	}
	memor[n] = count;
	return count;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	ll sum = 0;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				sum += d(i * j * k) % 1073741824;
			}
		}
	}
	cout << sum;
}
