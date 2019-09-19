#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct node {
    string val;
    int left;
    int right;
};

// 哭率, 啊款单, 坷弗率
void infix(node* map,node Node){

    if(Node.left != 0){
        infix(map, map[Node.left]);
    }
    cout<<Node.val;
    if(Node.right != 0){
        infix(map, map[Node.right]);
    }
}

int main() {
    for(int t=0;t<10;t++){
        int N;
        cin >> N;
        auto arr = new node[N+1];
        string temp;
        getline(cin,temp);
        for(int i=1;i<=N;i++){
            string str;
            getline(cin,str);

            int idx = 0;
            string val[4] = {"0","0","0","0"};
            string tempchar = "";
            for(int j=0;j<str.size();j++){
                if(str[j]==' '){
                    val[idx++] = tempchar;
                    tempchar = "";
                    continue;
                }
                tempchar = tempchar + str[j];
            }
            arr[stoi(val[0])].val = val[1];
            arr[stoi(val[0])].left = stoi(val[2]);
            arr[stoi(val[0])].right = stoi(val[3]);
           // cout<<endl<<"INPUT: "<<" "<<val[2]<<" "<<val[3];
        }
        infix(arr,arr[1]);
        cout<<endl;
    }
}