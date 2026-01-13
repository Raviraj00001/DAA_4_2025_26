#include <bits/stdc++.h>
using namespace std;


void complexRec(int n) {


   if (n <= 2) {
       return;
   }
int count=0;//counter

   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
         count++;
       }
       p >>= 1;
cout<<"count="<<count<<endl;
   }

   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       count++;
   }
cout<<"count="<<count<<endl;

   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
}
int main(){
   int n=18;
    complexRec(n);
}
//Recurrence relation=3T(n/2)+nlogn
//Time Complexity is n^log2(3)
//