#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<char> arr;
int power(int N){
    int r = 1;
    for(int i=0;i<N;i++){
        r*=2;
    }
    return r;
}

string floatToString(float a){
    int cnt = 1;
    while(1){
        if(a - (int)a == 0 ){
            break;
        }
        a*=2;
        cnt*=2;
    }
    return to_string(static_cast<int>(a)) + "/" + to_string(cnt);
}

int main() {
    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        string str;
        cin>>str;

        for(int i=0;i<str.size();){
            if(str[i] == 'n'){
                arr.push_back('N');
                i+=5;
            }else if(str[i] == 'w'){
                arr.push_back('W');
                i+=4;
            }
        }
        int upperN = 0;
        int upperW = 0;

        float ret = 0;

        for(auto it=arr.rbegin();it!=arr.rend();it++){
            char C = *it;
            if(C == 'N'){
                if(upperN != 0 || upperW != 0){
                    ret -= 90.0/power(upperN+upperW);
                }
                upperN ++;
            }else if(C == 'W'){
                if(upperN == 0 && upperW == 0){
                    ret += 90;
                }else{
                    ret += 90.0/power(upperN+upperW);
                }
                upperW ++;
            }
        }

        cout<<"#"<<t+1<<" ";
        if(ret -(int)ret == 0){
            cout<<(int)ret<<endl;
        }else{
            cout<<floatToString(ret)<<endl;
        }
        arr.clear();
    }

    return 0;
}