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
      int n = 0, m = 0;
      cin >> n >> m;
      vector<int> a(n);
      vector<int> b(m);
      for(int i = 0; i < n; i++) cin >> a[i];
      for(int i = 0; i < m; i++) cin >> b[i];

      int gap = (n + m) / 2;

      for(int i = 0,j = 0; gap >= 1; gap /= 2)
      {

        for(i = 0; i + gap < n; i++)
        {
          if(a[i] > a[i + gap])
          {
            int t = a[i];
            a[i] = a[i + gap];
            a[i + gap] = t;
          }
        }

        for(j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
        {
          //cout << b[j] << "\n";
          if(a[i] > b[j])
          {
            int t = a[i];
            a[i] = b[j];
            b[j] = t;
          }
        }

        if(j < m)
        {
          for(j = 0; j + gap < m; j++)
          {
            if(b[j] > b[j + gap])
            {
              if(b[i] > b[j])
              {
                int t = b[i];
                b[i] = b[j];
                b[j] = t;
              }
            }
          }
        }
      }

      for(int i = 0; i < n; i++) cout << a[i] << " ";
      cout << "\n";
      for(int i = 0; i < m; i++) cout << b[i] << " ";
      cout << "\n";
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
