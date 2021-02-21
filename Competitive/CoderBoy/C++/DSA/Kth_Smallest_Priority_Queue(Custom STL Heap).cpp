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


int kthSmallest(vector<vector<int>> mat, int n, int k)
{
  priority_queue<int, vector<node>, comp> mh;
  for(int i = 0 ; i < n; i++)
  {
      node *nd = new node();
      nd->val = mat[0][i];
      nd->i = 0;
      nd->j = i;
      mh.push(*nd);
  }

  node min;

  for(int i = 0; i < k; i++)
  {
      min = mh.top();
      mh.pop();
      if(min.i + 1 < n)
      {
          node *nd = new node();
          nd->i = min.i + 1;
          nd->j = min.j;
          nd->val = mat[i + 1][min.j];
          mh.push(*nd);
      }
  }

  return min.val;
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
      cin >> n >> k;

      vector<vector<int>> mat(n,vector<int>(n, 0));

      for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < n; j++)
        {
          cin >> mat[i][j];
        }
      }

      cout << kthSmallest(mat, n, k) << "\n";
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
