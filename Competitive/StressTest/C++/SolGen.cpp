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
#define io2 std::ofstream out("input.txt");std::cout.rdbuf(out.rdbuf());

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

int main()
{
  io2;
  cout << "3125" << "\n";
  ll i,j,k,p, q;
  fr(p, 0, 6, 1)
  {
    fr(q, 0, 6, 1)
    {
      fr(i, 0, 6, 1)
      {
        fr(j, 0, 6, 1)
        {
          fr(k, 0, 6, 1)
          {
            cout << "5\n";
            cout << p << " " << q << " " << i << " " << j << " " << k << "\n";
          }
        }
      }
    }
  }

  return 0;
}
