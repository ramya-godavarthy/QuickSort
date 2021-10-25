//C++ code for Quick Sort Algorithm for a set of 4 arrays
#include<iostream>
using namespace std;
int cost = 1; //counter for time complexity

//function for exchanging two integers 
void swap(int* a, int* b)
{
   int t = *a;
   *a = *b;
   *b = t;
}

//function for partitioning the array taking last element as pivot element
int partition(int A[], int p, int r)
{
int x = A[r];
int i = (p-1);
for(int j = p; j <= r-1; j++)
{
    cost++;
   if (A[j] <= x)
   {
       cost++;
       i = i + 1;
       swap(&A[i], &A[j]);
   }
}
swap(&A[i+1], &A[r]);
return i+1;
}

//function for implementing quick sort
void quickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
        cost++;
    }
}

//function to display the array
void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//function to generate array with random numbers
int* randomArray(int* n)
{ 
    int num = *n;
    int* A = new int[num];
    for(int i = 0; i < num; i++){
        A[i] = rand() % 100 + 1;
    }
    return A;
}

// Main code
int main()
{
    int num = 15;
    int array = 1;
    srand((unsigned int)time(0));  
    while(num<50)
    {
        for(int i = 0; i < 90; i++)
            cout<<"-";
        cout<<endl;

    //generating random array
     int* arr = randomArray(&num);
     cout << "\nOriginal array: " << array << " with size " << num << endl;
     display(arr,num);

     //Sorting array using quick sort
     quickSort(arr, 0, num-1);
     cout<< "\nSorted array using quick sort: \n";
     display(arr,num);
     cout<< "\nActual cost: " << cost << endl;
     cost = 1;

     //Again sorting array for worst case
     quickSort(arr, 0, num-1);
     cout<< "\nSorting the sorted array: \n"; 
     display(arr,num);
     cout<<"\nWorst case: "<< cost << endl;
     
     //Theoretical time complexity = n * n
     cout<< "\nTheoretical cost: " << num * num << endl;
     cost = 1;
     num = num + 10;
     array++;
     cost = 1;
     cout << endl;
    }
}
