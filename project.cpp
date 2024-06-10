#include <bits/stdc++.h>

using namespace std;
 int bs(int low,int high,int value,vector<vector<int>>&v){
     int ind=-1;
     while(high>=low){
         int mid=(high+low)/2;
         if(v[mid][1]<=value){
             ind=mid;
             high=mid-1;
         }
         else low=mid+1;
     }
     return ind;
 }
int main() {
    int n;
   cin>>n;
   vector<vector<int>>v;
   for(int i=0;i<n;i++){
        int ui,vi,cost;
         cin>>ui>>vi>>cost;
         vector<int>temp={vi,ui,cost};
         v.push_back(temp);
   }
   sort(v.begin(),v.end());
   for(int i=0;i<n;i++){
       swap(v[i][0],v[i][1]);
   }
   vector<int>dp(n+1,0);
   for(int i=0;i<n;i++){
       int ind=bs(0,i-1,v[i][0],v);
       if(ind==-1) dp[i]=v[i][2];
       else {
           dp[i]=dp[ind]+v[i][2];
       }
   }
   
 cout<<*max_element(dp.begin(),dp.end());
 return 0;
}
