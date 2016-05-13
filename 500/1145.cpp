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

string s;
int n;
int ind;

int scan_int()
{
	string s_num = "";
	int i = ind;
	while (s[i] >= '0' && s[i] <= '9') {
		s_num += s[i++];
	}
	ind = i;
	return toInt(s_num);
}

string scan_str()
{
	string s_num = "";
	int i = ind;
	while (s[i] >= 'A' && s[i] <= 'Z') {
		s_num += s[i++];
	}
	ind = i;
	return s_num;
}

string solve()
{
	string ret = "";

	if(s[ind] >= 'A' && s[ind] <= 'Z') {
		ret = scan_str();

	} else if (s[ind] >= '0' && s[ind] <= '9') {
		int cur = scan_int();
		string target;

		if (s[ind] == '('){
			ind++;
			target = solve();
			ind++;
		} else {
			target = s[ind++];
		}

		for (int i=0; i<cur; i++) {
			if(ret.size() > n) {
				return ret;
			}
			ret += target;
		}

	} else {
		return "";
	}

	ret += solve();
	return ret;
}

int main()
{
	while (1) {
		cin >> s >> n;
		if (s == "0" && !n)break;
		ind = 0;
		string ans = solve();
		//DUMP(ans);
		if(ans.size() <= n) cout << 0 << endl;
		else cout << ans[n] << endl;
	}

	return 0;
}
