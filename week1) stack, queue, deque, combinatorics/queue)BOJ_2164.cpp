#include <iostream>
#include <queue>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    init();
    int N;
    cin>>N;
    queue<int>q;

    for(int i = 1; i <= N; ++i)
        q.push(i);
    
    while(q.size() != 1){
        int temp;
        q.pop();            //맨 위 카드 뽑기
        temp = q.front();   //맨 위 카드 저장
        q.pop();            //맨 위 카드 뽑기
        q.push(temp);       //아래에 옮기기
    }
    cout<<q.front();
}