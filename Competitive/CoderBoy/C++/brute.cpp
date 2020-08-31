#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <numeric>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
#include<climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
#define grid vector<vector<ll>>
#define ld long double
#define ll long long int
#define vect vector<ll>
#define dvect vector<vector<ll>>

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
#define fr(start, stop, increment) for(auto iter = start; iter < stop; iter += increment)
#define frn(start, stop) for(auto iter = start; iter != stop; iter++)
#define dfr(start, stop ,increment) for(auto iter = start; iter >= stop; iter -= increment)
#define dfrn(start, stop) for(auto iter = prev(start); iter >= stop; iter--)

//For inner loop
#define fri(start, stop, increment) for(auto iteri = start; iteri < stop; iteri += increment)
#define frni(start, stop) for(auto iteri = start; iteri != stop; iteri++)
#define dfri(start, stop, increment) for(auto iteri = start; iteri >= stop; iteri -= increment)
#define dfrni(start, stop) for(auto iteri = prev(start); iteri >= stop; iteri--)

//namespace declarations
using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

//global variables
long long mx = INT32_MIN, mn = INT32_MAX;

/*struct maths_util
{
    vector<long long> fact;
    vector<bool> is_prime;
    maths_util(int n = 200001, long long q = R)
    {
        fact.resize(n);
        is_prime.assign(n + 1, true);

        fact[0] = 1;
        for(int i = 1; i < n; i++)
            fact[i] = (fact[i-1] * i) % q;

        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i <= n; i++)
            if(is_prime[i])
                for(int j = i + i; j <= n; j += i)
                    is_prime[j] = false;
    }

    long long power_mod_q(long long x, long long n, long long q = R)
    {
        if(n == 0)
            return 1;
        if(n % 2 == 0)
            return power_mod_q((x * x) % q, n / 2, q);
        else
            return (x * power_mod_q((x * x) % q, n / 2, q)) % q;
    }

    long long inverse_mod_q(long long n, long long q = R)
    {
        return power_mod_q(n, q-2, q);
    }

    long long nCr_mod_q(long long n, long long r, long long q = R)
    {
        return (((fact[n] * inverse_mod_q(fact[r], q)) % q) * inverse_mod_q(fact[n-r], q)) % q;
    }

    long long power(long long x, long long n)
    {
        if(n == 0)
            return 1;
        if(n % 2 == 0)
            return power(x * x, n / 2);
        else
            return x * power(x * x, n / 2);
    }

    grid multiply(grid& a, grid& b)
    {
        int p = a.size(), q = b.size(), r = b[0].size();
        grid c(p, vector<long long>(r, 0));
        for(int i = 0; i < p; i++)
            for(int j = 0; j < r; j++)
                for(int k = 0; k < q; k++)
                    c[i][j] += (a[i][k] * b[k][j]) % R;
        return c;
    }

    grid add(grid& a, grid& b)
    {
        int p = a.size(), q = a[0].size();
        grid c(p, vector<long long>(q));
        for(int i = 0; i < p; i++)
            for(int j = 0; j < q; j++)
                c[i][j] = a[i][j] + b[i][j];
        return c;
    }

    grid power(grid& a, long long n)
    {
        grid c(a.size(), vector<long long>(a.size(), 0));
        if(n == 0)
        {
            for(int i = 0; i < (int)a.size(); i++)
                c[i][i] = 1;
            return c;
        }
        if(n % 2 == 0)
            return power(c = multiply(a, a), n / 2);
        else
            return multiply(a, c = power(c = multiply(a, a), n / 2));

    }

    ll fibn(ll n)
    {
       grid fib(2, vector<long long>(2,1));
       fib[1][1] = 0;
       if(n == 0) return 0;
       grid ans(power(fib, n - 1));
       return ans[0][0];
    }

};*/

/*struct dsu
{
    vector<int> rank, parent, num;
    dsu(int n)
    {
        rank.assign(n, 0);
        parent.resize(n);
        num.assign(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find_set(int i)
    {
        if(i == parent[i])
            return i;
        return parent[i] = find_set(parent[i]);
    }
    bool is_same_set(int i, int j)
    {
        if(find_set(i) == find_set(j))
            return true;
        return false;
    }
    void union_set(int i, int j)
    {
        if(!is_same_set(i, j))
        {
            int u = find_set(i), v = find_set(j);
            if(rank[u] == rank[v])
            {
                parent[v] = u;
                rank[u] += 1;
                num[u] += num[v];
            }
            else if(rank[u] > rank[v])
                parent[v] = u, num[u] += num[v];
            else
                parent[u] = v, num[v] += num[u];
        }
    }

};*/

/*struct segment_tree
{
    struct node
    {
        long long sum;
    };

    node merge(node a, node b)
    {
        return {a.sum + b.sum};
    }

    vector<long long> a;
    vector<node> tree;
    int n;

    segment_tree(vector<long long> a, int buffer = 0)
    {
        n = a.size();
        while((n & (n-1)) != 0)
        {
            a.push_back(buffer);
            n = a.size();
        }
        this -> a = a;
        tree.resize(2 * n - 1);
        build(0, 0,  n - 1);
    }

    void build(int i, int l, int r)
    {
        if(l == r)
        {
            tree[i].sum = a[l];
        }
        else
        {
            int mid = (l + r) / 2;
            build(2 * i + 1, l, mid);
            build(2 * i + 2, mid + 1, r);
            tree[i] = merge(tree[2*i + 1], tree[2 * i + 2]);
        }
    }

    node query(int i, int s, int e, int l, int r)
    {
        if(l == s && r == e)
            return tree[i];

        int mid = (l + r) /2 ;
        if(e <= mid)
            return query(2 * i + 1, s, e, l, mid);
        else if(s > mid)
            return query(2 * i + 2, s, e, mid + 1, r);
        return merge(query(2 * i + 1, s, mid, l, mid), query(2 * i + 2, mid + 1, e, mid + 1, r));
    }

    void update(int i, int idx, int val, int l, int r)
    {
        if(l == r)
        {
            a[idx] = val;
            tree[i].sum = val;
        }
        else
        {
            int mid = (l + r) / 2;
            if(idx <= mid)
                update(2 * i + 1, idx, val, l, mid);
            else
                update(2 * i + 2, idx, val, mid + 1, r);

            tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }


};*/

/*struct graph
{
    int v, time, count;
    vector<pair<int, int>>* adj;
    grid matrix;
    vector<bool> visited, in_stack, ap, in_MST;
    stack<int> s;
    vector<int> color, cc, f, d, finish_time, l, indegree, sccs, topo, outdegree, pred, child, euler;
    vector<long long> dist;
    graph(int n)
    {
        v = n;
        adj = new vector<pair<int, int>>[n];
        // matrix.resize(n);
        // for(int i = 0; i < n; i++)
        //     matrix[i].assign(n, 0);
    }

    void add_edge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
        // matrix[u][v] = w;
        // matrix[v][u] = w;
    }

    void dfs()
    {
        color.assign(v, 0);
        cc.assign(v, -1);
        d.assign(v, -1);
        f.assign(v, -1);
        time = count = 0;
        finish_time.assign(2 * v, -1);
        visited.assign(v, false);
        pred.assign(v, -1);
        for(int i = 0; i < v; i++)
        {
            if(color[i] == 0)
            {
                dfs(i);
                count++;
            }
        }
        for(int i = 0; i < v; i++)
            finish_time[f[i]] = i;
    }

    void dfs(int i)
    {
        color[i] = 1;
        euler.push_back(i);
        cc[i] = count;
        d[i] = time;
        time++;
        for(auto x : adj[i])
        {
            if(!color[x.first])
            {
                pred[x.first] = i;
                dfs(x.first);
            }
        }
        color[i] = 2;
        f[i] = time;
        time++;
    }

    void bfs(int u)
    {
        color.assign(v, 0);
        pred.assign(v, -1);
        d.assign(v, 0);
        queue<int> q;
        color[u] = 1;
        q.push(u);
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            for(auto x : adj[i])
            {
                if(!color[x.first])
                {
                    pred[x.first] = i;
                    color[x.first] = 1;
                    d[x.first] = d[i] + 1;
                    q.push(x.first);
                }
            }
            color[i] = 2;
        }
    }

    void scc()
    {
        graph g_t(v);
        for(int i = 0; i < v; i++)
            for(auto x : adj[i])
                g_t.add_edge(x.first, i, x.second);
        dfs();
        g_t.color.assign(v, 0);
        g_t.cc.assign(v, -1);
        g_t.d.assign(v, -1);
        g_t.f.assign(v, -1);
        g_t.time = g_t.count = 0;
        g_t.finish_time.assign(2 * v, -1);
        g_t.visited.assign(v, false);
        g_t.pred.assign(v, -1);
        for(int i = 2 * v - 1; i >= 0; i--)
        {
            if(finish_time[i] != -1 && g_t.color[finish_time[i]] == 0)
            {
                g_t.dfs(finish_time[i]);
                g_t.count++;
            }
        }
        sccs = g_t.cc;
        count = g_t.count;
    }

    void topological_sort()
    {
        indegree.assign(v, 0);
        outdegree.assign(v, 0);
        for(int i = 0; i < v; i++)
            if(adj[i].size())
                outdegree[i] = adj[i].size();
        for(int i = 0; i < v; i++)
            for(auto x : adj[i])
                indegree[x.first]++;
        vector<int> zero;
        for(int i = 0; i < v; i++)
            if(!indegree[i])
                zero.push_back(i);

        while(!zero.empty())
        {
            int v = zero.back();
            topo.push_back(v);
            zero.pop_back();
            for(auto x : adj[v])
            {
                indegree[x.first]--;
                if(!indegree[x.first])
                    zero.push_back(x.first);
            }
        }
    }

    void tarjan()
    {
        for(int i = 0; i < v; i++)
            if(!color[i])
                tarjan(i);
    }

    void tarjan(int i)
    {
        color[i] = 1;
        d[i] = time;
        time++;
        l[i] = d[i];
        s.push(i);
        in_stack[i] = true;
        for(auto x : adj[i])
        {
            if(!color[x.first])
            {
                tarjan(x.first);
                l[i] = min(l[i], l[x.first]);
            }
            else if(in_stack[x.first])
            {
                l[i] = min(l[i], d[x.first]);
            }
        }

        color[i] = 2;
        f[i] = time;
        time++;
        if(d[i] == l[i])
        {
            while(s.top() != i)
                cout << s.top() << ' ', in_stack[s.top()] = false, s.pop();
            cout << s.top() << '\n', in_stack[s.top()] = false, s.pop();
        }
    }

    graph kruskal()
    {
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < v; i++)
            for(auto x : adj[i])
                edges.push_back(make_pair(x.second, make_pair(i, x.first)));
        sort(edges.begin(), edges.end());
        dsu d(v);
        graph mst(v);
        for(auto x : edges)
        {
            if(!d.is_same_set(x.second.first, x.second.second))
            {
                mst.add_edge(x.second.first, x.second.second, x.first);
                d.union_set(x.second.first, x.second.second);
            }

        }
        return mst;
    }

    graph prims(int s)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        d.assign(v, INT32_MAX);
        pred.assign(v, -1);
        in_MST.assign(v, false);
        count = 0;
        d[s] = 0;
        pq.push({0, s});
        while(count < v)
        {
            int u = pq.top().second;
            if(!in_MST[u])
                in_MST[u] = true, count++;
            pq.pop();
            for(auto x : adj[u])
            {
                if(!in_MST[x.first] && d[x.first] > x.second)
                {
                    pq.push({x.second, x.first});
                    pred[x.first] = u;
                    d[x.first] = x.second;
                }
            }
        }
        graph mst(v);
        for(int i = 0; i < v; i++)
        {
            if(pred[i] != -1)
                mst.add_edge(i, pred[i], d[i]);
        }
        return mst;
    }

    void dijkstra(int s)
    {
        d.assign(v, INT32_MAX);
        visited.assign(v, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({d[s] = 0, s});
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if(!visited[u])
            {
                visited[u] = true;
                for(auto x : adj[u])
                {
                    if(d[x.first] > d[u] + x.second)
                    {
                        d[x.first] = d[u] + x.second;
                        pq.push({d[x.first], x.first});
                    }
                }
            }
        }
    }
};*/

/*struct kmp
{
    vector<int> lps;
    string p, t;
    kmp(string& p, string& t)
    {
        this -> p = p;
        this -> t = t;
        //PREPROCESSING
        lps.assign(p.size(), 0);
        lps[0] = 0;
        int len = 0, i = 1, j;
        while(i < (int)p.size())
        {
            if(p[i] == p[len])
                lps[i++] = ++len;
            else if(len)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
        //STRING MATCHING
        i = j = 0;
        while(i < (int)t.size())
        {
            if(p[j] == t[i])
                j++, i++;

            if(j == (int)p.size())
            {
                //It's a match at index i - 1
                j = lps[j-1];
            }
            else if(i < (int)t.size() && p[j] != t[i])
            {
                if(j)
                    j = lps[j-1];
                else
                    i++;
            }
        }


    }
};*/

/*struct Trie
{
    struct node
    {
        char c;
        bool is_leaf;
        vector<node *> child;
        node(char ch)
        {
            c = ch;
            is_leaf = false;
            child.assign(L, nullptr);
        }
    };
    node * root;
    Trie()
    {
        root = new node('#');
    }

    void insert(string& s)
    {
        node * temp = root;
        for(auto x : s)
        {
            if(!(temp -> child)[x])
                (temp -> child)[x] = new node(x);
            temp = (temp -> child)[x];
        }
        temp -> is_leaf = true;
    }

    bool has_child(node * temp)
    {
        for(auto x : temp -> child)
            if(x)
                return true;
        return false;
    }

    bool search(string& s)
    {
        node * temp = root;
        bool flag = true;
        for(auto x : s)
        {
            if(!(temp -> child)[x])
            {
                flag = false;
                break;
            }
            temp = (temp -> child)[x];
        }
        if(flag && temp -> is_leaf)
            return true;
        else
            return false;
    }

    void remove(string& s)
    {
        if(search(s))
            root = remove(root, 0, s);
    }
    node * remove(node * root, int pos, string& s)
    {
        if(pos <= (int)s.length() - 1)
        {
            (root -> child)[s[pos]] = remove((root -> child)[s[pos]], pos + 1, s);
            bool flag = true;
            for(int i = 0; i < L; i++)
                if((root -> child)[i])
                    flag = false;
            if(root -> c != '#' && root -> is_leaf == false && flag)
            {
                delete(root);
                root = nullptr;
            }
        }
        else
        {
            root -> is_leaf = false;

            bool flag = true;
            for(int i = 0; i < L; i++)
                if((root -> child)[i])
                    flag = false;
            if(flag)
            {
                delete(root);
                root = nullptr;
            }
        }
        return root;
    }
};*/

/*struct lazy_seg
{
    struct node
    {
        long long sum;
    };
    vector<long long> a, pending;
    int n;
    vector<node> tree;
    node merge(node a, node b)
    {
        return {a.sum + b.sum};
    }

    lazy_seg(vector<long long> a, int buffer)
    {
        n = a.size();
        while(n & (n - 1))
        {
            a.push_back(buffer);
            n = a.size();
        }
        this -> a = a;
        tree.resize(2 * n - 1);
        pending.assign(2 * n - 1, 0);
        build(0, 0, n - 1);
    }

    void build(int i, int l, int r)
    {
        if(l == r)
        {
            tree[i] = {a[l]};
        }
        else
        {
            int mid = (l + r) / 2;
            build(2 * i + 1, l, mid);
            build(2 * i + 2, mid + 1, r);
            tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    node query(int i, int s, int e, int l, int r)
    {
        apply_pending(i, l, r);
        if(s == l && e == r)
            return tree[i];
        else
        {
            int mid = (l + r) / 2;
            if(e <= mid)
                return query(2 * i + 1, s, e, l, mid);
            else if(s > mid)
                return query(2 * i + 2, s, e, mid + 1, r);
            else
                return merge(query(2 * i + 1, s, mid, l, mid), query(2 * i + 2, mid + 1, e, mid + 1, r));
        }

    }

    void update(int i, int idx, long long val, int l, int r)
    {
        if(l == r)
        {
            a[idx] = val;
            tree[i] = {val};
        }
        else
        {
            int mid = (l + r) / 2;
            if(idx <= mid)
                update(2 * i + 1, idx, val, l, mid);
            else
                update(2 * i + 2, idx, val, mid + 1, r);
            tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    void apply_pending(int i, int s, int e)
    {
        if(pending[i])
        {
            tree[i].sum = tree[i].sum + (e - s + 1) * pending[i];
            if(s != e)
            {
                pending[2 * i + 1] += pending[i];
                pending[2 * i + 2] += pending[i];
            }
            pending[i] = false;
        }
    }

    void update_range(int i, int s, int e, long long val, int l, int r)
    {
        apply_pending(i, l, r);
        if(s == l && r == e)
        {
            tree[i].sum = tree[i].sum + (e - s + 1) * val;
            if(s != e)
            {
                pending[2 * i + 1] += val;
                pending[2 * i + 2] += val;
            }
        }
        else
        {
            int mid = (l + r) / 2;
            if(e <= mid)
                update_range(2 * i + 1, s, e, val, l, mid);
            else if(s > mid)
                update_range(2 * i + 2, s, e, val, mid + 1, r);
            else
            {
                update_range(2 * i + 1, s, mid, val, l, mid);
                update_range(2 * i + 2, mid + 1, e, val, mid + 1, r);
            }
            tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
        }


    }

};*/

/*void init()
{

}*/

/*string query_sim(ll x ,ll y)
{
  string ans = "NO";
  //cout << x << " " << y <<"\n";
  if(x == 0 && y >= 0 && y <= 16) ans = "YES";
  if(x == 4 && y >= 0 && y <= 8) ans = "YES";
  if(y == 0 && x >= 0 && x <= 4) ans = "YES";
  if(y == 8 && x >= 0 && x <= 10) ans = "YES";

  cout << x << " " << y << " -------> " << ans << "\n";
  return ans;
}*/

/*string query(ll x)
{
  string q = to_string(x) + "\n";
  string res;

  cout << q;
  fflush(stdout);

  cin >> res;
  //res = query_sim(x ,y);

  return res;
}*/

/*void rangeTS(ll l, ll u, ll &ans , ll k = -1)
{
  if (u < l) return;

  ll mids = l + (u - l) / 3;
  ll midu = u - (u - l) / 3;
  //cout << mid << "\n";
  if(mids == k)
  {
    ans = mids;
    return;
  }
  if(midu == k)
  {
    ans = midu;
    return;
  }

  if(mids > k)rangeTS(l, mids - 1, ans, k);
  if(midu < k)rangeTS(midu + 1, l, ans, k);
  rangeTS(mids + 1, midu - 1, ans, k);

}*/

/*void rangeBS(ll p, ll k, ll l, ll u, ll &ans)
{
  if (u < l) return;

  ll mid = (l + u) / 2;
  //cout << mid << "\n";
  if(mid == k)
  {
    ans = mid;
    return;
  }
  else
  {
    if(mid > k)rangeBS(p, k, l ,mid - 1 ,ans);
    else rangeBS(p ,k ,mid + 1 ,u ,ans);
  }
}*/

/*bool comp(pair<ld,ld>a,pair<ld,ld>b)
{
  return a.second < b.second;
}*/

ll join(vector<ll> &a, vector<ll> &b)
{
  ll count = 0;
  fr(1, 101, 1)
  {
    if(a[iter] == -1)continue;
    if(b[iter] == -1)
    {
      if(a[iter] != 1)count += a[iter];
      b[iter] = a[iter];
    }
    else
    {
      count += a[iter] + b[iter];
      b[iter] = a[iter] + b[iter];
    }
    a[iter] = 0;
  }

  return count;
}



int main()
{
   #ifndef ONLINE_JUDGE
   time1
   io1 io2
   #endif
	 //fast
   ll t = 1;
   //init();
   cin >> t;

   //common computation
   //maths_util *mt = new maths_util();
   //common computation

   while( t-- )
    {
      ll n = 0, k = 0, sum = 0, count = 0, j = 0, cl = 0, ci = 0, cr = 0, s = 0, f = 0;
      cin >> n >> k;

      vector<ll> v(n);
      vector<vector<ll>> vf;
      vector<ll> ans;
      fr(0, n, 1) cin >> v[iter];

      fr(0, n ,1)
      {
        j = iter + 1;
        set<ll> st;
        vector<ll> tf(101,-1);
        tf[v[iter]] = tf[v[iter]] == -1 ? 1 : tf[v[iter]]++;
        st.insert(v[iter]);
        while(j < n && st.find(v[j]) == st.end())
        {
          tf[v[j]] = tf[v[j]] == -1 ? 1 : tf[v[j]]++;
          st.insert(v[j]);
          j++;
        }
        vf.push_back(tf);
        //cout << v[iter] << " " << j - 1 << "\n";
        iter = j - 1;
      }

      vector<vector<vector<ll>>> vv(vf.size() - 1,vf);
      ans.push_back(vf.size() * k);
      fr(1, vf.size(), 1)
      {
        fri(0, vv.size(), 1)
        {
          ll x = join(vv[iteri][iter + iteri - 1], vv[iteri][iter + iteri]);
          //cout << x << "\n";
          ans.push_back(x + vv.size() * k);
          /*for(ll p = 0; p <vv[iteri].size();p++)
           {
            for(ll q = 1; q < 5; q++)cout << q << " " << vv[iteri][p][q] << "\n";
            cout << "----------------" << "\n";
          }*/
          //cout << ans[ans.size() - 1] << " ";
          //cout << "\n#########################\n";
        }
        //cout << "\n_______________________________\n";
        vv.erase(vv.end());
      }
      cout << *min_element(ans.begin(), ans.end()) << "\n";
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
