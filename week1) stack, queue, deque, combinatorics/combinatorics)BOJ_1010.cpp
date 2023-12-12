#include <iostream>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    init();
    int T;
    cin>>T;

    for(int i = 0; i < T; ++i){
        int n, r;
        cin>>r>>n;
        int temp = 1;
        int result = 1;
        while(r >= temp){
            result *= n--;
            result /= temp++;
        }
        cout<<result<<'\n';
    }
}