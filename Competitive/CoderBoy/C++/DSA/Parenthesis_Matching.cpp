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
      string s = "";
      cin >> s;
      stack<int> stk;

      bool flag = true;

      for(int i = 0; i < s.length(); i++)
      {
        cout << i << "\n";
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
        stk.push(s[i]);

        else
        {
          if(stk.empty() == true)
          {
            flag = false;
            break;
          }
          switch (s[i])
           {
            case ')':
            while(stk.empty() == false && stk.top() != '(')
            stk.pop();
            if(stk.empty() != true) stk.pop();
            else
            {
              flag = false;
            }
            break;
            case ']':
            while(stk.empty() == false && stk.top() != '[')
            stk.pop();
            if(stk.empty() != true) stk.pop();
            else
            {
              flag = false;
            }
            break;
            case '}':
            while(stk.empty() == false && stk.top() != '{')
            stk.pop();
            if(stk.empty() != true) stk.pop();
            else
            {
              flag = false;
            }
          }

          if(flag == false)break;
        }
      }

      if(flag == true && stk.empty() == true) cout << "balanced" << "\n";
      else cout << "not balanced" << "\n";
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
