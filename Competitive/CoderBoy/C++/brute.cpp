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

      fact[0] = 1;
      for(ll i = 1; i < n; i++)
          fact[i] = (fact[i-1] * i) % q;

      is_prime[0] = is_prime[1] = false;
      for(ll i = 2; i <= n; i++)
          if(is_prime[i])
              for(ll j = i + i; j <= n; j += i)
                  is_prime[j] = false;
  }
  ll power_mod_q(ll x, ll n, ll q = R)
  {
    if(n == 0)
        return 1;
    if(n % 2 == 0)
        return power_mod_q((x * x) % q, n / 2, q);
    else
        return (x * power_mod_q((x * x) % q, n / 2, q)) % q;
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
        return 1;
    if(n % 2 == 0)
        return power(x * x, n / 2);
    else
        return x * power(x * x, n / 2);
  }
  vector<vector<ll>> multiply(vector<vector<ll>>& a, vector<vector<ll>>& b)
  {
    ll p = a.size(), q = b.size(), r = b[0].size();
    vector<vector<ll>> c(p, vector<ll>(r, 0));
    for(ll i = 0; i < p; i++)
        for(ll j = 0; j < r; j++)
            for(ll k = 0; k < q; k++)
                c[i][j] += (a[i][k] * b[k][j]) % R;
    return c;
  }
  vector<vector<ll>> add(vector<vector<ll>>& a, vector<vector<ll>>& b)
  {
    ll p = a.size(), q = a[0].size();
    vector<vector<ll>> c(p, vector<ll>(q));
    for(ll i = 0; i < p; i++)
        for(ll j = 0; j < q; j++)
            c[i][j] = a[i][j] + b[i][j];
    return c;
  }
  vector<vector<ll>> power(vector<vector<ll>>& a, ll n)
  {
    vector<vector<ll>> c(a.size(), vector<ll>(a.size(), 0));
    if(n == 0)
    {
        for(ll i = 0; i < (ll)a.size(); i++)
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
    vector<vector<ll>> fib(2, vector<ll>(2,1));
    fib[1][1] = 0;
    if(n == 0) return 0;
    vector<vector<ll>> ans(power(fib, n - 1));
    return ans[0][0];
  }
};

struct DSU
{
  vector<ll> rank, parent, num;
  DSU(ll n)
  {
    rank.assign(n, 0);
    parent.resize(n);
    num.assign(n, 1);
    for(ll i = 0; i < n; i++) parent[i] = i;
  }
  ll find_set(ll i)
  {
    if(i == parent[i]) return i;
    return parent[i] = find_set(parent[i]);
  }
  bool is_same_set(ll i, ll j)
  {
    if(find_set(i) == find_set(j)) return true;
    return false;
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
          parent[v] = u, num[u] += num[v];
      else
          parent[u] = v, num[v] += num[u];
    }
  }
};

struct KMP
{
  vector<ll> lps;
  KMP(vector<char>& p, vector<char>& t)
  {
    //PREPROCESSING
    lps.assign(p.size(), 0);
    lps[0] = 0;
    ll len = 0, i = 1, j;
    while(i < (ll)p.size())
    {
      if(p[i] == p[len]) lps[i++] = ++len;
      else if(len) len = lps[len - 1];
      else lps[i++] = 0;
    }
    //STRING MATCHING
    i = j = 0;
    while(i < (ll)t.size())
    {
      if(p[j] == t[i]) j++, i++;
      if(j == (ll)p.size())
      {
        //It's a match at index i - 1
        j = lps[j - 1];
      }
      else if(i < (ll)t.size() && p[j] != t[i])
      {
        if(j) j = lps[j - 1];
        else i++;
      }
    }
  }
};

struct MCH
{
  ll P[1000000] = {0};
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
    if(key < root->key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
  }
  node* search(node* root, ll key)
  {
    if(root == NULL || root->key == key) return root;
    if (root->key < key) return search(root->right, key);
    return search(root->left, key);
  }
  node* minNode(node* root)
  {
      node *current = root;
      while(current && current->left != NULL)
      current = current->left;
      return current;
  }
  node* remove(node* root, ll key)
  {
    if (root == NULL) return root;
    if (key < root->key) root->left = remove(root->left, key);
    else if (key > root->key) root->right = remove(root->right, key);
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
      if(!ptr->child[idx]) return false;
      if(ptr->childf[idx] == 0) return false;
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
        if(!ptr->child[idx]) ptr->child[idx] = new node;
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
        future.push_back(ptr->child[idx]);
        ptr = ptr->child[idx];
      }
      ptr->isEnd = false;
      for(ll i = 0; i < future.size(); i++) delete(future[i]);
    }
  }
};

struct FTR
{
  vector<int> bit;
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
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }
  ll queryRange(ll l, ll r)
  {
      return query(r) - query(l - 1);
  }
  void ops(ll idx, ll delta)
  {
      for (; idx < n; idx = idx | (idx + 1))
          bit[idx] += delta;
  }
};

struct F2D
{
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
      for (ll j = 0; j < a[0].size(); j++) ops(i, j, a[i][j]);
    }
  }
  ll query(ll x, ll y)
  {
    ll ret = 0;
    for (ll i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (ll j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += bit[i][j];
    return ret;
  }
  void ops(ll x, ll y, ll delta)
  {
    for (ll i = x; i < n; i = i | (i + 1))
        for (ll j = y; j < m; j = j | (j + 1))
            bit[i][j] += delta;
  }
};

struct STR
{
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
    if(l > e || r < s) return 0;
    if(s >= l  && e <= r) return tree[idx];
    ll mid = (s + e) / 2;
    ll left = query(tree, 2 * idx, s, mid, l, r);
    ll right = query(tree, 2 * idx + 1, mid + 1, e, l, r);
    return (left + right);
  }
  void pointUpdate(vector<ll> & tree, ll idx, ll s, ll e, ll i, ll val)
  {
    if(i < s || i > e)return;
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
    if(l > e || r < s)return;
    if(s == e)
    {
      if(tree[idx] >= chg)tree[idx] -= chg;
      else tree[idx] = 0;
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
  void mask_gen(vector<vector<ll>>& mask, vector<ll>pat, ll i)
  {
    if(i == pat.size()) return;
    mask.push_back(pat);
    mask_gen(mask, pat, i + 1);
    pat[i] = 1;
    mask.push_back(pat);
    mask_gen(mask, pat, i + 1);
  }
  vector<vector<ll>> com_gen(vector<ll> v)
  {
    ll n = v.size(), k = 3;
    string bitmask(k, 1);
    bitmask.resize(n, 0);
    vector<vector<ll>> res;
    do
    {
      vector<ll> tmp;
      for (ll i = 0; i < n; ++i)
      {
          if (bitmask[i]) tmp.push_back(v[i]);
      }
      res.push_back(tmp);
    }
    while(prev_permutation(bitmask.begin(), bitmask.end()));
    return res;
  }
  vector<vector<ll>> perm_gen(vector<ll> v)
  {
    vector<vector<ll>> res;
    return res;
  }
};

struct ARP
{
  void query(vector<pair<ll, ll>> q, vector<ll>v)
  {
    DSU dsu(v.size());
    vector<vector<pair<ll, ll>>> p(q.size(), vector<pair<ll, ll>>());
    vector<ll> answer(q.size());
    stack<ll> s;
    for(ll i = 0; i < p.size(); i++)
    p[q[i].second].push_back({i,q[i].first});
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
  vector<ll> par, dsu_2ecc, dsu_cc, dsu_cc_size;
  ll bridges = 0, lca_iteration = 0;
  vector<ll> last_visit;
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
    if (v == -1) return -1;
    return dsu_2ecc[v] == v ? v : dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]);
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
    if (a == b) return;
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
     for (ll to : adj[v]) {
         if (to == p) continue;
         if (visited[to]) {
             low[v] = min(low[v], tin[to]);
         } else {
             dfs(to, v);
             low[v] = min(low[v], low[to]);
             if (low[to] >= tin[v] && p != -1)
                 cut.push_back(v);
             ++children;
         }
     }
     if(p == -1 && children > 1)
         cut.push_back(v);
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
      if(!visited[i]) dfs(i);
    }
    return cut;
  }
};

struct BPT
{
  vector<ll> rank;
  vector<pair<ll, ll>> parent;
  vector<bool> bipartite;
  BPT(ll n)
  {
    rank.assign(n, 0);
    parent.resize(n);
    bipartite.resize(n);
    for(ll i = 0; i < n; i++)
    parent[i].first = i;
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
      parent[b] = make_pair(a, x ^ y ^ 1);
      bipartite[a] = bipartite[a] & bipartite[b];
      if (rank[a] == rank[b]) ++rank[a];
    }
  }
  bool is_bipartite(ll v)
  {
    return bipartite[find_set(v).first];
  }
};

struct SCC
{
  struct tarjan
  {
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
            low[u]  = min(low[u], disc[v]);
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
  struct kosaraju
  {
    vector<vector<ll>> g, gr;
    vector<bool> used;
    vector<ll> order, component;
    void dfs1 (ll v)
    {
      used[v] = true;
      for(ll i = 0; i < g[v].size(); ++i)
      if(!used[ g[v][i] ]) dfs1(g[v][i]);
      order.push_back (v);
    }
    void dfs2 (int v)
    {
      used[v] = true;
      component.push_back (v);
      for (ll i=0; i < gr[v].size(); ++i)
      if(!used[gr[v][i]]) dfs2(gr[v][i]);
    }
    vector<vector<ll>> kosar(vector<vector<ll>> adj)
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
      if (!used[i]) dfs1(i);
      used.assign(adj.size(), false);
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
  //binary lifting
  struct BL
  {

  };

  //DSU
  struct DS
  {
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
        res[v][other_node] = ancestor[dsu.find_set(other_node)];
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
  //euler tour
  struct ET
  {

  };
};

struct EUT
{
  //eular tour
};

struct BLF
{
  // biary lifting
};

struct MO
{
  // mo's algorithm
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
          if (!u[j] && (v == -1 || d[j] < d[v])) v = j;
        }
        if (d[v] == INF) break;
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
      path.push_back(v);
      path.push_back(s);
      reverse(path.begin(), path.end());
      return path;
    }
  };

  struct BMF
  {
    vector<ll> bford(vector<vector<ll>> e, ll v)
    {
      vector<ll> d(e.size(), INF);
      d[v] = 0;
      vector<ll> p(e.size() - 1);
      ll x;
      /*for(ll i = 0; i < e.size(); ++i)
      {
        x = -1;
        for(ll j = 0; j < e[i].size(); ++j)
        if (d[e[j].a] < INF)
        if (d[e[j].b] > d[e[j].a] + e[j].cost)
        {
          d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
          p[e[j].b] = e[j].a;
          x = e[j].b;
        }
      }
      if (x == -1)
      {
        //cout << "No negative cycle from " << v;
      }
      else
      {
        ll y = x;
        for(ll i = 0; i < e.size(); ++i) y = p[y];
        vector<ll> path;
        for(ll cur = y; ; cur = p[cur])
        {
          path.push_back (cur);
          if (cur == y && path.size() > 1) break;
        }
        reverse (path.begin(), path.end());
        //cout << "Negative cycle: ";
        for (ll i = 0; i < path.size(); ++i)
        {
          //cout << path[i] << ' ';
        }
      }*/
      return d;
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
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
      return dist;
    }
  };
};

struct MTM
{

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
  }

  void rangeBS(ll p, ll k, ll l, ll u, ll &ans)
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
  }
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

    if(flag == 0) limit = lim[pos];

    //Base condition
    if(pos == lim.size())
    {
      if(num % k == 0 && sum % k == 0)
      {
        //cout << num << " " << sum << "\n";
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

/*bool comp(data a, data b)
{
  return a.t < b.t;
}*/

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
      ll n = 0, bc = 0;
      cin >> n;
      vector<ll> pre;
      bitset<21> res;

      fr(i, 1, 21, 1)
      {
        //cout<< 1 << " " << ((1 << i) + 1) << "\n";
        cout.flush();
        cin >> k;
        pre.push_back(k);
      }

      bc = 22;
      cout << bc << "\n";
      res[0] = (pre[0] & 1);

      fr(i, 1, 21, 1)
      {
        ll r = (n + (abs(bc - pre[i - 1]) / (1 << i))) / 2;
        cout << abs(bc - pre[i - 1]) << " " << (1 << i) << "\n";
        if(bc >= pre[i - 1])
        {
          res[i] = r % 2;
        }
        else
        {
          res[i] = (n - r) % 2;
        }
      }
      cout << 2 << " " << res.to_ullong() << "\n";
      cout.flush();
      cin >> k;
      if(k == -1) return 0;
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
