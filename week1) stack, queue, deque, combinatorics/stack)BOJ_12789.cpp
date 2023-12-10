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

bool can_push(stack<int>& st, const int head)
//스택에 push할 수 있는지 판별하는 함수
{
    if(st.size() == 0)
        return true;
    else if(st.top() > head)    //스택의 앞사람보다 우선순위가 높으면
        return true;            //가능
    else
        return false;
}

int main(){
    init();
    stack<int>st;
    int num;
    cin>>num;

    for(int i = 0; i < num; ++i){
        int head;
        cin>>head;
        if(order == head)
            ++order;
        else if(can_push(st, head))
            st.push(head);
        else{
            cout<<"Sad";
            return 0;
        }
        clean_up_stack(st);
    }
    cout<<"Nice";
}