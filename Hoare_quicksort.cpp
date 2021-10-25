//C++ code for quicksort algorithm using Hoare partion for a set of 4 arrays
#include<iostream>
using namespace std;
int cost = 0; //counter for time complexity
//function for exchanging two integers 
void swap(int* a, int* b)
{
   int t = *a;
   *a = *b;
   *b = t;
}
//function for partitioning the array taking random element as pivot element
int hoare_partition(int A[], int p, int r)
{
int x = A[p];
int i = p - 1;
int j = r + 1;
while(true)
 {
     cost++;
   do{
       j--;
   }while(A[j] > x);

   do{
       i++;
   }while(A[i] < x);
   
   if(i < j)
   swap(&A[i],&A[j]);
        
    else return j;
 }
}
//function for implementing quick sort
void quickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = hoare_partition(A,p,r);
        quickSort(A,p,q);
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

     //Sorting array using Hoare quick sort algorithm: sorts in descending order
     quickSort(arr, 0, num-1);
     cout<< "\nSorted array using quick sort in descending order \n";
     display(arr,num);
     cout<< "\nActual cost: " << cost << endl;
     cost = 0;

     //Again sorting array for worst case : sorts in descending order
     quickSort(arr, 0, num-1);
     cout<< "\nSorting the sorted array in descending order \n"; 
     display(arr,num);
     cout<<"\nWorst case: "<< cost << endl;
     int tc = num * int(log2 (num));
     cout<< "\nTheoretical cost: " << tc << endl;
     num = num + 10;
     array++;
     cost = 0;
     cout << endl;
    }
}
