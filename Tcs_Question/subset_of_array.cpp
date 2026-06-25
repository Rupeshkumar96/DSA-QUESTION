#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool issubset(vector<int>m,vector<int>n)
{
    unordered_map<int,int> s;
    for(auto a:m) s[a]++;
    for(auto b:n)
    {
        if(s[b]==0)
        {
            return false;
        }
        s[b]--;
    }
    return true;
}
int main()
{
    vector<int> m={1,2,4,5,1,7,8};
    vector<int> n={1,2,4,1};
    bool arr=issubset(m,n);
    cout<<arr;
    return 0;
}
