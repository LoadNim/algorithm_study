#include <iostream>
#include <string>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
}

struct Node
//deque 컨테이너를 구성할 노드
{
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct list{
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
}deque;

bool isempty();

void push_front(int data)
//deque의 앞에 정수를 넣음
{
    Node* newnode = new Node;
    newnode->data = data;

    if(isempty()){
        deque.head = newnode;
        deque.tail = newnode;
    }
    else{
        newnode->next = deque.head;
        deque.head->prev = newnode;
        deque.head = newnode;
    }
    ++deque.size;
}

void push_back(int data)
//deque의 뒤에 정수를 넣음
{
    Node* newnode = new Node;
    newnode->data = data;

    if(isempty()){
        deque.head = newnode;
        deque.tail = newnode;
    }
    else{
        newnode->prev = deque.tail;
        deque.tail->next = newnode;
        deque.tail = newnode;
    }
    ++deque.size;
}

void pop_front()
//deque의 맨 앞의 정수를 뺌
{
    if(isempty())
        cout<<"-1\n";
    else if(deque.size == 1)
    //런타임 에러를 방지하기 위해 구분
    {
        cout<<deque.head->data<<'\n';
        delete deque.head;
        --deque.size;
    }
    else{
        Node* delnode = deque.head;
        deque.head = deque.head->next;
        deque.head->prev = nullptr;
        cout<<delnode->data<<'\n';
        delete delnode;
        --deque.size;
    }
}

void pop_back()
//deque의 맨 뒤의 정수를 뺌
{
    if(isempty())
        cout<<"-1\n";
    else if(deque.size == 1){
        cout<<deque.tail->data<<'\n';
        delete deque.tail;
        --deque.size;
    }
    else{
        Node* delnode = deque.tail;
        deque.tail = deque.tail->prev;
        deque.tail->next = nullptr;
        cout<<delnode->data<<'\n';
        delete delnode;
        --deque.size;
    }
}

bool isempty()
//deque이 비었는지 확인
{
    if(deque.size)
        return false;
    else
        return true;
}

void peek_front()
//deque의 맨 앞 정수를 출력
{
    if(isempty())
        cout<<"-1\n";
    else
        cout<<deque.head->data<<'\n';
}

void peek_back()
//deque의 맨 뒤 정수를 출력
{
    if(isempty())
        cout<<"-1\n";
    else
        cout<<deque.tail->data<<'\n';
}

int main(){
    init();
    int N;
    cin>>N;

    for(int i = 0; i < N; ++i)
    //명령을 입력받는 반복문
    {
        char command;
        cin>>command;
        switch(command){
            case '1':{
                string data;    //command에 1이 들어오면
                cin>>data;      //입력스트림에 남아있는 정수를 받아옴
                push_front(stoi(data));
                break;
            }
            case '2':{
                string data;    //command에 2가 들어오면
                cin>>data;      //입력스트림에 남아있는 정수를 받아옴
                push_back(stoi(data));
                break;
            }
            case '3':
                pop_front();
                break;
            case '4':
                pop_back();
                break;
            case '5':
                cout<<deque.size<<"\n";
                break;
            case '6':
                if(isempty()) 
                    cout<<"1\n";
                else
                    cout<<"0\n";
                break;
            case '7':
                peek_front();
                break;
            default:
                peek_back();
                break;
        }
    }
}