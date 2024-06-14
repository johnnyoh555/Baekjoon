// https://www.acmicpc.net/problem/31416
#include <iostream>
#include <cmath>
using namespace std;
int Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int Ta, Tb, Va,Vb;
		cin >> Ta >> Tb >> Va >> Vb;
		int timeb = Tb * Vb;
		int cnt = timeb / Ta;
		int timea = cnt * Ta;
		if (cnt >= Va) cout << timeb << '\n';
		else {
			while (Va - cnt) {
				if (timea < timeb) {
					timea += Ta;
				} else {
					timeb += Ta;
				}
				cnt++;
			}
			cout << max(timea, timeb) << '\n';
		}
	}
}