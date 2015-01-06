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

int main()
{
  int n,m;
  while(cin >> n >> m,n){
    vi t(n),h(m);
    int sum_t=0, sum_h=0;
    for(int i=0;i<n;i++){
      cin >> t[i];
      sum_t += t[i];
    }
    for(int i=0;i<m;i++){
      cin >> h[i];
      sum_h += h[i];
    }

    int ans_t = 101, ans_h = 101;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(sum_t - t[i] + h[j] == sum_h - h[j] + t[i] && ans_t + ans_h > t[i] + h[j]){
          ans_t = t[i];
          ans_h = h[j];
        }
      }
    }
    if(ans_t == 101){
      cout << -1 << endl;
    }else{
      cout << ans_t << " " << ans_h << endl;
    }

  }

  return 0;
}
