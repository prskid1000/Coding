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

struct node
{
    int val;
    int i;
    int j;
};

struct comp {
    bool operator()(node const& a, node const& b)
    {

        return a.val > b.val;
    }
};

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

      vector<vector<int>> v;

      for(int i = 0; i < n; i++)
      {
        cin >> j;
        vector<int> tmp(j);
        for(k = 0; k < j; k++) cin >> tmp[k];
        v.push_back(tmp);
      }

      priority_queue<int, vector<node>, comp> heap;
      int mx = INT_MIN, mn = INT_MAX;
      for(int i = 0; i < n; i++)
      {
        node *m = new node();
        m->val = v[i][0];
        m->i = i;
        m->j = 0;
        heap.push(*m);
        mx = max(mx, v[i][0]);
      }

      vector<int>res;

      int p = 0, q = 0;

      while(heap.size() != 0)
      {
        node m = heap.top();
        heap.pop();
        cout << m.val << "\n";
        if(mn > mx - m.val + 1)
        {
          p = mx;
          q = m.val;
          mn = mx - m.val + 1;
        }

        if(m.j + 1 < v[m.i].size())
        {
          m.val = v[m.i][m.j + 1];
          m.j++;
          heap.push(m);
          mx = max(mx, m.val);
        }
        else break;
      }
        cout << q << " " << p << "\n";
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
