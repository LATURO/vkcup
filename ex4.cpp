#include<iostream>

using namespace std;

int main() {
	int n = 0;
	int k = 0;
	int ans = 0;

	cin>>n>>k;

	int seq[n];

	if(k == 0) {
		if((n * (n + 1) >> 2) < 10000)
			goto timet;

		int bag[10000 + 1] = { 0, };
		for(int iter = 0; iter < n; iter += 1) {
			int val = 0;
            cin>>val;
			bag[val] += 1;
		}

		for(int val = 0; val <= 10000; val += 1) {
			int c = bag[val];
			if(c > 1) {
				ans += (c * (c - 1) >> 1);
			}
		}

		goto exit;
	}
timet:

	for(int iter = 0; iter < n; iter += 1) {
		cin>>seq[iter];
	}

	for(int i = 0; i < n - 1; i += 1) {
		for(int j = i + 1; j < n; j += 1) {
			if(k ==  __builtin_popcount(seq[i] ^ seq[j])) {
				ans += 1;
			}
		}
	}

exit:
	cout<<ans;
}
