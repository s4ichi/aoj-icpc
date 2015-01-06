//-------------include
#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<vector>
#include<list>
#include<deque>
#include<functional>
#include<sstream>

//-------------define
#define ALL(a)  (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define SORT(c) sort((c).begin(),(c).end())
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define CLR(a) memset((a), 0 ,sizeof(a))
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define fi first
#define se second
#define INF 1 << 28

//-------------namespace
using namespace std;

//-------------inline
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//-------------typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;

//-------------var
int dx[]={0,-1,0,1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};

int l[201][201];
int s[201][201];
int dp[1001][201];

int main()
{
  int n,m;
  while(cin >> n >> m,n){
    for(int i=0;i<200;i++){
      s[i][i] = l[i][i] = 0;
      for(int j=0;j<200;j++){
        if(i!=j)s[i][j] = l[i][j] = INF;
      }
    }

    for(int i=0;i<1000;i++){
      for(int j=0;j<200;j++){
        dp[i][j] = INF;
      }
    }

    for(int i=0;i<m;i++){
      int a,b,t;
      char p;
      cin >> a >> b >> t >> p;
      a--;b--;
      if(p=='S'){
        s[a][b] = s[b][a] = t;
      }else{
        l[a][b] = l[b][a] = t;
      }
    }

    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          s[i][j] = min(s[i][j], s[i][k] + s[k][j]);
          l[i][j] = min(l[i][j], l[i][k] + l[k][j]);
        }
      }
    }

    int r;
    cin >> r;

    vi v(r);
    for(int i=0;i<r;i++){
      cin >> v[i];
      v[i]--;
    }

    dp[0][v[0]] = 0;
    for(int i=1;i<r;i++){
      for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
          dp[i][k] = min(dp[i][k], dp[i-1][j] + l[v[i-1]][j] + s[j][k] + l[k][v[i]]);
        }
        dp[i][j] = min(dp[i][j], dp[i-1][j] + l[v[i-1]][v[i]]);
      }
    }

    int ans = INF;
    for(int i=0;i<n;i++){
      ans = min(ans, dp[r-1][i]);
    }
    cout << ans << endl;
  }
  return 0;
}
