#include<iostream>
#include<algorithm>
#include<vector>
#define next(x,A,B,C) x=(A*x+B)%C

using namespace std;

int main()
{
  int n,a,b,c,x;
  while(cin >> n >> a >> b >> c >> x && n){
    int cnt = -1;
    vector<int> in(n);
    for(int i=0;i<n;i++)cin >> in[i];
    for(int i=0;i<n;i++){
      cnt++;
      while(x!=in[i]){
        next(x,a,b,c);
        cnt++;
        if(cnt>10000){
          cout << -1 << endl;
          break;
        }
      }
      if(cnt>10000)break;
      next(x,a,b,c);
    }
    if(cnt>10000)continue;
    cout << cnt << endl;
  }
  return 0;
}
