#include <bits/stdc++.h>
#define ld long double
#define ll long long int
//Constant declarations
#define INF 2147483647
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

void recur_solve(vector<int> v, int i, int j, int si, int sj ,int s, int &c, vector<vector<int>> &mp)
{
  if(si == (s - si - sj) && sj == (s - si - sj))
  {
    if(mp[i][j] == 0)
    {
      mp[i][j] = 1;
      c++;
    }
  }
  
  if(j <= i)return;
  recur_solve(v, i + 1, j - 1, si + v[i], sj + v[j] , s, c, mp);
  recur_solve(v, i, j - 1, si, sj + v[j] , s, c, mp);
  recur_solve(v, i + 1, j, si + v[i], sj, s, c, mp);
}

int solve(vector<int> v)
{
  int n = v.size();
  vector<vector<int>> mp(n, vector<int>(n, 0));
  int c = 0, s = 0;
  for(int i = 0; i < n; i++) s += v[i];
  recur_solve(v, 1, n - 2, v[0], v[n - 1], s, c, mp);
  return c;
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

   //common computation
   //common computation

   while( t-- )
    {
      int n = 0;
      cin >> n;

      vector<int> v(n, 0);
      for(int i = 0; i < n; i++) cin >> v[i];
      cout << solve(v) << "\n";

    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
