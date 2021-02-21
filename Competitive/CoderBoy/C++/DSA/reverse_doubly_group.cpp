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
  int data = 0;
  node *prev = NULL, *next = NULL; 
};

node* reverse(node *root, int k)
{
      node *curr = root;
      int count = 0;

      node *head = NULL, *end = NULL;
      
      while(count != k && curr != NULL)
      {
        if(head == NULL)
        {
          head = new node();
          head->data = curr->data;
          head->prev = head;
          end = head;
        }

        else
        {
          head->prev = new node();
          head->prev->data = curr->data;
          head->prev->next = head;
        }

        head = head->prev;
        curr = curr->next;
        count++;
      }

      if(curr != NULL)
      {
        end->next = reverse(curr, k);
        end->next->prev = root;
      }

      return head;
      
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

      cin >> k;
      node *start = new node();
      node *curr = start;
      curr->data = k;
      curr->prev = NULL;

      for(int i = 0; i < n - 1; i++)
      {
        cin >> k;
        curr->next = new node();
        curr->next->data = k;
        curr->next->next = NULL;
        curr->next->prev  = curr;
        curr = curr->next;
      }

      cin >> k;
      curr = reverse(start, k);

      while(curr != NULL)
      {
        cout<< curr->data << " ";
        curr = curr->next;
      }
      cout << "\n";
      
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
