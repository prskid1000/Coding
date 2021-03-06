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
  char data = 0;
  node *prev = NULL, *next = NULL; 
};

node* push(node *head, char k)
{
  while(head->next != NULL)
      head = head->next;
      head->next = new node();
      head->next->data = k;
      head->next->prev = head;
      return head->next;
}

void pop(node *head, node *target)
{
  if(target->next == NULL)
    {
      target->prev->next = NULL;
    }
    target->prev->next  = target->next;
    target->next->prev = target->prev;
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

      vector<pair<int, node*>> v(26,{0, NULL});
      node *root = new node();

      for(int i = 0; i < n; i++)
      {
        char c;
        cin >> c;
        if(v[c - 'a'].first == 0)
        {
          v[c - 'a'].first++;
          v[c - 'a'].second = push(root, c);
        }
        else
        {
          pop(root, v[c - 'a'].second);
          v[c - 'a'].second = NULL;
        } 
        cout << root->next->data << "\n";
     }  
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
