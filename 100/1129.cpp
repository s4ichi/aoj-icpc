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
  int n,r;
  while(cin >> n >> r,n){
    int k[51][2];
    int num = n;
    for(int i=1;num>0;i++)k[i][0] = num--;

    for(int i=0;i<r;i++){
      int p,c,cnt = 1;
      cin >> p >> c;

      for(int j=p;j<p+c;j++){
        k[cnt++][(i+1)%2] = k[j][i%2];
      }
      for(int j=1;j<p;j++){
        k[cnt++][(i+1)%2] = k[j][i%2];
      }
      for(int j=c+p;j<=n;j++){
        k[cnt++][(i+1)%2] = k[j][i%2];
      }

    }
    cout << k[1][r%2] << endl;
  }

  return 0;
}
