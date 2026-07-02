#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
unordered_map<int,int> repeating_Element(vector<int> arr)
{
    unordered_map<int,int>m;
    for(auto x:arr)
    {
        m[x]++;
    }
    return m;
}
int main()
{
    vector<int> arr={1,2,3,4,5,8,2,3,1,4};
    unordered_map<int,int>m=repeating_Element(arr);
    for(auto x:m)
    {
        if(x.second>1) cout<<x.first<<" ";

    }
    return 0;
}
