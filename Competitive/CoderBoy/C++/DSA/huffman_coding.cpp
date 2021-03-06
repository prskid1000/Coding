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

struct Node {
  int f = 0;
  string c = "";
  Node *left = NULL, *right = NULL;
};

struct node {
    int f = 0;
    string c = "";
    bool operator()(node const& a, node const& b)
    {
        return a.f > b.f;
    }
};

void pnode(Node *root, string s)
{
  if(root->c.length() == 1)
  {
    cout << root->c << " " << s << "\n";
    return;
  }

  if(root->left) pnode(root->left, s + "0");
  if(root->right) pnode(root->right, s + "1");
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
      cin >> n;

      string s = "";
      cin >> s;

      priority_queue<node, vector<node>, node> mh;
      map<string, Node*> mp;

      int freq[26] = {0};

      for(int i = 0; i < n; i++)
      {
        freq[s[i] - 'a']++;
      }

      for(int i = 0; i < 26; i++)
      {
        node *np = new node();
        np->f = freq[i];
        np->c = i + 'a';
        mh.push(*np);

        Node *nw = new Node();
        nw->c = np->c;
        nw->f = np->f;
        mp[nw->c] = nw;
      }

      Node *root = NULL;

      while(!mh.empty())
      {
        int f = 0;
        string s1 = mh.top().c;
        f += mh.top().f;
        mh.pop();
        string s2 = mh.top().c;
        f += mh.top().f;
        mh.pop();

        node *np = new node();
        np->f = f;
        np->c = s1 + s2;

        Node *nw = new Node();
        nw->c = np->c;
        nw->f = np->f;

        if(mp[s1]) nw->left = mp[s1];
        if(mp[s2]) nw->right = mp[s2];
        mp[nw->c] = nw;
        root = nw;
        mh.push(*np);
      }

      pnode(root, "");

    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
