#include<bits/stdc++.h>
#define ld long double
#define ll long long int
#define dvect vector<vector<int>>
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define io1 std::ifstream in("GenData.txt");std::cin.rdbuf(in.rdbuf());
#define io2 std::ofstream out("input.txt");std::cout.rdbuf(out.rdbuf());
#define time1 auto start = high_resolution_clock::now();
#define time2  auto stop = high_resolution_clock::now(); auto duration = duration_cast<microseconds>(stop - start); cout << "Time taken: "<< duration.count() << " microseconds" <<"\n";
#define FOR(start,stop,increment) for(auto iter=start;iter<stop;iter+=increment)
#define FORN(start,stop,increment) for(auto iter=start;iter!=stop;iter+=increment)
#define DFOR(start,stop,increment) for(auto iter=start;iter>=stop;iter-=increment)
#define DFORN(start,stop,increment) for(auto iter=start;iter>=stop;iter-=increment)
using namespace std;
using namespace chrono;


int main()
{
  io2
  cout<<65536<<"\n";
  ll x=4,y=4,z=4,a=4,b=4,c=4,d=4,e=4;
  for(ll i=0;i<x;i++)
  {
    for(ll j=0;j<y;j++)
    {
      for(ll k=0;k<z;k++)
      {
        for(ll p=0;p<a;p++)
        {
          for(ll q=0;q<b;q++)
          {
            for(ll r=0;r<c;r++)
            {
              for(ll s=0;s<d;s++)
              {
                for(ll t=0;t<e;t++)
                {
                  cout<<4<<"\n";
                  cout<<i<<" "<<j<<" "<<k<<" "<<p<<"\n";
                  cout<<q<<" "<<r<<" "<<s<<" "<<t<<"\n";
                }
              }
            }
          }
        }
      }
    }
  }
    return 0;
}
