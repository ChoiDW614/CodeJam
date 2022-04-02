#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, i, j, k, l, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> T;
	for (i = 0; i < T; i++)
	{
		cin >> N;
		vector<int> arr, S(N);
		for (j = 0; j < N; j++)	cin >> S[j];

		sort(S.begin(), S.end());
		k = 0;
		for (l = 0; l < S.size(); l++)
		{
			if (k + 1 <= S[l]) {
				arr.push_back(k + 1);
				k++;
			}
		}
		cout << "Case #" << i + 1 << ": " << arr.back() << '\n';
	}
	return 0;
}