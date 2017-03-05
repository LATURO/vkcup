#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
    int size;
    cin>>size;
    vector<int>vec(size);
    for (size_t i = 0; i < vec.size(); i++) {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    if(size==1)
        cout<<vec[0];
    else if(size==3)
        cout<<vec[1];
    else
        cout<<vec[2];
}
