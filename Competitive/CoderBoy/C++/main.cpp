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

int heap[100] = {0};
int size = 0;

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void min_heapify(int p)
{
  int smallest = p;

  if(heap[p] > heap[2 * p + 1])
  smallest = 2 * p + 1;

  if(heap[p] > heap[2 * p + 2])
  smallest = 2 * p + 2;

  if(smallest != p)
  {
    swap(&heap[p], &heap[smallest]);
    min_heapify(smallest);
  }
}

int extractMin()
{
    if(size <= 0) return INT_MAX;
    if(size == 1)
    {
      size--;
      return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[size-1];
    size--;
    min_heapify(0);

    return root;
}

void decreaseKey(int i, int v)
{
    heap[i] = v;
    while(i != 0 && heap[(i - 1) / 2] > heap[i])
    {
       swap(&heap[i], &heap[(i - 1) / 2]);
       i = (i - 1) / 2;
    }
}

void deleteKey(int p)
{
  decreaseKey(p, INT_MIN);
  extractMin();
}

void insertKey(int k)
{
    decreaseKey(size++, k);
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

      for( i = 0; i < n; i++)
      {
        cin >> k;
        insertKey(k);
        //cout << size << "\n";
      }

      for( i = 0; i < 100; i++)
      {
        cout << extractMin() << "\n";

      }

    }

   #ifndef ONLINE_JUDGE
   time2
   #endif
   //fflush(stdout);
  return 0;
}
