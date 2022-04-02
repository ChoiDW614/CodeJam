#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int u_int;

vector<u_int> C(3), M(3), Y(3), B(3);

u_int common(vector<u_int> color)
{
	u_int min_link = 1000000;
	for (auto i = color.begin(); i != color.end(); i++) {
		if (min_link > *i)
			min_link = *i;
	}
	return min_link;
}

void solve(vector<u_int> cyan, vector<u_int> magenta, vector<u_int> yellow, vector<u_int> black)
{
	u_int c_cyan, c_magenta, c_yellow, c_black;
	c_cyan = common(cyan);	c_magenta = common(magenta);
	c_yellow = common(yellow);	c_black = common(black);

	u_int ink_sum = c_cyan + c_magenta + c_yellow + c_black;
	if (ink_sum < 1000000) {
		cout << "IMPOSSIBLE\n";
	}

	if (c_black < (ink_sum - 1000000)) {
		ink_sum -= c_black;
		c_black = 0;
	}
	else
	{
		c_black -= (ink_sum - 1000000);
		cout << c_cyan << " " << c_magenta << " " << c_yellow << " " << c_black << '\n';
		return;
	}

	if (c_yellow < (ink_sum - 1000000)) {
		ink_sum -= c_yellow;
		c_yellow = 0;
	}
	else
	{
		c_yellow -= (ink_sum - 1000000);
		cout << c_cyan << " " << c_magenta << " " << c_yellow << " " << c_black << '\n';
		return;
	}

	if (c_magenta < (ink_sum - 1000000)) {
		ink_sum -= c_magenta;
		c_magenta = 0;
	}
	else
	{
		c_magenta -= (ink_sum - 1000000);
		cout << c_cyan << " " << c_magenta << " " << c_yellow << " " << c_black << '\n';
		return;
	}

	if (c_cyan < (ink_sum - 1000000)) {
		ink_sum -= c_cyan;
		c_cyan = 0;
	}
	else
	{
		c_cyan -= (ink_sum - 1000000);
		cout << c_cyan << " " << c_magenta << " " << c_yellow << " " << c_black << '\n';
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	
	int T, i, j;
	cin >> T;
	for (i = 0; i < T; i++) {
		for (j = 0; j < 3; j++)	cin >> C[j] >> M[j] >> Y[j] >> B[j];
		cout << "Case #" << i+1 << ": ";
		solve(C, M, Y, B);
	}

	return 0;
}