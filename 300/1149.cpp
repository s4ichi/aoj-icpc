#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstdio>
#define mp make_pair
#define pb push_back
using namespace std;

vector<pair<int,pair<int,int> > > v;

int main()
{
  int n,w,d;
  while(scanf("%d%d%d",&n,&w,&d),w!=0){
    v.clear();
    v.pb(mp(w*d,mp(w,d)));
    for(int i=0;i<n;i++){
      int k,c;
      cin >> k >> c;
      k--;
      while(c>v[k].second.first+v[k].second.second)
        c-=v[k].second.first+v[k].second.second;
      pair<int,pair<int,int> > h1,h2;
      if(v[k].second.first-c>0){
        h1.second.first=abs(v[k].second.first-c);
        h1.second.second=v[k].second.second;
        h1.first=h1.second.first*h1.second.second;

        h2.second.first=v[k].second.first-h1.second.first;
        h2.second.second=v[k].second.second;
        h2.first=h2.second.first*h2.second.second;
      }else{
        h1.second.second=abs(v[k].second.second+v[k].second.first-c);
        h1.second.first=v[k].second.first;
        h1.first=h1.second.first*h1.second.second;

        h2.second.second=v[k].second.second-h1.second.second;
        h2.second.first=v[k].second.first;
        h2.first=h2.second.first*h2.second.second;
      }

      if(h1.first>h2.first){v.pb(h2);v.pb(h1);}
      else {v.pb(h1);v.pb(h2);}

      vector<pair<int,pair<int,int> > >::iterator it = v.begin();
      it+=k;
      v.erase(it);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
      cout << v[i].first;
      if(i<v.size()-1)cout << " ";
    }
    cout << endl;
  }

  return 0;
}
