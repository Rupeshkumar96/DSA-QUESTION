#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> delete_duplicated(vector<int> arr)
{
    unordered_set<int> m;
    vector<int>result;
    for(int i=0;i<arr.size();i++)
    {
        if(m.find(arr[i])==m.end())
        {
            m.insert(arr[i]);
            result.push_back(arr[i]);
        }
    }
    return result;

}
int main()
{
    vector<int> arr={5,1,23,1,4,5,23};
    vector<int> arr1=delete_duplicated(arr);
    for(auto x:arr1)
    {
        cout<<x;
    }
    return 0;
}
