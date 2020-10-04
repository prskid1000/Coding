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

string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
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
   //init();
   cin >> t;

   //common computation
   //common computation

   while( t-- )
    {
      ll n = 0;
      cin >> n;

      bitset<32>bt1(n);
      string s = "2 3 1 ";

      if(bt1.count() == 1 || n == 1)
      {
        s = n == 1 ? "1" : "-1";
        cout << s << "\n";
      }

      else if(n > 3)
      {
        cout << s;
        fr(i, 4, n + 1, 1)
        {
          bitset<32>bt(i);
          if(bt.count() == 1)
          {
            cout << (i + 1) << " " << i << " ";
            i++;
          }
          else
          {
            cout << i << " ";
          }
        }
        cout << "\n";
      }
      else
      {
        cout << s << "\n";
      }
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
