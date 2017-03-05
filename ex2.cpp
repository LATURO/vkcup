#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool retard(int a,int b){return a>b;}
int main ()
{
    int n;
    cin>>n;
    vector<int>myVec(n);
    cin>>myVec[0];
    int yepOrNot = myVec[0];
    for (size_t i = 1; i < myVec.size(); i++) {
        cin  >> myVec[i];
        yepOrNot+=myVec[i]-1;
    }
    if(yepOrNot>=0&&myVec[0]){
        cout<<n-1<<endl;
        vector<int>indexes(n);
        for (size_t i = 0; i < n; i++) {
            indexes[i]=i+1;
        }
        for (size_t i = 1; i < n; i++) {
            for (size_t j = 1; j < n-1; j++) {
                if (myVec[j]<myVec[j+1]){
                    swap(myVec[j],myVec[j+1]);
                    swap(indexes[j],indexes[j+1]);
                }
            }
        }

        int lastest = 1;
        //тут предел перед адом
        for (int alpha = 0;lastest<n;alpha++) {
            for (;myVec[alpha];) {
                if(lastest>n)
                    break;
                else{
                    cout<<indexes[alpha]<<" "<<indexes[lastest]<<endl;
                    lastest++;
                    myVec[alpha]--;
                }
            }
        }




    }else{
        cout<<-1;
    }
}
