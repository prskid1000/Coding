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

bool back(vector<vector<int>> v, vector<vector<int>> &res, vector<pair<int,int>> ans, int i, int j)
{
  //cout << i << " " << j << "\n";
  if(i == v.size() - 1 && j == v.size() - 1)
  {
    ans.push_back({i, j});
    for(int k = 0; k < ans.size(); k++)
    {
      cout << ans[k].first << " " << ans[k].second << "\n";
    }
    cout << "----------------\n";
    return true;
  }

  else if(i < v.size() && j < v.size() && i >= 0 && j >= 0)
  {
    if(res[i][j] == 1 || v[i][j] == 0) return false;

    res[i][j] = 1;
    ans.push_back({i, j});

    if(back(v, res, ans, i, j - 1 )) return true;
    if(back(v, res, ans, i , j + 1 )) return true;
    if(back(v, res, ans, i + 1, j )) return true;
    if(back(v, res, ans, i - 1, j)) return true;

    res[i][j] = 0;
    ans.pop_back();
  }

  return false;
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
      int n = 0;
      cin >> n;

      vector<vector<int>> v(n, vector<int>(n, 0));
      vector<vector<int>> res(n, vector<int>(n, 0));
      vector<pair<int, int>> ans;

      for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < n; j++)
        {
          cin >> k;
          v[i][j] = k;
        }
      }

      /*for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < n; j++)
        {
          cout << v[i][j] << " ";
        }
        cout << "\n";
      }*/

      cout << back(v, res, ans, 0, 0) << "\n";
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
