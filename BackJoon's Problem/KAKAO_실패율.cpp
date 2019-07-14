#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<pair<int, float>> p;

int Count[200001];
bool compare(pair<int, float> a, pair<int, float> b){

    if (a.second == b.second)
    {
        return a.first<b.first;
    }
    return a.second>b.second;

}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    for(int i=0;i<stages.size();i++){
        Count[stages[i]]+=1;
    }

    int now = 0;
    for(int i=1;i<N+1;i++){

        int under = (int)stages.size() - now;
        if(under != 0){
            int up = Count[i];
            float percent = ((float)up/under);
            pair<int, float> r = make_pair(i,percent);
            p.push_back(r);
            now += Count[i];
            continue;
        }
        p.push_back(make_pair(i,0.f));
    }
    sort(p.begin(),p.end(),compare);
    for(int i=0;i<p.size();i++){
        answer.push_back(p[i].first);
    }
    return answer;
}

int main(){
    vector<int> a;
    a.push_back(3);
    a.push_back(4);
    a.push_back(2);
    a.push_back(1);
    a.push_back(5);
    solution(5,a);

    for(int i=0;i<5;i++){
        printf("%d ", a[i]);
    }
    return 0;
}
