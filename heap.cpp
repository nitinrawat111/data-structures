#include <iostream>
#include <math.h>

#define HEAP_CAPACITY 20
typedef int HEAP_SIZE_TYPE;
typedef int HEAP_TYPE;

using namespace std;

class heap
{
    HEAP_TYPE array[HEAP_CAPACITY];
    HEAP_SIZE_TYPE heap_size{0};

    HEAP_SIZE_TYPE parent(HEAP_SIZE_TYPE i)
    {
        return (i-1) >> 1;
    }

    HEAP_SIZE_TYPE left(HEAP_SIZE_TYPE i)
    {
        return (i << 1) + 1;
    }

    HEAP_SIZE_TYPE right(HEAP_SIZE_TYPE i)
    {
        return (i << 1) + 2;
    }

public:
    void max_heapify(HEAP_SIZE_TYPE i)
    {
        HEAP_SIZE_TYPE largest_index = i;
        if(left(i) < heap_size && array[left(i)] > array[largest_index])
        {
            largest_index = left(i);
        }
        if(right(i) < heap_size && array[right(i)] > array[largest_index])
        {
            largest_index = right(i);
        }

        HEAP_TYPE temp;
        while(array[i] < array[largest_index])
        {
            temp = array[i];
            array[i] = array[largest_index];
            array[largest_index] = temp;
            i = largest_index;

            if(left(i) < heap_size && array[left(i)] > array[largest_index])
            {
                largest_index = left(i);
            }
            if(right(i) < heap_size && array[right(i)] > array[largest_index])
            {
                largest_index = right(i);
            }
        }
    }

    void build_max_heap(HEAP_TYPE *a, HEAP_SIZE_TYPE n)
    {
        if(n > HEAP_CAPACITY)
        {
            cout<<"Overflow! Heap unchanged!";
            return;
        }

        for(int i = 0; i < n; i++)
        {
            array[i] = a[i];
        }
        heap_size = n;

        for(int i = heap_size/2; i > -1; i--)
        {
            max_heapify(i);
        }
    }

    void print()
    {
        for(int i = 0; i < heap_size; i++)
        {
            cout<<array[i]<<' ';
        }
    }



};

int main()
{
    int a[] = {-50,5,6,2,4,66,8,3,1,0};   
    heap h;
    h.build_max_heap(a, 10);
    h.print();
    return 0;
}