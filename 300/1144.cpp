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
#define INIT 1<<27

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

int ma[21][21];

int w, h;

int walk(int cnt, int y, int x)
{
	if (cnt == 11) return -1;

	//cout << endl;
	//DUMP(cnt);
	//DUMP(y);
	//DUMP(x);


	int by = y, bx = x, cur = INIT;
	//up
	if (y - 1 >= 0) {
		if (ma[y-1][x] != 1) {
			while (1) {
				if (y < 0 || y >= h) break;

				if(ma[y][x] == 0) {
					y--;
				} else if (ma[y][x] == 1) {
					//cout << "up" <<  endl;
					ma[y][x] = 0;
					int ret = walk(cnt+1, y+1, x);
					if(ret != -1) cur = min (cur, ret);
					ma[y][x] = 1;
					break;
				} else if (ma[y][x] == 3) {
					//cout << "ug" << endl;
					return cnt;
				}
			}
		}
	}

	y = by; x = bx;

	//down
	if (y + 1 < h) {
		if (ma[y+1][x] != 1) {
			while (1) {
				if (y < 0 || y >= h) break;

				if(ma[y][x] == 0) {
					y++;
				} else if (ma[y][x] == 1) {
					//cout << "down" <<  endl;
					ma[y][x] = 0;
					int ret = walk(cnt+1, y-1, x);
					if (ret != -1) cur = min(cur, ret);
					ma[y][x] = 1;
					break;
				} else if (ma[y][x] == 3) {
					//cout << "dg" << endl;
					return cnt;
				} else {
					break;
				}
			}
		}
	}

	y = by; x = bx;

	//left
	if(x - 1 >= 0) {
		if (ma[y][x-1] != 1) {
			while (1) {
				if (x < 0 || x >= w) break;

				if(ma[y][x] == 0) {
					x--;
				} else if (ma[y][x] == 1) {
					//cout << "left" <<  endl;
					ma[y][x] = 0;
					int ret = walk(cnt+1, y, x+1);
					if (ret != -1) cur = min(cur, ret);
					ma[y][x] = 1;
					break;
				} else if (ma[y][x] == 3) {
					//cout << "lg" << endl;
					return cnt;
				} else {
					break;
				}
			}
		}
	}

	y = by; x = bx;

	//right
	if (x + 1 < w) {
		if (ma[y][x+1] != 1) {
			while (1) {
				if (x < 0 || x >= w) break;

				if(ma[y][x] == 0) {
					x++;
				} else if (ma[y][x] == 1) {
					//cout << "right" <<  endl;
					ma[y][x] = 0;
					int ret = walk(cnt+1, y, x-1);
					if (ret != -1) cur = min(cur, ret);
					ma[y][x] = 1;
					break;
				} else if (ma[y][x] == 3) {
					//cout << "rg" << endl;
					return cnt;
				}
			}
		}
	}

	if (cur == INIT) return -1;
	return cur;
}

int main()
{
	while (cin >> w >> h, w || h) {
		int x, y;
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) {
				cin >> ma[i][j];

				if (ma[i][j] == 2) {
					y = i;
					x = j;
				}
			}
		}
		ma[y][x] = 0;
		cout << walk(1, y, x) << endl;
	}
	return 0;
}
