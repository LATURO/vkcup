#include<iostream>
using namespace std;
int main (){
    int n,m,k;
    cin>>n>>m>>k;
    char mas[1004][1004];
    for (size_t i = 0; i < n+2; i++) {
        for (size_t j = 0; j < m+2; j++) {
                mas[i][j]='*';
        }
    }
    int nowX,nowY;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cin>>mas[i+1][j+1];
            if(mas[i+1][j+1]=='X'){
                nowX=j+1;
                nowY=i+1;
                mas[i+1][j+1]='.';
            }
        }
    }
    if(k%2){
        cout<<"IMPOSSIBLE";
    }else{
    bool check = true;
    string answer="";
    for (size_t i = 0; i < k/2; i++) {
        if(mas[nowY+1][nowX]=='.'){
            answer+="D";
            nowY++;
        }else if (mas[nowY][nowX-1]=='.') {
            answer+="L";
            nowX--;
        }else if (mas[nowY][nowX+1]=='.') {
            answer+="R";
            nowX++;
        }else if (mas[nowY-1][nowX]=='.') {
            answer+="U";
            nowY--;
        }else{
            cout<<"IMPOSSIBLE";
            check = false;
            break;
        }
    }
    if(check){
        for (int i = k/2-1; i >= 0; i--) {
            if(answer[i]=='D'){
                answer+="U";
            }else if (answer[i]=='L') {
                answer+="R";
            }else if (answer[i]=='R') {
                answer+="L";
            }else if (answer[i]=='U') {
                answer+="D";
            }
        }
        cout<<answer;
    }
}
}
