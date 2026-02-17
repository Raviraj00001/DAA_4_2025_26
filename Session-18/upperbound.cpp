
// find the upper bound of the target (equal se bda wala chaiye)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>nums={1,1,1,5,6};
    sort(nums.begin(),nums.end());
    int start=0,end=nums.size()-1,mid,ans=nums.size();
    int target=0;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(nums[mid]>target)
        {
            ans=mid;
            end=mid-1;
        }
        else if(nums[mid]<target)
        {
            start=mid+1;
        }
    }
    cout<<"the upper bound is = "<<ans;
    return 0;
}