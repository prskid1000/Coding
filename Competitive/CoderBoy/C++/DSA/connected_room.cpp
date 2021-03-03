#include <bits/stdc++.h>
#define ld long double
#define ll long long int
//Constant declarations
#define INF 1000000000000000000LL
//IO modifiers
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define io1 std::ifstream in("in.txt");std::cin.rdbuf(in.rdbuf());
#define io2 std::ofstream out("out.txt");std::cout.rdbuf(out.rdbuf());
//Time Counter
#define time1 auto start = high_resolution_clock::now();
#define time2  auto stop = high_resolution_clock::now(); auto duration = duration_cast<microseconds>(stop - start); cout << "------------------------\n" << "Time taken: " << ceil(duration.count() / 1000000.0) << " seconds" << "\n";
//For outer loop
#define fr(i, start, stop, increment) for(i = start; i < stop; i += increment)
#define dfr(i, start, stop ,decrement) for( i = start; i >= stop; i -= decrement)
//namespace declarations
using namespace std;
using namespace std::chrono; 

void check(vector<vector<bool>> &vis, int i, int j)
{

  if(vis[i][j] == true) return;
  int n = vis.size();
  int m = n != 0? vis[0].size():0;
  vis[i][j] = true;

  if(i + 1 < n)
  {
    check(vis, i + 1, j);
    if(j + 1 < m)
    {
      check(vis, i + 1, j + 1);
      check(vis, i, j + 1);
    }    
  }

  else
  {
    if(j + 1 < m)
    {
      check(vis, i, j + 1);
    }   
  }

}

int main()
{
   #ifndef ONLINE_JUDGE
   time1
   io1 io2
   #endif
   #ifdef ONLINE_JUDGE
   fast
   #endif

   ll t = 1, i = 0, j = 0, k = 0;
   //cin >> t;

   while( t-- )
    {
      ll m = 0, n = 0;
      cin >> n >> m;

      vector<vector<bool>> vis(n, vector<bool>(m, true));
      for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < m; j++)
        {
          char c;
          cin >> c;
          if(c == '.') vis[i][j] = false;
        }
      }

      int count = 0;

      for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < m; j++)
        {
          if(vis[i][j] == false)
          {
            check(vis, i, j);
            count++;
          }
        }
      }

      cout << count << "\n";

    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
