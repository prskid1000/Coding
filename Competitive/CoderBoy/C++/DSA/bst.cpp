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
  int data;
  Node *left = NULL, *right = NULL;
};

Node* search(Node* root, int val)
{
  if(root == NULL || root->data == val)
       return root;
    
  if (root->data < val)
       return search(root->right, val);
 
  return search(root->left, val);
}

Node* insert(Node *root, int val)
{
  if(!root)
  {
    Node *nw = new Node();
    nw->data = val;
    return nw;
  }
  else if(val < root->data)
  {
    root->left = insert(root->left, val);
  }
  else
  {
    root->right = insert(root->right, val);
  }
  return root;
}

Node* minValueNode(Node* node)
{
  Node* current = node;

  while (current && current->left != NULL)
        current = current->left;
 
  return current;
}

Node* remove(Node *root, int val)
{
  if(!root) return NULL;
  if(val < root->data)
  {
    root->left = remove(root->left, val);
  }
  else
  {
    root->right = remove(root->right, val);
  }

  if(val == root->data)
  {
    if(root->left == NULL && root->right == NULL)
    {
      free(root);
      return NULL;
    }

    else if(root->left == NULL)
    {
      Node *t = root->right;
      free(root);
      return t;
    }

    else if(root->right == NULL)
    {
      Node *t = root->left;
      free(root);
      return t;
    }

    Node* t = minValueNode(root->right);
    root->data = t->data;
    root->right = remove(root->right, t->data);
  }

  return root;
}

void inorder(Node *root)
{
  if(root == NULL) return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
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
      ll n = 0;
      cin >> n;
      Node *root = NULL;
      for(int i = 0; i < n; i++)
      {
        cin >> k;
        root = insert(root, k);
      }
      inorder(root);
      cout << "\n";
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
