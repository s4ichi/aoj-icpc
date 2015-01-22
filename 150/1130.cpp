#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

vector<string> m;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
bool f[21][21];

int dfs(int y, int x, int h, int w)
{
  int cnt = 1;
  for(int i=0;i<4;i++){
    int xx = x+dx[i], yy = y+dy[i];
    if(xx>=0 && xx<w && yy>=0 && yy<h){
      if(!f[yy][xx] && m[yy][xx] == '.'){
        f[yy][xx] = true;
        cnt += dfs(yy, xx, h, w);
      }
    }
  }
  return cnt;
}

int main()
{
  int h,w;
  while(cin >> w >> h,h){
    m.resize(h);
    memset(f, 0, sizeof(f));
  
    int y, x;
    for(int i=0;i<h;i++){
      cin >> m[i];
      for(int j=0;j<w;j++){
        if(m[i][j] == '@'){
          y = i;x = j;
        }
      }
    }
    f[y][x] = true;
    cout << dfs(y, x, h, w) << endl;
  }
  return 0;
}
