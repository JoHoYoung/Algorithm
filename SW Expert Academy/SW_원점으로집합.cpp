#include<iostream>

using namespace std;

int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        auto arr = new int[N];

        // even : true, odd = false;
        int n, m;

        cin >> n;
        cin >> m;

        arr[0] = abs(n) + abs(m);

        int remain = arr[0] % 2;
        int MAX = arr[0];

        int a, b;
        bool found = false;
        for (int i = 1; i < N; i++) {

            cin >> a;
            cin >> b;

            arr[i] = abs(a) + abs(b);
            MAX = max(arr[i], MAX);

            if (arr[i] % 2 != remain) {
                found = true;
            }
        }

        if (found) {
            cout << "#" << t + 1 << " " << -1 << endl;
        }

        int i = 0;
       // cout<<"CASE [] "<<MAX<<endl;
        while (!found) {
            MAX -= i;
            if (MAX == 0) {
                cout << "#" << t + 1 << " " << i << endl;
                break;
            }
            if (MAX < 0) {
                MAX += i;
                if(MAX%2 == (i)%2){
                    cout << "#" << t + 1 << " " << i << endl;
                    break;

                }else{
                    MAX -= i;
                    if(abs(MAX)%2 == (i+1)%2){
                        cout << "#" << t + 1 << " " << i+1 << endl;
                        break;
                    }else{
                        cout << "#" << t + 1 << " " << i+2 << endl;
                        break;
                    }
                }

            }
            i++;
        }
    }
    return 0;
}
//10
//1
//1 0
//1
//2 0
//1
//3 0
//1
//4 0
//1
//5 0
//1
//6 0
//1
//7 0
//1
//8 0
//1
//9 0
//1
//100000000 0