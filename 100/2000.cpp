#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
  int n;
  while(cin >> n,n!=0)
    {
      int x=10,y=10;
      int map[40][40];

      for(int i=0;i<40;i++)
        {
          for(int j=0;j<40;j++)
            {
              map[i][j]=0;
            }
        }

      for(int i=0;i<n;i++)
        {
          int xa,ya;
          cin >> xa >> ya;
          map[xa][ya]=1;
        }

      int k;
      cin >> k;
      int yo=n;

      for(int i=0;i<k;i++)
        {
          string mo;
          int cnt;
          cin >> mo >> cnt;
          for(int j=1;j<=cnt;j++)
            {
              if(mo=="W")
                {
                  if(map[x-1][y]==1)
                    {
                      map[x-1][y]=0;
                      yo--;
                    }
                  x--;
                }
              else if(mo=="E")
                {
                  if(map[x+1][y]==1)
                    {
                      map[x+1][y]=0;
                      yo--;
                    }
                  x++;
                }
              else if(mo=="S")
                {
                  if(map[x][y-1]==1)
                    {
                      map[x][y-1]=0;
                      yo--;
                    }
                  y--;
                }
              else if(mo=="N")
                {
                  if(map[x][y+1]==1)
                    {
                      map[x][y+1]=0;
                      yo--;
                    }
                  y++;
                }
            }
        }

      if(yo>0)
        {
          cout << "No" << endl;
        }
      else if(yo==0)
        {
          cout << "Yes" << endl;
        }
    }

  return 0;
}
