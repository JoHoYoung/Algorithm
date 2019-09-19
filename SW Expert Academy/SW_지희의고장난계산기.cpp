#include <iostream>
#include <string>

using namespace std;

int MIN = 100000000;

int arr[10];
int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

void dfs(int N, int upper, int depth) {

    if (N == 1) {
        MIN = min(depth, MIN);
        return;
    }

    if(upper>1){
        if (N % upper == 0) {
            dfs(N / upper,0, to_string(upper).size() + 1 + depth);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (arr[i] != 0) {
            int pivot = upper*10 + i;
            if (pivot <= N && pivot > 0) {
                dfs(N, pivot, depth);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 10; i++) {
            cin >> arr[i];
        }
        int N;
        cin >> N;
        bool find = true;
        string s = to_string(N);

        for (int i = 0; i < s.size(); i++) {
            if (arr[s[i] - '0'] == 0) {
                find = false;
                break;
            }
        }

        if (find) {
            cout << "#" << t + 1 << " " << s.size() + 1 << endl;
        } else {

            dfs(N,0,0);

            if (MIN == 100000000) {
                cout << "#" << t + 1 << " " << -1 << endl;
            } else {
                cout << "#" << t + 1 << " " << MIN << endl;
                MIN = 100000000;
            }

        }
    }
}
