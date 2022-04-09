#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);	cin.tie(nullptr);

void input(vector<char>& v)
{
	string st;
	cin >> st;
	for (int i = 0; i < st.size(); i++)	v.push_back(st[i]);
}

void swapVec(vector<char>& v1, vector<char>& v2) {
	v1.clear();
	for (auto i = v2.begin(); i != v2.end(); i++)
		v1.push_back(*i);
}

void Solve()
{
	int testcase, N;
	cin >> testcase;
	N = testcase;
	while (testcase--) {
		vector<char> v;
		vector<string> ans;
		input(v);
		string origin;
		for (int j = 0; j < v.size(); j++) {
			origin += v[j];
		}
		ans.push_back(origin);

		for (int i = 0; i < v.size() - 1; i++) {
			vector<char>v2;
			swapVec(v2, v);
			for (int k = i; k < v2.size() - 1; k = k + 2) {
				string st;
				vector<char> tmp;
				for (int j = 0; j < k; j++) {
					tmp.push_back(v2[j]);
				}
				tmp.push_back(v2[k]);
				tmp.push_back(v2[k]);
				for (int j = k + 1; j < v2.size(); j++) {
					tmp.push_back(v2[j]);
				}
				swapVec(v2, tmp);

				for (int j = 0; j < v2.size(); j++) {
					st += v2[j];
				}
				ans.push_back(st);
			}
		}

		string answer = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		for (int i = 0; i < ans.size(); i++) {
			if (answer >= ans[i]) {
				answer = ans[i];
			}
		}

		std::cout << "Case #" << N - testcase << ": ";
		cout << answer;
		std::cout << '\n';
	}
}

int main()
{
	FAST_IO;
	Solve();

	//string s1, s2;
	//s1 = "CODEJAMDAY";
	//s2 = "CODEJAAMDAY";
	//if (s1 > s2)
	//	cout << s1;
	//else
	//	cout << s2;
	return 0;
}

// 				if (v2[k] <= v2[k + 1]) {