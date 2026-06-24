#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int,int> count_freq(vector<int> arr)
{
    map<int,int> freq;
    for(auto x:arr)
    {
        freq[x]++;
    }
    return freq;

}
int main()
{
    vector<int> arr={1,2,3,2,5,3,7,3};
    map<int,int> arr1=count_freq(arr);
    for(auto x:arr1)
    {
        cout<<x.first<<"->"<<x.second<<endl;
    }
    return 0;
}
