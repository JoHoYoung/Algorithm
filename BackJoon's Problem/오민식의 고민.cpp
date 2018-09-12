//문제 1219 오민식의 고민
//오민식은 세일즈맨이다. 오민식의 회사 사장님은 오민식에게 물건을 최대한 많이 팔아서 최대 이윤을 남기라고 했다.
//
//오민식은 고민에 빠졌다.
//
//어떻게 하면 최대 이윤을 낼 수 있을까
//
//이 나라에는 N개의 도시가 있다. 도시는 0번부터 N-1번까지 번호 매겨져 있다.
// 오민식의 여행은 A도시에서 시작해서 B도시에서 끝난다.
//
//오민식이 이용할 수 있는 교통수단은 여러 가지가 있다. 오민식은 모든 교통수단의
// 출발 도시와 도착 도시를 알고 있고, 비용도 알고 있다. 게다가, 오민식은 각각의
// 도시를 방문할 때마다 벌 수 있는 돈을 알고있다. 이 값은 도시마다 다르며, 액수는
// 고정되어있다. 또, 도시를 방문할 때마다 그 돈을 벌게 된다.
//
//오민식은 도착 도시에 도착할 때, 가지고 있는 돈의 액수를 최대로 하려고 한다. 이
// 최댓값을 구하는 프로그램을 작성하시오.
//
//오민식이 버는 돈보다 쓰는 돈이 많다면, 도착 도시에 도착할 때 가지고 있는 돈의 액수가
// 음수가 될 수도 있다. 또, 같은 도시를 여러 번 방문할 수 있으며, 그 도시를 방문할 때마다
// 돈을 벌게 된다. 모든 교통 수단은 입력으로 주어진 방향으로만 이용할 수 있으며, 여러번 이용할 수도 있다.
#include<iostream>
#include <cstdio>
#include <vector>
struct Edge {
    int s, e, pr;
};
using namespace std;
long long INF = 2147483647L * 214214214;
int main () {
    int N, startCity, endCity, M;
    scanf("%d%d%d%d", &N, &startCity, &endCity, &M);
    long long *d = new long long[N];
    long long *p = new long long[N];
    for (int i = 0; i < N; i++) {
        d[i] = -INF;
    }
    //d라는 배열은 -INF다
    Edge edge;
    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        int S, E, P;
        scanf("%d%d%d", &S, &E, &P);
        edge.s = S; edge.e = E; edge.pr = -P;
        edges.push_back(edge);
    }

    //간선 정보를 edges에 모두푸쉬, edge.s, e, p
    for (int i = 0; i < N; i++) {
        scanf("%lld", &p[i]);
    }

    //p라는 배열은 어떤 도시에 방문했을때 얻게되는 돈.
    //d 라는 배열은 어떤도시에 방문하는 경우,의 돈의 최댓값? 정도인듯
    d[startCity] = p[startCity];

    bool gee = false;
    for (int k = 0; k < 2; k++) {  //두번 돌린다.
        cout<<"k번째 시도.";
        for (int i = 0; i < N; i++) {      //경로의 갯수만큼 N번 돌린다...
            for (int j = 0; j < M; j++) { //경로의 갯수 ,edge의 갯수
                int s = edges[j].s; int e = edges[j].e; int pr = edges[j].pr; //간선정보 갯수만큼 계속꺼내온다...
                if (d[s] == -INF) continue;   //지금 간선의 시작지(?)로 갈 수 없으면 무시
                else if (d[s] == INF) d[e] = INF;  //시작점으로 가는 경우의 코스트가 무한대이면 도착지로 가는 코스트도 무한대(?? 왜지)
                else if (d[e] < d[s] + p[e] + pr) { //무한대가 아니고, 지금꺼내온 간선의 시작지로 갈 수 있으면 거기 시작지로 갔을때 비용 + 도시에서주는 돈 + 교통비.
                    d[e] = d[s] + p[e] + pr;
                    if (k) d[e] = INF;    //k가 1이면 무한대로... 두번돌릴때 즉 두번째 돌리는 시도일때 값이 갱신되면 무한대로.
                            //갱신 된다는 것은 d[e]가 더 작을때, 즉 값이 더 큰게 생긴다는 것이니까 돌수록 점점 늘어나게 됨. 무한대로수렴 그러니까 GG
                                    //한번 더 돌렸을때 거기로 도착하는것이 늘어나면 계속 늘어날테니까 무한대이고
                                            // 줄어 들면 한번더 돌릴필요가 없고, 최대값을 출력해야하니까 고려하지 않는것.
                                                    //값이 -로 내려가는것은.. 한번만 돌았을때가 최대값. 최대값을 구하는 문제이기 때문임.
                                                            // +로 증가하는것은 계속증가할테니까 INF가 되는것.
                }
            }
        }
    }
    if (d[endCity] == -INF) printf("gg");
    else if (d[endCity] == INF) printf("Gee");
    else printf("%lld", d[endCity]);
}
