// Experiment–3: Stable Attendance Window
// Problem Statement
// A university maintains an automated log of attendance activities recorded in order.
// Each record represents a student being Present (P) or Absent (A).
// A stable attendance window is defined as a continuous period in which:
// The number of Present and Absent records are equal.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int N;//number of inputs;
    cin>>N;
    vector<char> arr(N);//for present and absent
    unordered_map<int,int>mp;//to store sum and index
    mp[0]=0;
    int sum=0;
    int maxlen=0;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int j=0;j<N;j++){
        if(arr[j]=='P'){
            sum--;
        }
        else{
            sum++;
        }
        if(mp.find(sum)!=mp.end()){
            maxlen=max(maxlen,j-mp[sum]);
        }
        else{
            mp[sum]=j;
        }
    }
    cout<<maxlen<<endl;//printing the maximum lenghth
    return 0;
}
