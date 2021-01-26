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

void dfs(vector<vector<char>>& grid,vector<vector<bool>>& v,int i,int j,int n,int m)
{
    if( v[i][j]==false)
    v[i][j]=true;

    if(i+1<n && grid[i+1][j]=='1')
    dfs(grid,v,i+1,j,n, m);

    if(j+1<m && grid[i][j+1]=='1')
    dfs(grid,v,i,j+1,n, m);

    if(i-1>=0 && grid[i-1][j]=='1')
    dfs(grid,v,i-1,j,n, m);

    if(j-1>=0 && grid[i][j-1]=='1')
    dfs(grid,v,i,j-1,n, m);

    if(i+1<n && j+1<m && grid[i+1][j+1]=='1')
    dfs(grid,v,i+1,j+1,n, m);

    if(i+1<n &&j-1>=0 && grid[i+1][j-1]=='1')
    dfs(grid,v,i+1,j-1,n, m);

    if(i-1>=0 && j+1<m && grid[i-1][j+1]=='1')
    dfs(grid,v,i-1,j+1,n, m);

    if(i-1>=0 && j-1>=0 && grid[i-1][j-1]=='1')
    dfs(grid,v,i-1,j-1,n, m);

}
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        //cout<<n<<" "<<m<<endl;
        vector<vector<bool>>v(n,vector<bool>(m,false));
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( grid[i][j]=='1' && v[i][j]==false )
                {
                    c++;
                    dfs(grid,v,i,j,n,m);
                }
            }
        }
        
        return c;
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
       int n = 0, m = 0;
       cin >> n >> m;
       vector<vector<char>> v(n, vector<char>(m, '.'));
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < m; j++)
           {
               cin >> v[i][j];
           }
       }

    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
