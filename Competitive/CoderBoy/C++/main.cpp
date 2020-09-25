#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

#define ld long double
#define ll long long int

//Constant declarations
#define R 1000000007
#define M 998244353
#define L 256
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
using namespace __gnu_pbds;


struct PTF
{
  struct DJK
  {
    vector<vector<pair<ll, ll>>> adj;
    void dijkstra(ll s, vector<ll>& d, vector<ll>& p)
    {
      ll n = adj.size();
      d.assign(n, INF);
      p.assign(n, -1);
      vector<bool> u(n, false);
      d[s] = 0;
      for (ll i = 0; i < n; i++)
      {
        ll v = -1;
        for (ll j = 0; j < n; j++)
        {
          if (!u[j] && (v == -1 || d[j] < d[v]))
          {
            v = j;
          }
        }
        if (d[v] == INF)
        {
          break;
        }
        u[v] = true;
        for (auto edge : adj[v])
        {
          ll to = edge.first;
          ll len = edge.second;
          if (d[v] + len < d[to])
          {
            d[to] = d[v] + len;
            p[to] = v;
          }
        }
      }
    }
    vector<ll> restore_path(ll s, ll t, vector<ll> const& p)
    {
      vector<ll> path;
      for (ll v = t; v != s; v = p[v])
      {
          path.push_back(v);
      }
      path.push_back(s);
      reverse(path.begin(), path.end());
      return path;
    }
  };

  struct BMF
  {
    vector<ll> bellmanFord(vector<vector<ll>>edge, ll v, ll e, ll s)
    {
      vector<ll>dis(v, INF);
      dis[s] = 0;
      for(ll i = 0; i < v - 1; i++)
      {
        for(ll j = 0; j < e; j++)
        {
          if(dis[edge[j][0]] + edge[j][2] < dis[edge[j][1]])
          {
            dis[edge[j][1]] = dis[edge[j][0]] + edge[j][2];
          }
        }
      }
      for(ll i = 0; i < e; i++)
      {
        ll x = edge[i][0];
        ll y = edge[i][1];
        ll weight = edge[i][2];
        if (dis[x] != INF && dis[x] + weight < dis[y])
        {
          //cout << "Graph contains negative weight cycle\n";
        }
      }
      return dis;
    }
  };
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
   //init();
   cin >> t;

   //common computation
   //common computation

   while( t-- )
    {

    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
