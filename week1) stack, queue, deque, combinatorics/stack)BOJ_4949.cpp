#include <iostream>
#include <string>
using namespace std;

char is_equal()
//괄호의 짝이 맞는지 재귀를 활용해 검사하는 함수
{
    char input;
    cin>>input;
    switch(input){
        case '(':{
            char x = is_equal();
            if(x != ')')        //닫는 소괄호가 아니면
                return 'x';     //잘못된 문장
            return is_equal();  //맞다면 다시 재귀호출
        }
        case ')':
            return ')';
        case '[':{
            char x = is_equal();
            if(x != ']')
                return 'x';
            return is_equal();
        }
        case ']':
            return ']';
        case '.':
            return '.';
        default:
            return is_equal();
    }
}

int main(){
    char input;
    while(cin.get(input) && input != '.'){
        cin.putback(input);
        char plag = is_equal();
        if(plag == 'o' || plag == '.')
            cout<<"yes\n";
        else
            cout<<"no\n";
        cin.ignore(101,'\n');   //입력 스트림에 남은 값을 비움
    }
}