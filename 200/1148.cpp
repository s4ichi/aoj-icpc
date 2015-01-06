#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstdio>

using namespace std;

bool g[10001][1261];

int main()
{
  int n,m;
  while(scanf("%d %d",&n,&m),n!=0 && m!=0){
    for(int i=0;i<10001;i++){
      for(int j=0;j<1261;j++){
        g[i][j]=false;
      }
    }
    map<pair<int,int>,int> time;
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
      int t,num,s,b;
      cin >> t >> num >> s >> b;
      if(b){
        time[make_pair(num,s)]=t;
      }else{
        int st=time[make_pair(num,s)];
        int ed=t;
        for(int j=st;j<ed;j++){
          g[s][j]=true;
        }
      }
    }
    cin >> k;
    for(int i=0;i<k;i++){
      int a,b,c;
      cin >> a >> b >> c;
      int tol=0;
      for(int j=a;j<b;j++){
        if(g[c][j])tol++;
      }
      cout << tol << endl;
    }
  }
  return 0;
}
