#include<iostream>

using namespace std;
int N, A, B;

int arr[1000];
int result[1000];

int main() {

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> A >> B;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int idx = 0;
        int head = 0;
        int rear = N - 1;
        A--;
        while (head <= rear) {
            if(idx == N){
                break;
            }
            // �������� -> �ð�������.
            if (head + A > rear) {
                while (head <= rear) {
                    int time = arr[head] + B;
                    int cnt = 1;
                    for (int i = head + 1; i <= rear; i++) {
                        if (arr[i] <= time) {
                            cnt++;
                        } else {
                            break;
                        }
                    }
                    for (int i = 0; i < (cnt + 1) / 2; i++) {
                        result[idx++] = time;
                        head++;
                    }
                }
                break;
            }

            int left = arr[head] + B;
            int right = arr[head + A];
            // �ð� ������
            if (left < right) {
                int time = arr[head] + B;
                int cnt = 1;

                for (int i = head + 1; i <= rear; i++) {
                    if (arr[i] <= left) {
                        cnt++;
                    } else {
                        break;
                    }
                }
                for (int i = 0; i < (cnt + 1) / 2; i++) {
                    result[idx++] = time;
                    head++;
                }
            } else { // ���� ������
                int re = (A + 2) / 2;
                int time = right;
                for (int i = 0; i < re; i++) {
                    result[idx++] = time;
                    head++;
                }
            }
        }

        cout << "#" << t + 1 << " ";

        for (int i = 0; i < N; i++) {
            cout << result[i] << " ";
        }

        cout << endl;
    }
    return 0;
}