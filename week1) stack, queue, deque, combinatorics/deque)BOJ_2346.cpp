#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int cal_dist(int next, int size)
//종이에 써진 값을 deque의 size에 맞게 수정하는 함수
{
    while(next < 0)     //종이에 음수가 써져있으면 (왼쪽으로 이동)
        next += size;   //size를 활용하여 양수로 만들어 오른쪽으로 이동할 수 있게끔 한다.
    return next % size;
}

int main(){
    init();
    int num;
    cin>>num;
    deque<pair<int, int>>dq(num); //풍선안에 있는 종이와, 원래 위치를 저장
                           
    for(int i = 0; i < num; ++i)
    //풍선안에 있는 종이를 입력받음
    {
        cin>>dq[i].first;
        if(dq[i].first > 0)     //풍선을 터트리고 이동하기에, 종이의 수가 자연수라면
            --dq[i].first;      //미리 이동한 꼴이 되니 종이의 수를 1 감소
        dq[i].second = i + 1;
    }

    for(int i = 0; i < num - 1; ++i)
    //풍선을 터트리고 이동하는 과정
    {
        cout<<dq[0].second<<' ';
        int next = dq[0].first;
        dq.erase(dq.begin());
        next = cal_dist(next, dq.size());
        rotate(dq.begin(), dq.begin() + next, dq.end());    //다음 터트릴 풍선을 begin()으로 회전
    }
    cout<<dq[0].second;
}