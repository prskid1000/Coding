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
  int data;
  node *prev, *next; 
};

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

      node *end = curr;

      curr = start;
      while(curr != NULL)
      {
        cout << curr->data << " ";
        curr = curr->next;
      }
      cout << "\n";

      curr = end;
      while(curr != NULL)
      {
        cout << curr->data << " ";
        curr = curr->prev;
      }
      cout << "\n";

      cin >> k;
      int count = 0;

      curr = start;
      while(count != k)
      {
        count++;
        node *temp = curr->next;
        curr->next = NULL;
        curr->prev = end;
        end->next = curr;
        end = end->next;
        curr = temp;
      }

      start = curr;
      start->prev = NULL;

      curr = end;
      while(curr != NULL)
      {
        cout << curr->data << " ";
        curr = curr->prev;
      }
      cout << "\n";
      
    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
