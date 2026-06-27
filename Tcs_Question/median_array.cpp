#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int median(vector<int> arr)
{
    int med=0;
    sort(arr.begin(),arr.end());
    int n=arr.size();
    if(n%2==1)
    {
        med=arr[(n/2)];
    }
    else{
        med=arr[(n/2)]+arr[(n/2)-1];
        return med/2;
    }
    return med;
}
int main()
{
    vector<int> arr={4,7,8,9,5,1,2,3};
    cout<<median(arr);
    return 0;
}
