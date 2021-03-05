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

struct Node{
  int l = 0, h = 0;
  Node *pre = NULL, *suc = NULL;
  Node *left = NULL, *right = NULL;
};

Node* insert(Node *root = NULL,  int l = 0, int h = 0, Node *pre = NULL, Node *suc = NULL)
{
  if(!root)
  {
    Node *nw = new Node();
    nw->l = l;
    nw->h = h;
    nw->pre = pre;
    nw->suc = suc;
    return nw;
  }

  if(root->l > l)
  {
    suc = root;
    root->left = insert(root->left, l, h, pre, suc);
  }

  else
  {
    pre = root;
    root->right = insert(root->right, l, h, pre, suc);
  }

  return root;
}

Node* remove(Node *root = NULL,  int l = 0, int h = 0)
{
  if(!root) return NULL;

  if(root->l > l)
  {
    root->left = remove(root->left, l, h);
  }

  else if(root->l < l)
  {
    root->right = remove(root->right, l, h);
  }

  else
  {
    if(root->left == NULL)
    {
      Node *tmp = root->right;
      free(root);
      return tmp;
    }

    if(root->right == NULL)
    {
      Node *tmp = root->left;
      free(root);
      return tmp;
    }

    Node *tmp = root->suc;
    root->l = tmp->l;
    root->h = tmp->h;
    root->pre = tmp->pre;
    root->suc = tmp->suc;
    root->right = remove(root->right, tmp->l, tmp->h);
  }

  return root;
}

Node* search(Node *root = NULL, int l = 0, int h = 0)
{
  return root;
}

void inorder(Node *root = NULL)
{
  if(!root) return;
  inorder(root->left);
  cout << root->l << " " << root->h << "\n";
  inorder(root->right);
}

void preorder(Node *root = NULL)
{
  if(!root) return;
  cout << root->l << " " << root->h << "\n";
  preorder(root->left);
  preorder(root->right);
} 

//Interval Tree


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
      ll n = 0;
      cin >> n;

      Node *root = NULL;
      for(int i = 0; i < n; i++)
      {
        cin >> j >> k;
        root = insert(root, j, k);
      }

      inorder(root);
      cout << "\n";
      remove(root, 30, 40);
      inorder(root);
      cout << "\n";
      
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
