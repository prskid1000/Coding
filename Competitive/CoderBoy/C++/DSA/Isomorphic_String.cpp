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
      string a, b;
      cin >> a >> b;
      int n = a.length(), m = b.length();

      map<char, char>mp;

      map<char, int> ca;
      map<char, int> cb;
      bool flag = true;

      for(int i = 0; i < n; i++)
      {
        if(ca[a[i]] == 0)
        {
          mp[a[i]] = b[i];
          ca[a[i]]++;
          cb[b[i]]++;
        }
        else if(mp[a[i]] == b[i] && ca[a[i]] == cb[b[i]])
        {
          ca[a[i]]++;
          cb[b[i]]++;
        }
        else
        {
          flag = false;
        }
      }

      if(flag == false) cout << "No\n";
      else cout << "Yes\n";
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
