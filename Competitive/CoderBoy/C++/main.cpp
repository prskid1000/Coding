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

vector<int> heap;

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void heapify(int p)
{
  int swapper = p;

  if(2 * p + 1 < heap.size() && heap[p] > heap[2 * p + 1])
  swapper = 2 * p + 1;

  if(2 * p + 2 < heap.size() && heap[swapper] > heap[2 * p + 2])
  swapper = 2 * p + 2;

  if(swapper != p)
  {
    swap(&heap[p], &heap[swapper]);
    heapify(swapper);
  }
}

int extractMin()
{
    if(heap.size() <= 0) return INT_MAX;
    int root = heap[0];
    if(heap.size() == 1) heap.clear();

    else
    {
      heap[0] = heap[heap.size() - 1];
      heap.pop_back();
      heapify(0);
    }

    return root;
}

void insertElement(int v)
{
  heap.push_back(v);
  int i = heap.size() - 1;

  while(i != 0 && heap[(i - 1) / 2] > heap[i])
  {
     swap(&heap[i], &heap[(i - 1) / 2]);
     i = (i - 1) / 2;
  }
}

void display()
{
  for(int i = 0; i < heap.size(); i++)
  {
    cout << heap[i] << " ";
  }
  cout << "\n";
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
        insertElement(k);
        //cout << size << "\n";
      }

      for( i = 0; i < 5; i++)
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
