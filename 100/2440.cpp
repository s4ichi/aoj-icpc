#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
  int n;
  map<string, int> hs;

  cin >> n;
  for(int i=0;i<n;i++){
    string s; cin >> s;
    hs[s] = 1;
  }

  cin >> n;
  for(int i=0,j=0;i<n;i++){
    string in; cin >> in;
    if(hs[in] < 1){
      cout << "Unknown " << in << endl;
    }else{
      cout << ((++j)%2?"Opened by ":"Closed by ") << in << endl;
    }
  }
  
  return 0;
}
