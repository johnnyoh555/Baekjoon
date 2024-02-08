// https://www.acmicpc.net/problem/1932

#include <iostream>

using namespace std;

int d[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1)
                d[i][j] += d[i - 1][j];
            else if (j == i)
                d[i][j] += d[i - 1][j - 1];
            else
                d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
        }
    }
    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (d[N][i] > max)
            max = d[N][i];
    }
    cout << max << '\n';
}