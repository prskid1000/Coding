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

struct MT
{
  vector<ll> fact;
  vector<bool> is_prime;
  MT(ll n = 200001, ll q = R)
  {
    fact.resize(n);
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    fact[0] = 1;
    for(ll i = 1; i < n; i++)
    {
      fact[i] = (fact[i-1] * i) % q;
    }
    for(ll i = 2; i <= n; i++)
    {
      if(is_prime[i])
      {
        for(ll j = i + i; j <= n; j += i)
        {
          is_prime[j] = false;
        }
      }
    }
  }
  ll power_mod_q(ll x, ll n, ll q = R)
  {
    if(n == 0)
    {
      return 1;
    }
    if(n % 2 == 0)
    {
      return power_mod_q((x * x) % q, n / 2, q);
    }
    else
    {
      return (x * power_mod_q((x * x) % q, n / 2, q)) % q;
    }
  }
  ll inverse_mod_q(ll n, ll q = R)
  {
    return power_mod_q(n, q - 2, q);
  }
  ll nCr_mod_q(ll n, ll r, ll q = R)
  {
    return (((fact[n] * inverse_mod_q(fact[r], q)) % q) * inverse_mod_q(fact[n - r], q)) % q;
  }
  ll power(ll x, ll n)
  {
    if(n == 0)
    {
      return 1;
    }
    if(n % 2 == 0)
    {
      return power(x * x, n / 2);
    }
    else
    {
      return x * power(x * x, n / 2);
    }
  }
  vector<vector<ll>> multiply(vector<vector<ll>>& a, vector<vector<ll>>& b)
  {
    ll p = a.size(), q = b.size(), r = b[0].size();
    vector<vector<ll>> c(p, vector<ll>(r, 0));
    for(ll i = 0; i < p; i++)
    {
      for(ll j = 0; j < r; j++)
      {
        for(ll k = 0; k < q; k++)
        {
          c[i][j] += (a[i][k] * b[k][j]) % R;
        }
      }
    }
    return c;
  }
  vector<vector<ll>> add(vector<vector<ll>>& a, vector<vector<ll>>& b)
  {
    ll p = a.size(), q = a[0].size();
    vector<vector<ll>> c(p, vector<ll>(q));

    for(ll i = 0; i < p; i++)
    {
      for(ll j = 0; j < q; j++)
      {
        c[i][j] = a[i][j] + b[i][j];
      }
    }
    return c;
  }
  vector<vector<ll>> power(vector<vector<ll>>& a, ll n)
  {
    vector<vector<ll>> c(a.size(), vector<ll>(a.size(), 0));

    if(n == 0)
    {
      for(ll i = 0; i < (ll)a.size(); i++)
      {
        c[i][i] = 1;
      }
      return c;
    }
    if(n % 2 == 0)
    {
      return power(c = multiply(a, a), n / 2);
    }
    else
    {
      return multiply(a, c = power(c = multiply(a, a), n / 2));
    }
  }
  ll fibn(ll n)
  {
    vector<vector<ll>> fib(2, vector<ll>(2,1));
    fib[1][1] = 0;
    if(n == 0)
    {
      return 0;
    }
    else
    {
      vector<vector<ll>> ans(power(fib, n - 1));
      return ans[0][0];
    }
  }
};

struct DSU
{
  //Disjoint-Set-Union
  vector<ll> rank, parent, num;
  DSU(ll n)
  {
    rank.assign(n, 0);
    parent.resize(n);
    num.assign(n, 1);
    for(ll i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }
  ll find_set(ll i)
  {
    if(i == parent[i])
    {
      return i;
    }
    else
    {
      return parent[i] = find_set(parent[i]);
    }
  }
  bool is_same_set(ll i, ll j)
  {
    if(find_set(i) == find_set(j))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  void union_set(ll i, ll j)
  {
    if(!is_same_set(i, j))
    {
      ll u = find_set(i), v = find_set(j);
      if(rank[u] == rank[v])
      {
        parent[v] = u;
        rank[u] += 1;
        num[u] += num[v];
      }
      else if(rank[u] > rank[v])
      {
        parent[v] = u, num[u] += num[v];
      }
      else
      {
        parent[u] = v, num[v] += num[u];
      }
    }
  }
};

struct KMP
{
  //Knuth–Morris–Pratt
  vector<ll> lps;
  KMP(vector<char>& p, vector<char>& t)
  {
    lps.assign(p.size(), 0);
    lps[0] = 0;
    ll len = 0, i = 1, j;
    while(i < (ll)p.size())
    {
      if(p[i] == p[len])
      {
        lps[i++] = ++len;
      }
      else if(len)
      {
        len = lps[len - 1];
      }
      else
      {
        lps[i++] = 0;
      }
    }
    i = j = 0;
    while(i < (ll)t.size())
    {
      if(p[j] == t[i])
      {
        j++;
        i++;
      }
      if(j == (ll)p.size())
      {
        j = lps[j - 1];
      }
      else if(i < (ll)t.size() && p[j] != t[i])
      {
        if(j)
        {
          j = lps[j - 1];
        }
        else
        {
          i++;
        }
      }
    }
  }
};

struct MCH
{
  //Manachar
  vector<ll> P;
  vector<char> convert(vector<char>& s)
  {
      vector<char> v;
      v.push_back('@');
      for (int i = 0; i < s.size(); i++)
      {
        v.push_back('#');
        v.push_back(s[i]);
      }
      v.push_back('#');
      v.push_back('$');
      return v;
  }
  vector<char> manachar(vector<char>& s)
  {
    vector<char> Q(convert(s));
    vector<ll> P(s.size() * 6);
    ll c = 0, r = 0;
    for (ll i = 1; i < Q.size() - 1; i++)
    {
      ll iMirror = c - (i - c);
      if(r > i)
      {
        P[i] = min(r - i, P[iMirror]);
      }
      while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]])
      {
        P[i]++;
      }
      if (i + P[i] > r)
      {
        c = i;
        r = i + P[i];
      }
    }
    ll maxPalindrome = 0;
    ll centerIndex = 0;
    for (ll i = 1; i < Q.size() - 1; i++)
    {
      if (P[i] > maxPalindrome)
      {
        maxPalindrome = P[i];
        centerIndex = i;
      }
    }
    //cout << centerIndex << " " << maxPalindrome << "\n";
    vector<char> res;
    ll i = 0;
    fr(i, (centerIndex - 1 - maxPalindrome) / 2, (centerIndex - 1 - maxPalindrome) / 2 + maxPalindrome, 1)
    {
      res.push_back(s[i]);
    }
    return res;
  }
};

struct BST
{
  //Binary-Search-Tree
  struct node
  {
    ll key = 0;
    node *left = NULL, *right = NULL;
  };
  node* insert(node* root, ll key)
  {
    if(root == NULL)
    {
      root = new node;
      root->key = key;
      return root;
    }
    if(key < root->key)
    {
      root->left = insert(root->left, key);
    }
    else
    {
      root->right = insert(root->right, key);
    }
    return root;
  }
  node* search(node* root, ll key)
  {
    if(root == NULL || root->key == key)
    {
      return root;
    }
    if (root->key < key)
    {
      return search(root->right, key);
    }
    return search(root->left, key);
  }
  node* minNode(node* root)
  {
      node *current = root;

      while(current && current->left != NULL)
      {
        current = current->left;
      }
      return current;
  }
  node* remove(node* root, ll key)
  {
    if (root == NULL)
    {
      return root;
    }
    if (key < root->key)
    {
      root->left = remove(root->left, key);
    }
    else if (key > root->key)
    {
      root->right = remove(root->right, key);
    }
    else
    {
      if(root->left == NULL)
      {
        node *temp = root->right;
        free(root);
        return temp;
      }
      else if (root->right == NULL)
      {
        node *temp = root->left;
        free(root);
        return temp;
      }
      else
      {
        node* temp = minNode(root->right);
        root->key = temp->key;
        root->right = remove(root->right, temp->key);
      }
    }
    return root;
  }
};

struct TRI
{
  //Trie
  struct node
  {
    node *child[26] = {NULL};
    bool *childf[26] = {0};
    bool isEnd = false;
  };
  bool search(node *root, string s)
  {
    node *ptr = root;
    for(ll i  = 0; i < s.size(); i++)
    {
      ll idx = s[i] - 'a';
      if(!ptr->child[idx])
      {
        return false;
      }
      if(ptr->childf[idx] == 0)
      {
        return false;
      }
      ptr = ptr->child[idx];
    }
    return (ptr != NULL && ptr->isEnd);
  }
  void insert(node *root, string s)
  {
    node *ptr = root;
    if(search(root, s) == false)
    {
      for(ll i = 0; i < s.size(); i++)
      {
        ll idx = s[i] - 'a';
        ptr->childf[idx]++;
        if(!ptr->child[idx])
        {
          ptr->child[idx] = new node;
        }
        ptr = ptr->child[idx];
      }
      ptr->isEnd = true;
    }
  }
  void remove(node *root, string s)
  {
    node *ptr = root;
    if(search(root, s) == true)
    {
      vector<node*>future;
      for(ll i = 0; i < s.size(); i++)
      {
        ll idx = s[i] - 'a';
        ptr->childf[idx]--;

        if(ptr->childf[idx] == 0)
        {
          future.push_back(ptr->child[idx]);
        }
        ptr = ptr->child[idx];
      }
      ptr->isEnd = false;
      for(ll i = 0; i < future.size(); i++) delete(future[i]);
    }
  }
};

struct FTR
{
  //Fenwick-Tree
  vector<ll> bit;
  ll n;
  FTR(ll n)
  {
    this->n = n;
    bit.assign(n, 0);
  }
  FTR(vector<ll> a) : FTR(a.size())
  {
    for (ll i = 0; i < a.size(); i++) ops(i, a[i]);
  }
  ll query(ll r)
  {
    ll ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
    {
      ret += bit[r];
    }
    return ret;
  }
  ll queryRange(ll l, ll r)
  {
      return query(r) - query(l - 1);
  }
  void ops(ll idx, ll delta)
  {
      for (; idx < n; idx = idx | (idx + 1))
      {
        bit[idx] += delta;
      }
  }
};

struct F2D
{
  //2D-Range-Query
  vector<vector<ll>> bit;
  ll n, m;
  F2D(ll n, ll m)
  {
    this->n = n;
    this->m = m;
    vector<ll> tmp(m, 0);
    bit.assign(n, tmp);
  }
  F2D(vector<vector<ll>> a) : F2D(a.size(), a[0].size())
  {
    for (ll i = 0; i < a.size(); i++)
    {
      for (ll j = 0; j < a[0].size(); j++)
      {
        ops(i, j, a[i][j]);
      }
    }
  }
  ll query(ll x, ll y)
  {
    ll ret = 0;
    for (ll i = x; i >= 0; i = (i & (i + 1)) - 1)
    {
      for (ll j = y; j >= 0; j = (j & (j + 1)) - 1)
      {
        ret += bit[i][j];
      }
    }
    return ret;
  }
  void ops(ll x, ll y, ll delta)
  {
    for (ll i = x; i < n; i = i | (i + 1))
    {
      for (ll j = y; j < m; j = j | (j + 1))
      {
          bit[i][j] += delta;
      }
    }
  }
};

struct STR
{
  //Segment-Tree
  void build(vector<ll>&tree, vector<ll> v, ll idx, ll s, ll e)
  {
    //cout << idx << " " << tree[idx] << "\n";
    if(s > e) return;
    if(s == e)
    {
      tree[idx] = v[s];
      return;
    }
    ll mid = (s + e) / 2;
    build(tree, v, 2 * idx, s, mid);
    build(tree, v, 2 * idx + 1, mid + 1, e);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
  }
  ll query(vector<ll>tree, ll idx, ll s, ll e, ll l, ll r)
  {
    if(l > e || r < s)
    {
      return 0;
    }
    if(s >= l  && e <= r)
    {
      return tree[idx];
    }
    ll mid = (s + e) / 2;
    ll left = query(tree, 2 * idx, s, mid, l, r);
    ll right = query(tree, 2 * idx + 1, mid + 1, e, l, r);
    return (left + right);
  }
  void pointUpdate(vector<ll> & tree, ll idx, ll s, ll e, ll i, ll val)
  {
    if(i < s || i > e)
    {
      return;
    }
    if(s == e)
    {
      tree[idx] += val;
      return;
    }
    ll mid = (s + e) / 2;
    pointUpdate(tree, 2 * idx, s, mid, i, val);
    pointUpdate(tree, 2 * idx + 1, mid + 1, e, i, val);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
  }
  void rangeUpdate(vector<ll>& tree, ll idx, ll s, ll e, ll l, ll r, ll chg)
  {
    if(l > e || r < s)
    {
      return;
    }
    if(s == e)
    {
      if(tree[idx] >= chg)
      {
        tree[idx] -= chg;
      }
      else
      {
        tree[idx] = 0;
      }
      return;
    }
    ll mid = (s + e) / 2;
    rangeUpdate(tree, 2 * idx, s, mid, l, r, chg);
    rangeUpdate(tree, 2 * idx + 1, mid + 1, e, l, r, chg);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
  }
};

struct STG
{
  //Set-Generation
  void mask_gen(vector<vector<ll>>& mask, vector<ll>pat, ll i)
  {
    if(i == pat.size())
    {
      return;
    }
    mask.push_back(pat);
    mask_gen(mask, pat, i + 1);
    pat[i] = 1;
    mask.push_back(pat);
    mask_gen(mask, pat, i + 1);
  }
  vector<vector<ll>> com_gen(vector<ll> v, ll k = 3)
  {
    ll n = v.size();
    string bitmask(k, 1);
    bitmask.resize(n, 0);
    vector<vector<ll>> res;
    do
    {
      vector<ll> tmp;
      for(ll i = 0; i < n; ++i)
      {
        if (bitmask[i])
        {
          tmp.push_back(v[i]);
        }
      }
      res.push_back(tmp);
    }
    while(prev_permutation(bitmask.begin(), bitmask.end()));
    return res;
  }
  vector<vector<ll>> perm_gen(vector<ll> v, ll k = 3)
  {
    vector<vector<ll>> res;
    vector<vector<ll>> tmp(com_gen(v, k));
    for(ll i = 0; i < tmp.size(); i++)
    {
      sort(tmp[i].begin(), tmp[i].end());
      while(next_permutation(tmp[i].begin(), tmp[i].end()))
      {
        res.push_back(tmp[i]);
      }
    }
    return res;
  }
};

struct ARP
{
  //Arpa's Trick
  void query(vector<pair<ll, ll>> q, vector<ll>v)
  {
    DSU dsu(v.size());
    vector<vector<pair<ll, ll>>> p(q.size(), vector<pair<ll, ll>>());
    vector<ll> answer(q.size());
    stack<ll> s;
    for(ll i = 0; i < p.size(); i++)
    {
      p[q[i].second].push_back({i,q[i].first});
    }
    for(ll i = 0; i < v.size(); i++)
    {
      while (!s.empty() && v[s.top()] > v[i])
      {
        dsu.parent[s.top()] = i;
        s.pop();
      }
      s.push(i);
      for (pair<ll, ll> j : p[i])
      {
        answer[j.first] = v[dsu.find_set(j.second)];
      }
    }
  }
};

struct BDG
{
  //Finding-Bridges-Online
  vector<ll> par, dsu_2ecc, dsu_cc, dsu_cc_size, last_visit;
  ll bridges = 0, lca_iteration = 0;
  BDG(ll n)
  {
    par.resize(n);
    dsu_2ecc.resize(n);
    dsu_cc.resize(n);
    dsu_cc_size.resize(n);
    lca_iteration = 0;
    last_visit.assign(n, 0);
    for(ll i = 0; i < n; ++i)
    {
      dsu_2ecc[i] = i;
      dsu_cc[i] = i;
      dsu_cc_size[i] = 1;
      par[i] = -1;
    }
    bridges = 0;
  }
  ll find_2ecc(ll v)
  {
    if (v == -1)
    {
      return -1;
    }
    else
    {
      return dsu_2ecc[v] == v ? v : dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]);
    }
  }
  ll find_cc(ll v)
  {
    v = find_2ecc(v);
    return dsu_cc[v] == v ? v : dsu_cc[v] = find_cc(dsu_cc[v]);
  }
  void make_root(ll v)
  {
    v = find_2ecc(v);
    ll root = v, child = -1;
    while(v != -1)
    {
      ll p = find_2ecc(par[v]);
      par[v] = child;
      dsu_cc[v] = root;
      child = v;
      v = p;
    }
    dsu_cc_size[root] = dsu_cc_size[child];
  }
  void merge_path (ll a, ll b)
  {
    ++lca_iteration;
    vector<ll> path_a, path_b;
    ll lca = -1;
    while(lca == -1)
    {
      if(a != -1)
      {
        a = find_2ecc(a);
        path_a.push_back(a);
        if(last_visit[a] == lca_iteration)
        {
          lca = a;
          break;
        }
        last_visit[a] = lca_iteration;
        a = par[a];
      }
        if(b != -1)
        {
          b = find_2ecc(b);
          path_b.push_back(b);
          if(last_visit[b] == lca_iteration)
          {
            lca = b;
            break;
          }
          last_visit[b] = lca_iteration;
          b = par[b];
        }
    }
    for(ll v : path_a)
    {
      dsu_2ecc[v] = lca;
      if(v == lca) break;
      --bridges;
    }
    for(ll v : path_b)
    {
      dsu_2ecc[v] = lca;
      if (v == lca) break;
      --bridges;
    }
  }
  void add_edge(ll a, ll b)
  {
    a = find_2ecc(a);
    b = find_2ecc(b);
    if (a == b)
    {
      return;
    }
    ll ca = find_cc(a);
    ll cb = find_cc(b);
    if (ca != cb)
    {
      ++bridges;
      if (dsu_cc_size[ca] > dsu_cc_size[cb])
      {
        swap(a, b);
        swap(ca, cb);
      }
      make_root(a);
      par[a] = dsu_cc[a] = b;
      dsu_cc_size[cb] += dsu_cc_size[a];
    }
    else
    {
      merge_path(a, b);
    }
  }
};

struct KRK
{
  //kruksal's
  struct edge
  {
    ll u, v, weight;
    bool operator<(edge const& other)
    {
      return weight < other.weight;
    }
  };
  vector<pair<ll, ll>> kruksal(vector<vector<ll>>v)
  {
    ll n = v.size(), cost = 0;
    vector<edge> edges;
    vector<pair<ll, ll>> res;
    DSU dsu(n);
    for(ll i = 0; i < v.size(); i++)
    {
      for(ll j = 0; j < v[i].size(); j++)
      {
        edge e;
        e.u = i;
        e.v = j;
        e.weight = v[i][j];
        edges.push_back(e);
      }
    }
    sort(edges.begin(), edges.end());
    for (edge e : edges)
    {
    if (dsu.find_set(e.u) != dsu.find_set(e.v))
     {
       cost += e.weight;
       res.push_back({e.u, e.v});
       dsu.union_set(e.u, e.v);
     }
    }
    return res;
  }
};

struct ART
{
  //Finding Articulation Point
  vector<vector<ll>> adj;
  vector<bool> visited;
  vector<ll> tin, low;
  vector<ll> cut;
  ll timer;
  void dfs(ll v, int p = -1)
   {
     visited[v] = true;
     tin[v] = low[v] = timer++;
     ll children = 0;
     for (ll to : adj[v])
     {
       if (to == p)
       {
         continue;
       }
       if (visited[to])
       {
         low[v] = min(low[v], tin[to]);
       }
       else
       {
         dfs(to, v);
         low[v] = min(low[v], low[to]);
         if (low[to] >= tin[v] && p != -1)
         {
           cut.push_back(v);
         }
         ++children;
       }
     }
     if(p == -1 && children > 1)
     {
       cut.push_back(v);
     }
   }
  vector<ll> find_cut(vector<vector<ll>> v)
  {
    adj.assign(v.begin(), v.end());
    visited.assign(v.size(), false);
    timer = 0;
    tin.assign(v.size(), -1);
    low.assign(v.size(), -1);
    cut.clear();
    for (ll i = 0; i < v.size(); ++i)
    {
      if(!visited[i])
      {
        dfs(i);
      }
    }
    return cut;
  }
};

struct BPT
{
  //Bipartite-Check-Online
  vector<ll> rank;
  vector<pair<ll, ll>> parent;
  vector<bool> bipartite;
  BPT(ll n)
  {
    rank.assign(n, 0);
    parent.resize(n);
    bipartite.resize(n);
    for(ll i = 0; i < n; i++)
    {
      parent[i].first = i;
    }
  }
  void make_set(ll v)
  {
    parent[v] = make_pair(v, 0);
    rank[v] = 0;
    bipartite[v] = true;
  }
  pair<ll, ll> find_set(ll v)
  {
    if (v != parent[v].first)
    {
      ll parity = parent[v].second;
      parent[v] = find_set(parent[v].first);
      parent[v].second ^= parity;
    }
    return parent[v];
  }
  void add_edge(ll a, ll b)
  {
    pair<ll, ll> pa = find_set(a);
    a = pa.first;
    ll x = pa.second;
    pair<ll, ll> pb = find_set(b);
    b = pb.first;
    ll y = pb.second;
    if (a == b)
    {
      if (x == y) bipartite[a] = false;
    }
    else
    {
      if (rank[a] < rank[b]) swap (a, b);
      {
        parent[b] = make_pair(a, x ^ y ^ 1);
      }
      bipartite[a] = bipartite[a] & bipartite[b];
      if (rank[a] == rank[b])
      {
        ++rank[a];
      }
    }
  }
  bool is_bipartite(ll v)
  {
    return bipartite[find_set(v).first];
  }
};

struct SCC
{
  //Shortest-Connected-Component
  struct TAR
  {
    //Tarjan's
    vector<vector<ll>> adj;
    void util(ll u, vector<ll> disc, vector<ll> low, stack<ll> *st, vector<ll> stackMember, vector<vector<ll>> &res)
    {
      static ll time = 0;
      disc[u] = low[u] = ++time;
      st->push(u);
      stackMember[u] = true;
      for (auto v:adj[u])
      {
        if (disc[v] == -1)
        {
          util(v, disc, low, st, stackMember, res);
          low[u]  = min(low[u], low[v]);
        }
        else if (stackMember[v] == true)
        {
          low[u]  = min(low[u], disc[v]);
        }
      }
      ll w = 0;
      if (low[u] == disc[u])
      {
        vector<ll> tmp;
        while (st->top() != u)
        {
          w = (ll) st->top();
          tmp.push_back(w);
          stackMember[w] = false;
          st->pop();
        }
        w = (ll) st->top();
        tmp.push_back(w);
        res.push_back(tmp);
        stackMember[w] = false;
        st->pop();
      }
    }
    vector<vector<ll>> tarjan_ssc(vector<vector<ll>> v)
    {
      vector<ll> disc(v.size());
      vector<ll> low(v.size());
      vector<ll> stackMember (v.size());
      stack<ll> *st = new stack<ll>();
      vector<vector<ll>> res;
      adj.assign(v.begin(), v.end());
      for(ll i = 0; i < v.size(); i++)
      {
        disc[i] = INF;
        low[i] = INF;
        stackMember[i] = false;
      }
      for(ll i = 0; i < v.size(); i++)
      if (disc[i] == INF)
      util(i, disc, low, st, stackMember, res);
      return res;
    }
  };

  struct KOS
  {
    //kosaraju's
    vector<vector<ll>> g, gr;
    vector<bool> used;
    vector<ll> order, component;
    void dfs1 (ll v)
    {
      used[v] = true;
      for(ll i = 0; i < g[v].size(); ++i)
      {
        if(!used[ g[v][i] ])
        {
          dfs1(g[v][i]);
        }
      }
      order.push_back (v);
    }
    void dfs2 (int v)
    {
      used[v] = true;
      component.push_back (v);
      for (ll i=0; i < gr[v].size(); ++i)
      {
        if(!used[gr[v][i]])
        {
          dfs2(gr[v][i]);
        }
      }
    }
    vector<vector<ll>> kosaraju(vector<vector<ll>> adj)
    {
      vector<vector<ll>> res;
      g.assign(adj.begin(), adj.end());
      gr.resize(adj.size());
      for(ll i = 0; i < adj.size(); i++)
      {
        for(ll j = 0; j < adj[i].size(); j++)
        {
          gr[g[i][j]].push_back(i);
        }
      }
      used.assign (adj.size(), false);
      for (ll i = 0; i < adj.size(); ++i)
      {
        if (!used[i]) dfs1(i);
        {
          used.assign(adj.size(), false);
        }
      }
      for (ll i = 0; i < adj.size(); ++i)
      {
        ll v = order[adj.size() - 1 - i];
        if (!used[v])
        {
          dfs2(v);
          res.push_back(component);
          component.clear();
        }
      }
      return res;
    }
  };
};

struct LCA
{
  //Lowest-Common-Ancestor
  struct BL
  {
    //Binary-Lifting
    ll n, l, timer;
    vector<vector<ll>> adj;
    vector<ll> tin, tout;
    vector<vector<ll>> up;
    vector<vector<ll>> blca(vector<vector<ll>> v, ll r)
    {
      vector<vector<ll>> res(v);
      adj.assign(v.begin(), v.end());
      n = v.size();
      preprocess(r);
      for(ll i = 0; i < v.size(); i++)
      {
        for(ll j = 0; j < v[i].size(); j++)
        {
          res[i][v[i][j]] = lca(i, v[i][j]);
        }
      }
      return res;
    }

    void dfs(ll v, ll p)
    {
      tin[v] = ++timer;
      up[v][0] = p;
      for(ll i = 1; i <= l; ++i)
      {
        up[v][i] = up[up[v][i-1]][i-1];
      }
      for(ll u : adj[v])
      {
        if(u != p)
        {
          dfs(u, v);
        }
      }
      tout[v] = ++timer;
    }
    bool is_ancestor(ll u, ll v)
    {
      return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    ll lca(ll u, ll v)
    {
      if(is_ancestor(u, v))
      {
        return u;
      }
      if(is_ancestor(v, u))
      {
        return v;
      }
      for (ll i = l; i >= 0; --i)
      {
        if(!is_ancestor(up[u][i], v))
        {
          u = up[u][i];
        }
      }
      return up[u][0];
    }
    void preprocess(ll root)
    {
      tin.resize(n);
      tout.resize(n);
      timer = 0;
      l = ceil(log2(n));
      up.assign(n, vector<ll>(l + 1));
      dfs(root, root);
    }
  };

  struct DS
  {
    //DSU
    vector<vector<ll>> adj;
    vector<vector<ll>> queries;
    vector<vector<ll>> res;
    vector<ll> ancestor;
    vector<bool> visited;
    DSU dsu = DSU(1000000);

    void dfs(ll v)
    {
      visited[v] = true;
      ancestor[v] = v;
      for (ll u : adj[v])
      {
        if (!visited[u])
        {
          dfs(u);
          dsu.union_set(v, u);
          ancestor[dsu.find_set(v)] = v;
        }
      }
      for (ll other_node : queries[v])
      {
        if(visited[other_node])
        {
          res[v][other_node] = ancestor[dsu.find_set(other_node)];
        }
      }
    }
    vector<vector<ll>> lca(vector<vector<ll>>v ,vector<vector<ll>>q)
    {
      adj.assign(v.begin(), v.end());
      queries.assign(q.begin(), q.end());
      ancestor.resize(v.size());
      visited.assign(v.size(), false);
      res.clear();
      dfs(0);
      return res;
    }
  };

  struct ET
  {
    //Euler-Tour
    vector<ll> height, euler, first, segtree;
    vector<bool> visited;
    ll n;
    ET(vector<vector<ll>> &adj, ll root = 0)
    {
      n = adj.size();
      height.resize(n);
      first.resize(n);
      euler.reserve(n * 2);
      visited.assign(n, false);
      dfs(adj, root);
      ll m = euler.size();
      segtree.resize(m * 4);
      build(1, 0, m - 1);
    }
    void dfs(vector<vector<ll>> &adj, ll node, ll h = 0)
    {
      visited[node] = true;
      height[node] = h;
      first[node] = euler.size();
      euler.push_back(node);
      for (auto to : adj[node])
      {
        if (!visited[to])
        {
          dfs(adj, to, h + 1);
          euler.push_back(node);
        }
      }
    }
    void build(ll node, ll b, ll e)
    {
      if (b == e)
      {
        segtree[node] = euler[b];
      }
      else
      {
        ll mid = (b + e) / 2;
        build(node << 1, b, mid);
        build(node << 1 | 1, mid + 1, e);
        ll l = segtree[node << 1], r = segtree[node << 1 | 1];
        segtree[node] = (height[l] < height[r]) ? l : r;
      }
    }
   ll query(ll node, ll b, ll e, ll l, ll r)
   {
     if (b > r || e < l)
     {
       return -1;
     }
     if (b >= l && e <= r)
     {
       return segtree[node];
     }
     ll mid = (b + e) >> 1;
     ll left = query(node << 1, b, mid, l, r);
     ll right = query(node << 1 | 1, mid + 1, e, l, r);
     if (left == -1)
     {
       return right;
     }
     if (right == -1)
     {
       return left;
     }
     return height[left] < height[right] ? left : right;
   }
   ll lca(ll u, ll v)
   {
     ll left = first[u], right = first[v];
     if (left > right)
     {
       swap(left, right);
     }
     return query(1, 0, euler.size() - 1, left, right);
   }
  };
};

struct SQD
{
  //Square-Root-Decomposition
  vector<ll> decompose(vector<ll>v, vector<vector<ll>>q)
  {
    ll n = v.size();
    ll len = (ll) sqrt(n + 0) + 1;
    vector<ll> b(len);
    vector<ll> res(q.size(), 0);
    for(ll i = 0; i < n; ++i)
    {
      b[i / len] += v[i];
    }
    for (ll k = 0; k < q.size(); k++)
    {
      ll l = q[k][0], r = q[k][0];
      ll sum = 0;
      ll c_l = l / len, c_r = r / len;
      if (c_l == c_r)
      {
        for (ll i = l; i <= r; ++i)
        {
          sum += v[i];
        }
      }
    else
     {
       for (ll i = l, end = (c_l + 1) * len - 1; i <= end; ++i)
       {
         sum += v[i];
       }
       for (ll i=c_l+1; i<=c_r-1; ++i)
       {
         sum += b[i];
       }
       for (ll i=c_r*len; i<=r; ++i)
       {
         sum += v[i];
       }
     }
    }
    return res;
  }
};

struct LHD
{
  //Light-Heavy-Decomposition
  vector<vector<ll>> adj, costs, indexx, pa;
  vector<ll> baseArray, chainInd, chainHead, posInBase, depth;
  vector<ll> otherEnd, subsize, st, qt;
  ll ptr, chainNo;
  void decompose(vector<vector<ll>> v, vector<vector<ll>> c)
  {
    adj.assign(v.begin(), v.end());
    costs.assign(c.begin(), c.end());
    indexx.assign(v.size(), vector<ll>(v.size()));
    baseArray.assign(v.size(), 0);
    chainInd.assign(v.size(), 0);
    chainHead.assign(v.size(), 0);
    posInBase.assign(v.size(), 0);
    depth.assign(v.size(), 0);
    otherEnd.assign(v.size(), 0);
    subsize.assign(v.size(), 0);
    st.assign(v.size() * 6, 0);
    qt.assign(v.size() * 6, 0);
    pa.assign(v.size() * 6, vector<ll>(v.size()));
  }
  void make_tree(ll cur, ll s, ll e)
  {
  	if(s == e-1)
    {
  		st[cur] = baseArray[s];
  		return;
  	}
  	ll c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
  	make_tree(c1, s, m);
  	make_tree(c2, m, e);
  	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
  }
  void update_tree(ll cur, ll s, ll e, ll x, ll val)
  {
  	if(s > x || e <= x)
    {
      return;
    }
  	if(s == x && s == e-1)
    {
  		st[cur] = val;
  		return;
  	}
  	ll c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
  	update_tree(c1, s, m, x, val);
  	update_tree(c2, m, e, x, val);
  	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
  }
  void query_tree(ll cur, ll s, ll e, ll S, ll E)
  {
  	if(s >= E || e <= S)
    {
  		qt[cur] = -1;
  		return;
  	}
  	if(s >= S && e <= E)
    {
  		qt[cur] = st[cur];
  		return;
  	}
  	ll c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
  	query_tree(c1, s, m, S, E);
  	query_tree(c2, m, e, S, E);
  	qt[cur] = qt[c1] > qt[c2] ? qt[c1] : qt[c2];
  }
  ll query_up(ll u, ll v)
  {
    if(u == v) return 0;
  	ll uchain, vchain = chainInd[v], ans = -1;
  	while(1)
    {
  		uchain = chainInd[u];
  		if(uchain == vchain)
       {
         if(u==v)
         {
           break;
         }
         query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
         if(qt[1] > ans)
         {
           ans = qt[1];
         }
         break;
  		 }
       query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
       if(qt[1] > ans)
       {
         ans = qt[1];
       }
       u = chainHead[uchain];
    	 u = pa[0][u];
  	 }
     return ans;
  }
  ll LCA(ll u, ll v)
  {
  	if(depth[u] < depth[v])
    {
      swap(u,v);
    }
  	ll diff = depth[u] - depth[v];
  	for(ll i = 0; i < adj.size() * 6; i++)
    {
      if( (diff >> i) &1 )
      {
        u = pa[i][u];
      }
    }
  	if(u == v)
    {
      return u;
    }
  	for(ll i = adj.size() * 6 - 1; i >= 0; i--)
    {
      if(pa[i][u] != pa[i][v])
      {
        u = pa[i][u];
    		v = pa[i][v];
  	  }
    }
  	return pa[0][u];
  }
  void query(ll u, ll v)
  {
    ll lca = LCA(u, v);
  	ll ans = query_up(u, lca);
  	ll temp = query_up(v, lca);
  	if(temp > ans)
    {
      ans = temp;
    }
  	cout << ans << "\n";
  }
  void change(ll i, ll val)
  {
  	ll u = otherEnd[i];
  	update_tree(1, 0, ptr, posInBase[u], val);
  }
  void HLD(ll curNode, ll cost, ll prev)
  {
  	if(chainHead[chainNo] == -1)
    {
  		chainHead[chainNo] = curNode;
  	}
  	chainInd[curNode] = chainNo;
  	posInBase[curNode] = ptr;
  	baseArray[ptr++] = cost;
  	ll sc = -1, ncost;
  	for(ll i = 0; i<adj[curNode].size(); i++)
    {
      if(adj[curNode][i] != prev)
      {
        if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]])
        {
          sc = adj[curNode][i];
          ncost = costs[curNode][i];
        }
    	}
    }
  	if(sc != -1)
    {
  		HLD(sc, ncost, curNode);
  	}
  	for(ll i = 0; i < adj[curNode].size(); i++)
    {
      if(adj[curNode][i] != prev)
      {
        if(sc != adj[curNode][i])
        {
    			chainNo++;
    			HLD(adj[curNode][i], costs[curNode][i], curNode);
    		}
      }
  	}
  }
  void dfs(ll cur, ll prev, ll _depth=0)
  {
    pa[0][cur] = prev;
  	depth[cur] = _depth;
  	subsize[cur] = 1;

  	for(ll i = 0; i < adj[cur].size(); i++)
    {
      if(adj[cur][i] != prev)
      {
  			otherEnd[indexx[cur][i]] = adj[cur][i];
  			dfs(adj[cur][i], cur, _depth+1);
  			subsize[cur] += subsize[adj[cur][i]];
      }
    }
  }
};

struct SPM
{
  //Sparse-Matrix
  vector<ll> log;
  vector<vector<ll>> st;
  ll func(ll a, ll b)
  {
    return min(a , b);
  }
  void construct(vector<ll> v, ll k)
  {
    log.assign(v.size() + 1, 0);
    st.assign(v.size(), vector<ll>(k + 1));
    for (ll i = 2; i <= v.size(); i++)
    {
      log[i] = log[i/2] + 1;
    }
    for (ll i = 0; i < v.size(); i++)
    {
      st[i][0] = v[i];
    }
    for (ll j = 1; j <= k; j++)
    {
      for (ll i = 0; i + (1 << j) <= v.size(); i++)
      {
        st[i][j] = func(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  ll query(ll l , ll r)
  {
    ll j = log[r - l + 1];
    return func(st[l][j], st[r - (1 << j) + 1][j]);
  }
};

struct EUT
{
  //Euler-Tour
  vector<ll> tour(vector<vector<ll>> v)
  {
    ll n = v.size(), first = 0, v1 = -1, v2 = -1;
    vector<vector<ll>> g(v);
    vector<ll> deg(n), res;
    bool bad = false;
    for(ll i = 0; i < n; ++i)
    {
      for(ll j = 0; j < n; ++j)
      {
        deg[i] += g[i][j];
      }
    }
    while(first < n && !deg[first])
    {
      ++first;
    }
    if(first == n)
    {
      cout << -1;
      return res;
    }
    stack<ll> st;
    st.push(first);
    for (ll i = 0; i < n; ++i)
    {
      if (deg[i] & 1)
      {
        if (v1 == -1)
        {
          v1 = i;
        }
        else if(v2 == -1)
        {
          v2 = i;
        }
        else
        {
          bad = true;
        }
      }
    }
    if (v1 != -1)
    {
      ++g[v1][v2];
      ++g[v2][v1];
    }
    while (!st.empty())
    {
      ll v = st.top(), i;
      for(i = 0; i < n; ++i)
      {
        if (g[v][i])
        {
          break;
        }
      }
      if (i == n)
      {
        res.push_back(v);
        st.pop();
      }
      else
      {
        --g[v][i];
        --g[i][v];
        st.push(i);
      }
    }
    if (v1 != -1)
    {
      for (ll i = 0; i + 1 < res.size(); ++i)
      {
        if ((res[i] == v1 && res[i + 1] == v2) ||(res[i] == v2 && res[i + 1] == v1))
        {
          vector<ll> res2;
          for (ll j = i + 1; j < res.size(); ++j)
          {
            res2.push_back(res[j]);
          }
          for (ll j = 1; j <= i; ++j)
          {
            res2.push_back(res[j]);
          }
          res = res2;
          break;
        }
      }
    }
    for (ll i = 0; i < n; ++i)
    {
      for (ll j = 0; j < n; ++j)
      {
        if (g[i][j])
        {
          bad = true;
        }
      }
    }
    if(bad)
    {
      cout << -1;
    }
    else
    {
      for(ll x : res)
      {
        cout << x << " ";
      }
    }
  }
};

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

  struct MO
  {
    void remove(ll idx)
    {
      // TODO: remove value at idx from data structure
    }

    void add(ll idx)
    {
       // TODO: add value at idx from data structure
    }

    ll get_answer()
    {
      // TODO: extract the current answer of the data structure
      return 0;
    }

    struct Query
    {
      ll l, r, idx, block_size;
      bool operator<(Query other) const
      {
        return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
      }
    };
    vector<ll> mo_s_algorithm(vector<Query> queries)
    {
      vector<ll> answers(queries.size());
      sort(queries.begin(), queries.end());
      ll cur_l = 0;
      ll cur_r = -1;
      for (Query q : queries)
      {
        while (cur_l > q.l)
        {
          cur_l--;
          add(cur_l);
        }
        while (cur_r < q.r)
        {
          cur_r++;
          add(cur_r);
        }
        while (cur_l < q.l)
        {
          remove(cur_l);
          cur_l++;
        }
        while (cur_r > q.r)
        {
          remove(cur_r);
          cur_r--;
        }
        answers[q.idx] = get_answer();
      }
      return answers;
    }
  };

  struct FDW
  {
    vector<vector<ll>> floydWarshall(vector<vector<ll>> v)
    {
      vector<vector<ll>>  dist(v);
      ll i, j, k;
      for (k = 0; k < v.size(); k++)
      {
        for (i = 0; i < v.size(); i++)
        {
          for (j = 0; j < v.size(); j++)
          {
            if (dist[i][k] + dist[k][j] < dist[i][j])
            {
              dist[i][j] = dist[i][k] + dist[k][j];
            }
          }
        }
      }
      return dist;
    }
  };
};

struct PSA
{
  vector<ll> prefix(vector<ll> v)
  {
    vector<ll> res(v.size(), 0);
    ll i = 0;
    fr(i, 1, v.size(), 1)
    {
      res[i] = res[i- 1] + v[i];
    }
    return res;
  }
  vector<ll> sufix(vector<ll> v)
  {
    v = prefix(v);
    vector<ll> res(v.size(), 0);
    ll i = 0;
    fr(i, 1, v.size(), 1)
    {
      res[i] = v[v.size() - 1] + v[i - 1];
    }
    return res;
  }
};

struct FFT
{

};

struct NTT
{

};

struct PRM
{
  //Prime's
};

struct TPS
{
  //Topological-Sorting
};

struct CYD
{
  //Cycle-Detection
};

struct MTM
{
  //Meet-In-The-Middle
};

struct CVH
{
  //Convex-Hull
  //Monotone-chain
  //Graham-Scan
  //Gift-Wrapping
};

struct FLW
{
  //Ford-Fulkerson
  //Edmonds-Karp
  //Dinic's
};

struct STK
{
  //Next-Greater-Left
  //Next-Smaller-Left
  //Next-Greater-Right
  //Next-Smaller-Right
};

struct SLW
{
  //Sliding-Window-Maximum
  //Sliding-Window-Minimum
  //Sliding-Window-Median
};

struct IGQ
{
  ll query_sim(string q)
  {
    ll ans = 0;
    stringstream s(q);
    return ans;
  }
  ll query(ll x, ll y)
  {
    string q = to_string(x) + " " + to_string(y) + "\n";
    ll res;
    cout << q;
    fflush(stdout);
    //cin >> res;
    res = query_sim(q);
    return res;
  }
};

struct BTS
{
  void rangeTS(ll l, ll u, ll &ans , ll k = -1)
  {
    if (u < l)
    {
      return;
    }
    ll mids = l + (u - l) / 3;
    ll midu = u - (u - l) / 3;
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
    if(mids > k)
    {
      rangeTS(l, mids - 1, ans, k);
    }
    if(midu < k)
    {
      rangeTS(midu + 1, l, ans, k);
    }
    rangeTS(mids + 1, midu - 1, ans, k);
  }
  void rangeBS(ll p, ll k, ll l, ll u, ll &ans)
  {
    if (u < l) return;
    ll mid = (l + u) / 2;

    if(mid == k)
    {
      ans = mid;
      return;
    }
    else
    {
      if(mid > k)
      {
        rangeBS(p, k, l ,mid - 1 ,ans);
      }
      else
      {
        rangeBS(p ,k ,mid + 1 ,u ,ans);
      }
    }
  }
};

struct DP
{
  ll digitDp(unordered_map<string, ll>memo, string m, vector<ll>lim, ll k)
  {
    // lim vector should be stored in reversed order
    //DP table retrieval
    stringstream s(m);
    ll num = 0, sum = 0, flag = 0, pos = 0, limit = 9, i = 0;
    s >> pos;
    s >> num;
    s >> sum;
    s >> flag;
    if(flag == 0)
    {
      limit = lim[pos];
    }
    //Base condition
    if(pos == lim.size())
    {
      if(num % k == 0 && sum % k == 0)
      {
        return 1;
      }
      return 0;
    }
    //Subsolution check
    if(memo.find(m) != memo.end()) return memo[m];
    //Recursion
    ll res = 0;
    fr(i ,0 ,limit + 1, 1)
    {
      ll next_flag = (flag == 0 && i < limit) ? 1 : flag;
      // Main logic goes below;
      string new_num = to_string(num);
      new_num.push_back((char)(i + 48));
      string new_m = to_string(pos + 1) + " " + new_num + " " + to_string(sum + i)+ " " + to_string(next_flag);
      //cout << new_m << "\n";
      res += digitDp(memo, new_m, lim, k);
    }
    return (memo[m] = res);
  }
};

bool comp(ll a, ll b)
{
  return a.t < b.t;
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

    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
