#include<iostream>

using namespace std;
long DP[31][31];

int main() {

    int T;
    cin >> T;

    auto arr = new int *[T];
    for (int i = 0; i < T; i++) {
        arr[i] = new int[2];
        cin >> arr[i][0];
        cin >> arr[i][1];
    }

    for (int t = 0; t < T; t++) {

        int N = arr[t][0];
        int M = arr[t][1];

        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= M; j++) {
                if (i == j) {
                    DP[i][j] = 1;
                } else if (i == 1) {
                    DP[i][j] = j;
                } else {
                    DP[i][j] = 0;
                    for (int k = 1; j - k >= i - 1; k++) {
                        DP[i][j] += DP[i - 1][j - k];
                    }
                }
            }
        }
        cout << DP[N][M] << endl;
    }
    return 0;
}