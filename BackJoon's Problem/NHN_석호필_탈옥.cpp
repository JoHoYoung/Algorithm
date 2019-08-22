#include <iostream>
#include <algorithm>
#include "cmath"
using namespace std;

struct Node{
    int X;
    int Y;
    int Radius;
    int Id;
    Node* parents;
};

int ABS(int a){
    if(a > 0){
        return a;
    }
    return -a;
}

void isInner(Node &Larger, Node &Smaller){
    if(Smaller.parents -> Id != 300){
        return;
    }

    int width = ABS(Larger.X - Smaller.X);
    int height = ABS(Larger.Y - Smaller.Y);

    int disto =Larger.Radius + Smaller.Radius;
    int dist = width*width + height*height;

    // 아예 상관없는 두 원.
    if(disto*disto < dist) {
        return;
    }else{
        Smaller.parents = &Larger;
        return;
    }
};

bool compare(Node a,Node b){
    if (a.Radius > b.Radius){
        return true;
    }
    return false;
}

int main(int argc, char* argv[]) {

    int Num;
    cin>>Num;
    Node Root;
    Root.X = 10000;
    Root.Y = 10000;
    Root.Radius = 200000;
    Root.Id = 300;

    Node Nodes[Num];
    // 0 : x, 1 : y, 3 : r
    for(int i=0;i<Num;i++){
        int a;
        cin>>a;
        cin >> Nodes[i].X;
        cin >> Nodes[i].Y;
        cin >> Nodes[i].Radius;
        Nodes[i].Id = i;
        Nodes[i].parents = &Root;
    }

    sort(Nodes, Nodes + Num, compare);
    int start, end;

    cin>>start;
    cin>>end;

    for(int i=1;i<Num;i++){
        for(int j=i-1;j>=0;j--){
            isInner(Nodes[j],Nodes[i]);
        }
    }
    int Ts[100];
    int Te[100];

    Node *s = &Nodes[start-1];
    int sidx = 0;

    Node *e = &Nodes[end -1];
    int eidx = 0;

    for(int i=0;i<Num;i++){
        if(Nodes[i].Id == start-1){
            s = &Nodes[i];
        }
        if(Nodes[i].Id == end-1){
            e = &Nodes[i];
        }
    }

    while(1) {
        Ts[sidx++] = s->Id;
        s = s->parents;
        if(s == &Root){
            Ts[sidx++] = -1;
            break;
        }
    }
    while(1) {
        Te[eidx++] = e->Id;
        e = e->parents;
        if(e == &Root){
            Te[eidx++] = -1;
            break;
        }
    }
//    for(int i=0;i<sidx;i++){
//        cout<<Ts[i]<< " ";
//    }
//    cout<<endl;
//    for(int i=0;i<eidx;i++){
//        cout<<Te[i]<< " ";
//    }

    int i=0;
    int j=0;
    for(;i<sidx;i++){
        bool find = false;
        j=0;
        for(;j<eidx;j++){
            if(Ts[i] ==Te[j]){
                find = true;
                break;
            }
        }
        if(find){
            break;
        }
    }
    for(int q=0;q<i;q++){
        cout<<Ts[q]+1<<" ";
    }
    for(int q=j;q>=0;q--){
        cout<<Te[q]+1<<" ";
    }
    return 0;
}