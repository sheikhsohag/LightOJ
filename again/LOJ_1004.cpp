#include<iostream>
#include<vector>

using namespace std;
typedef int long long ll;


ll maximumbanana(vector<vector<int>>&table,vector<vector<int>>&dp,int n,int m)
{
    if(n<=0||m<=0) return 0;

    if(dp[n][m]!=-1) return  dp[n][m];
    
    return dp[n][m]=max(maximumbanana(table,dp,n-1,m-1),maximumbanana(table,dp,n-1,m)) + table[n][m];
}


int main()
{

    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
               int n,m,ini=1,en=0;
      cin>>n;
       m=2*n-1;
       vector<vector<int> >table(m+3,vector<int>(n+3,-1)),dp(m+3,vector<int>(n+3,-1));
       for(int i=1;i<=m;i++)
       {
        if(i>n)
        ini++;

        if(i<=n) en++;
        for(int j=ini;j<=en;j++)
        {
            int a;
            cin>>a;
            table[i][j]=a;
        }
       }

       printf("Case %d: ",tc);

       cout<<maximumbanana(table,dp,m,n)<<endl;
       

    }
  

      
      /* for(int i=0;i<=m;i++)
       {
        for(int j=0;j<=n;j++)
        cout<<table[i][j]<<" ";
        cout<<endl;
       }*/
}