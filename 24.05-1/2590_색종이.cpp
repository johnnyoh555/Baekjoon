// https://www.acmicpc.net/problem/2590
#include <iostream>
#include <cstring>
using namespace std;
int cnt, ans, arr[7];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 6; i++) {cin >> arr[i]; cnt += arr[i];}
	while (cnt) {
		ans++;
		bool b[6][6];
		memset(b, 0, sizeof(b));
		for (int i = 6; i > 0; i--) {
			if (!arr[i]) continue;
			for (int y = 0; y <= 6 - i; y++) {
				for (int x = 0; x <= 6 - i; x++) {
					if (!cnt || !arr[i]) break;
					if (b[y][x] == 0) {
						bool flag = 0;
						for (int yy = y; yy < y + i; yy++)
							for (int xx = x; xx < x + i; xx++)
								if (b[yy][xx]) flag = 1;
						if (flag) continue;
						for (int yy = y; yy < y + i; yy++)
							for (int xx = x; xx < x + i; xx++)
								b[yy][xx] = 1;
						cnt--;
						arr[i]--;
					}
				}
			}
		}
	}	
	cout << ans << '\n';
}