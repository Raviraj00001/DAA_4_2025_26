#include <bits/stdc++.h>
using namespace std;


void complexRec(int n) {

    int f=0;
   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           f++;
       }
       p >>= 1;
   }
   cout<<"F:"<<f<<endl;
   f=0;


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
         f++;
   }
    cout<<"F:"<<f<<endl;


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
}
int main() {
   int n = 16;
   complexRec(n);
   return 0;
}
//RECURRENCE RELATION - T(N)= 3T(N/2)+ NlogN
//time complexity by me- n^(log2(3))
// a=3 b=2 d= log2(3) >1
