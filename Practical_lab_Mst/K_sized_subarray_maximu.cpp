class Solution {
  public:
   int maxi(vector<int>&arr,int i,int j){
      int maxi2=-1;
     for(int k=i;k<j;k++){
          maxi2=max(arr[k],maxi2);
        }
     return maxi2;
  }
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        if(k==1){
            return arr;
        }
        vector<int>v;
        
        for(int i=0;i<arr.size()-k+1;i++){
            int maxi1=maxi(arr,i,k+i);
            v.push_back(maxi1);
        }
        return v;
        
    }
};