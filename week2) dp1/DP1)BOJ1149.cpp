#include <iostream>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    init();
    int N;
    cin>>N;
    
    int cost[N][3];
    for(int i = 0; i < N; ++i)
        for(int r = 0; r < 3; ++r)
        //각 집을 칠하는 비용을 저장하는 반복문
            cin>>cost[i][r];

    int total_cost[N][3];
    total_cost[0][0] = cost[0][0];
    total_cost[0][1] = cost[0][1];
    total_cost[0][2] = cost[0][2];

    for(int i = 1; i < N; ++i)
    //각 집을 칠할 때, 그 색의 최소비용을 구하는 반복문
    {
        total_cost[i][0] = total_cost[i-1][1] <= total_cost[i-1][2] ? total_cost[i-1][1] : total_cost[i-1][2];
        total_cost[i][1] = total_cost[i-1][0] <= total_cost[i-1][2] ? total_cost[i-1][0] : total_cost[i-1][2];
        total_cost[i][2] = total_cost[i-1][0] <= total_cost[i-1][1] ? total_cost[i-1][0] : total_cost[i-1][1];

        for(int r = 0; r <3; ++r)
            total_cost[i][r] += cost[i][r];
    }
    int result = total_cost[N-1][0] <= total_cost[N-1][1] ? total_cost[N-1][0] : total_cost[N-1][1];
    result = result <= total_cost[N-1][2] ? result : total_cost[N-1][2];
    cout<<result;
}