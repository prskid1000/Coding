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

int solve(int n, int k , string s)
{
  stack<int> mag;
  stack<int> iron;
  vector<int> sheet(n + 1, 0);
  int count = 0;

  for(int i = 0; i < n; i++)
  {
    if(s[i] == ':') sheet[i] = sheet[i - 1] + 1;
    else
    {
      if(i != 0) sheet[i] = sheet[i - 1];
    }
  }
  sheet[n] = sheet[n - 1];

  for(int i = 0; i < n; i++)
  {
    if(s[i] == 'X')
    {
      while(!mag.empty()) mag.pop();
      while(!iron.empty()) iron.pop();
    }

    if(s[i] == 'I')
    {
      int power  = 0;
      while(!mag.empty())
      {
        int j = mag.top();
        mag.pop();
        power = k + 1 + abs(i - j) - (sheet[i + 1] - sheet[j]);
        if(power > 0)
        {
          //cout << i << " " << j << "\n";
          count++;
          break;
        }
      }
      if(power <= 0) iron.push(i);
    }

    if(s[i] == 'M')
    {
      int power  = 0;
      while(!iron.empty())
      {
        int j = iron.top();
        iron.pop();
        power = k + 1 + abs(i - j) - (sheet[i + 1] - sheet[j]);
        if(power > 0)
        {
          //cout << i << " " << j << "\n";
          count++;
          break;
        }
      }
      if(power <= 0) mag.push(i);
    }
    cout << i << " " << mag.size() << " " << iron.size() << "\n";
  }

  return count;
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
   cin >> t;

   //common computation
   //common computation

   while( t-- )
    {
      cin >> j >> k;
      string s;
      cin >> s;
      cout << solve(j, k, s) << "\n";
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
