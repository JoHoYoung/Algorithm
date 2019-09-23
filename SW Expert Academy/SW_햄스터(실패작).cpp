#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int Marr[11][3];
int t;
vector<int *> comb[11];
vector<int *> step[11];
int MAX[11];
int N, X, M;

bool compare(int *A, int *B) {
    int sumA = 0;
    int sumB = 0;

    for (int i = 0; i < N; i++) {
        sumA += A[i];
        sumB += B[i];
    }

    if (sumA == sumB) {
        for (int i = 0; i < N; i++) {
            if (A[i] == B[i]) {
                continue;
            } else {
                return A[i] < B[i];
            }
        }
    } else {
        return sumA > sumB;
    }
    return true;
}

void getComb(int depth, int *upper, int l, int r, int s) {
    int *arr = new int[N];
    copy(upper, upper + N, arr);
    if(s<0){
        return;
    }
    if (l == r) {
        if (s <= X) {
            arr[l] = s;
            comb[depth].push_back(arr);
        }
    } else if (s == 0) {
        for (int i = l; i <= r; i++) {
            arr[i] = 0;
        }
        comb[depth].push_back(arr);
    } else {
        for (int i = 0; i <= X; i++) {
            arr[l] = i;
            getComb(depth, arr, l + 1, r, s - i);
        }
    }
}

bool concatTwo(int depth, int *A, int *B) {

    int* c = new int[N];
   // int max = 0;

    for(int i=0;i<N;i++){
        c[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        int a = A[i];
        int b = B[i];
        if(a == b){
            c[i] = a;
        }else{
            if(a == -1){
                c[i] = b;
                continue;
            }
            if(b == -1){
                c[i] = a;
                continue;
            }
            return false;
        }
    }
//    if(max>MAX[depth+1]){
//        MAX[depth+1] =max;
//    }
    step[depth+1].push_back(c);
    return true;
}

void solution() {
    for (int t = 0; t < M - 1; t++) {
        if (t == 0) {
            for (int i = 0; i < comb[t].size(); i++) {
                for (int j = 0; j < comb[t + 1].size(); j++) {
                    if (concatTwo(t, comb[t][i], comb[t + 1][j])) {
                        continue;
                    }
                }
            }
        } else {
            for (int i = 0; i < step[t].size(); i++) {
                for (int j = 0; j < comb[t + 1].size(); j++) {
                    if (concatTwo(t, step[t][i], comb[t + 1][j])) {
                        continue;
                    }
                }
            }
            comb[t+1].clear();
            step[t].clear();
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (t = 0; t < T; t++) {
        cin >> N;
        cin >> X;
        cin >> M;

        int *arr = new int[N];
        for (int i = 0; i < N; i++) {
            MAX[i] = -1;
            arr[i] = -1;
        }

        for (int i = 0; i < M; i++) {
            cin >> Marr[i][0];
            cin >> Marr[i][1];
            cin >> Marr[i][2];
            Marr[i][0] -= 1;
            Marr[i][1] -= 1;
        }

        for (int i = 0; i < M; i++) {
            getComb(i, arr, Marr[i][0], Marr[i][1], Marr[i][2]);
        }

        solution();
        sort(comb[M - 1].begin(), comb[M - 1].end(), compare);
        sort(step[M - 1].begin(), step[M - 1].end(), compare);

        if (M <= 1) {
            if(comb[0].size() == 0){
                cout<<"#"<<t+1<<" "<<-1;
            }else{
                cout<<"#"<<t+1<<" ";
                for (int j = 0; j < N; j++) {
                    int num = comb[0][0][j];
                    if (num == -1) {
                        num = X;
                    }
                    cout<< num << " ";
                }
            }
            cout << endl;
        } else {
            if(step[M-1].size() == 0){
                cout<<"#"<<t+1<<" "<<-1;
            }else{
                cout <<"#"<<t+1<<" ";
                for (int j = 0; j < N; j++) {
                    int num = step[M - 1][0][j];
                    if (num == -1) {
                        num = X;
                    }
                    cout<< num << " ";
                }
            }
            cout << endl;
        }

        for(int i=0;i<11;i++){
            comb[i].clear();
            step[i].clear();
        }
    }
    return 0;
}