#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  int x,y,s;

  while(cin >> x >> y >> s, s){
    int ans = 0;
    for(int i=0;i<=100;i++){
      int j = s - i;
      if(j == i || j < 0 || j > 100)continue;
      int p = ((i+j)*100)/(100+x);
      ans = max(ans, ((i+j)*(100+y))/100);
    }
    cout << ans << endl;
  }
  return 0;
}
