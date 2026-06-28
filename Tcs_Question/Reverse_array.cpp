#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse_array(vector<int> arr)
{
    int left=0;
    int right=arr.size()-1;
    while(left<right)
    {
        int temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
         left++;
         right--;
    }
    return arr;
}
int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    arr=reverse_array(arr);
    for(int x:arr)
    {
        cout<<x<<" ";
    }
    return 0;
}
