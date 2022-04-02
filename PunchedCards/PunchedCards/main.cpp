#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int T, R, C;
	cin >> T;
	for(int k = 0; k < T; k++) {
		cin >> R >> C;
		cout << "Case #" << k+1 << ":\n";
		for (int i = 0; i < 2*R+1; i++) {
			for (int j = 0; j < 2*C+1; j++) {
				if ((i == 0 || i == 1) && (j == 0 || j == 1)) {
					cout << '.';
				}
				else if (i % 2 == 1 && j % 2 == 1)
				{
					cout << '.';
				}
				else if (i % 2 == 1 && j % 2 == 0)
				{
					cout << '|';
				}
				else if (i % 2 == 0 && j % 2 == 1)
				{
					cout << '-';
				}
				else
				{
					cout << '+';
				}
			}
			cout << '\n';
		}
	}

	return 0;
}