#include<iostream>
#include<set>
#include<list>

using namespace std;

list<int> map[1001];
int N;

int main(){

    int T;
    cin>>T;

    for(int t=0;t<T;t++){
        cin>>N;
        for(int i=0;i<N;i++){
            int a,b;
            cin>>a;
            cin>>b;
            map[a].push_back(b);
            map[b].push_back(a);
        }

        while(1){
            bool find = false;
            for(int i=1;i<=N;i++){
                if(map[i].size() == 1){
                    int other = map[i].front();
                    map[i].pop_front();
                    map[other].remove(i);
                    find = true;
                 }
            }
            if(!find){
                break;
            }
        }

        int result = 0;
        for(int i=1;i<=N;i++){
            if(map[i].size() > 1){
                result++;
            }
        }

        cout<<"#"<<t+1<<" "<<result<<endl;
        for(int i=1;i<=N;i++){
            map[i].clear();
        }
    }
    return 0;
}