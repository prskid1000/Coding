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
  int freq[26] = {0};
  node *n[26] = {nullptr};
};


void insert(node *root, string s)
{
  if(root == nullptr)
  {
    root = new node();
  }

  for(int i = 0; i < s.length(); i++)
  {
    int k = s[i] - 'a';
    root->freq[k]++;

    if(root->n[k] == nullptr)
    root->n[k] = new node();

    root = root->n[k];
  }
}

void remove(node *root, string s)
{
  for(int i = 0; i < s.length(); i++)
  {
    int k = s[i] - 'a';
    root->freq[k]--;

    node *tmp = root->n[k];
    root = root->n[k];

    if(tmp->freq[k] == 0) free(tmp->n[k]);
  }
}

string prefix(node *root, string s)
{
  string ans = "";
  for(int i = 0; i < s.length(); i++)
  {
    int k = s[i] - 'a';
    ans += s[i];

    if(root->freq[k] == 1)break;

    root = root->n[k];
  }

  return ans;
}

void display(node *root)
{
  if(root == nullptr) return;

  for(int i = 0; i < 26; i++) cout << root->freq[i] << " ";
  cout << "\n";

  for(int i = 0; i < 26; i++) display(root->n[i]);
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
      string s[n];

      node *root = new node();

      for(int i = 0; i < n; i++)
      {
        cin >> s[i];
        insert(root, s[i]);
      }

      //display(root);

      for(int i = 0; i < n; i++)
      {
        cout << prefix(root, s[i]) << "\n";
      }

    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
