#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
  vector<string> button(10);
  button[1] = ".,!? ";
  button[2] = "abc";
  button[3] = "def";
  button[4] = "ghi";
  button[5] = "jkl";
  button[6] = "mno";
  button[7] = "pqrs";
  button[8] = "tuv";
  button[9] = "wxyz";
  button[0] = "OK";

  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    string in;
    cin >> in;
    int target = -1, push = -1;
    for(int j=0;j<in.size();j++){
      if(in[j] == '0'){
        if(target >= 0)cout << button[target][push];
        push = -1;
        target = -1;
      }else{
        target = in[j] - '0';
        if(push == button[target].size() - 1)push = 0;
        else push++;
      }
    }
    cout << endl;
  }
  return 0;
}
