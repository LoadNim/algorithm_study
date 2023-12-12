#include <iostream>
#include <deque>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    init();
    int N;
    cin>>N;
    bool queuestack[N]; //큐인지 스택인지 저장할 bool 배열
    for(int i = 0; i < N; ++i)
        cin>>queuestack[i];
    
    deque<int>dq;   //자료구조에 들어있는 원소를 담을 deque
    for(int i = 0; i < N; ++i)
    //queue일때만 deque의 앞쪽에 push
    {
        int input;
        cin>>input;
        if(!queuestack[i])
            dq.push_front(input);
    }

    int M;
    cin>>M;
    for(int i = 0; i < M; ++i){
    //queuestack에 삽입할 원소를 뒤쪽에다가 push
        int input;
        cin>>input;
        dq.push_back(input);
    }

    for(int i = 0; i < M; ++i)
    //새로 삽입된 원소만큼 deque의 앞쪽에서 pop
    {
        int num = dq.front();
        cout<<num<<' ';
        dq.pop_front();
    }
}