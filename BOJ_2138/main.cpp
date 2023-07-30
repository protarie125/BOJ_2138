#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

void tog(string& s, int i) {
	for (auto j = i - 1; j <= i + 1; ++j) {
		if (-1 == j) {
			continue;
		}

		if (j == s.length()) {
			continue;
		}

		if ('1' == s[j]) {
			s[j] = '0';
		}
		else {
			s[j] = '1';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	string now, target;
	cin >> now >> target;

	auto anss = vi{};

	auto now1 = string{ now };
	auto ans1 = int{ 0 };
	for (auto i = 1; i < n; ++i) {
		if (now1[i - 1] != target[i - 1]) {
			tog(now1, i);
			++ans1;
		}
	}

	if (now1 == target) {
		anss.push_back(ans1);
	}

	auto now2 = string{ now };
	tog(now2, 0);
	auto ans2 = int{ 1 };
	for (auto i = 1; i < n; ++i) {
		if (now2[i - 1] != target[i - 1]) {
			tog(now2, i);
			++ans2;
		}
	}

	if (now2 == target) {
		anss.push_back(ans2);
	}

	if (0 == anss.size()) {
		cout << -1;
		return 0;
	}

	cout << *min_element(anss.begin(), anss.end());

	return 0;
}