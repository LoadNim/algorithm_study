#include <iostream>
#include <stack>
using namespace std;

int order = 1;  //현재 입장해야되는 학생의 번호
void init()
//cin, cout의 속도를 빠르게 해주기 위함
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void clean_up_stack(stack<int>& st)
//스택에 있는 학생을 입장시키는 함수
{
    while(st.size() && st.top() == order)
    //스택이 비거나, 맨 앞 학생이 입장할 차례가 아닐 때까지 입장시킴
    {
        st.pop();
        ++order;
    }
}

bool can_push(stack<int>& st, const int input)
//스택에 push할 수 있는지 판별하는 함수
{
    if(st.size() == 0)          //스택이 비어있으면
        return true;            //가능
    else if(st.top() > input)   //스택의 앞사람보다 우선순위가 높으면
        return true;            //가능
    else                        //스택에 세울 수 없음
        return false;
}

int main(){
    init();
    stack<int>st;   //순서가 아닌 학생들이 대기할 스택
    int N;          //학생들의 수
    cin>>N;

    for(int i = 0; i < N; ++i){
        int input;          //줄의 맨 앞사람을 입력받음
        cin>>input;
        if(order == input)  //만약 줄의 맨 앞사람이 입장할 차례면
            ++order;        //입장해야될 학생의 번호를 증가
        else if(can_push(st, input))    //스택에 push여부 판별 후
            st.push(input);             //스택에 push
        else
        //간식을 받을 수 없음
        {
            cout<<"Sad";
            return 0;
        }
        clean_up_stack(st); //스택에 있는 사람들을 입장시킴
    }
    cout<<"Nice";
}