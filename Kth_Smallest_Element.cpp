#include<iostream>
#include<climits>
using namespace std;

class MaxHeap{
   int heapSize, capacity;
   int* heap;
   
   void swap(int *a, int *b)
   {
       int c = *a;
       *a = *b;
       *b = c;
   }
   void heapify(int i)
   {
       while(i<heapSize)
       {
           int greater=i;
           if(2*i+1<heapSize && heap[i] < heap[2*i+1])
             greater = 2*i+1;

           if(2*i + 2 < heapSize && heap[greater] < heap[2*i+2])
             greater = 2*i+2;

           if(greater != i)
             {
                 swap(&heap[i],&heap[greater]);
                 i=greater;
             }
           else
           {
               break;
           }
       }
   }
   
   public :
   
   MaxHeap(int capacity)
   {
       this->capacity = capacity;
       heapSize = 0;
       heap = new int[capacity];
   }

   // parent (i-1)/2, left (2*i + 1), right (2*i +2)

   void push(int element)
   {
       
       if(heapSize==capacity)
        { cout<<"Heap Overflow!"<<endl;
         return;}

      heapSize++;
      heap[heapSize-1]=element;
      
      int i = heapSize-1;  // parent

      while(i && heap[i] > heap[(i-1)/2]) // maxHeapify
      {
         swap(&heap[i], &heap[(i-1)/2]);
         i = (i-1)/2;
      }
   }
   
   bool empty()
   {
       return (heapSize==0);
   }

   int top()
   {
      if(!empty())
       {
           //cout<<heapSize<<"----  ";
           return heap[0];
      }
      return INT_MAX;
   }

   void pop()
   {
       if(!empty())
       {
           heap[0]= heap[heapSize-1];
           //cout<<heapSize<<"  "<<heap[0]<<"\n";
           heapSize--;
           heapify(0);
       }
   }

  
   void show()
   {
      for(int i =0; i<heapSize; i++)
         cout<<heap[i]<<" ";

       cout<<"\n";
   }
 
};

int main()
{
    /*
    7 3
    -1 23 12 -2 30 7 50
    */
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];

    MaxHeap pq(k);

    for(int i=0; i<k; i++)
      pq.push(arr[i]);

    for(int i=k; i<n; i++)
    {
        if(arr[i]<=pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    cout<<pq.top();
}
