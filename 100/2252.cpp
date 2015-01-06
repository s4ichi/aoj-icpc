//-------------include
//#include<bits/stdc++.h>
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
inline int toInt(string s) {int v; istringstream istr(s);istr>>v;return v;}
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
  string A = "qwertasdfgzxcvb";
  string in;

  while(cin >> in, in!="#"){
    int sw = -1,cnt = -1;
    for(int i=0;i<in.size();i++){
      if(A.find(in[i],0) == string::npos && sw != 1){
        cnt++;
        sw = 1;
      }else if(sw != 0 && A.find(in[i],0) != string::npos){
        cnt++;
        sw = 0;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
