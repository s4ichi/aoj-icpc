#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
  int n;
  while(scanf("%d",&n),n!=0){
    vector<int> v;
    for(int i=0;i<n;i++){
      int k;
      cin >> k;
      v.push_back(k);
    }
    sort(v.begin(),v.end());

    int sum=0;
    for(int i=1;i<n-1;i++){
      sum+=v[i];
    }

    cout << sum/(v.size()-2) << endl;
  }

  return 0;
}
