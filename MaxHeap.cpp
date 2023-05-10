#include <iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;     //alocating an index to the value
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else 
            {
                return;
            }
        }
    }
    void print(){
        for(int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }

    void deleteheap()
    {
        if(size == 0)
        {
            cout<<"nothing to delete";
        }
         
        arr[1] = arr[size];
        size = size - 1;

        int i = 1;
        while(i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            if(leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if(rightindex < 1 && arr[i] < rightindex)
            {
                swap(arr[i], arr[rightindex]);
            }
            else 
            {
                return;
            }
        }
    }
};


int main(){
    heap h;
    h.insert(50);
    h.insert(25);
    h.insert(53);
    h.insert(22);
    h.insert(39);
    cout<<"after inserting elements :";
    cout<<"\nmax heap :";
    h.print();
    cout << "after deletion" << endl;
    h.deleteheap();
    h.print();

}
