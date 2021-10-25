/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author godavarthy
 */
public class QuickSort {
    static int partition(int A[], int p, int r) 
    { 
        int x = A[r];  
        int i = (p-1); // index of smaller element 
        for (int j=p; j<r; j++) 
        { 
            // If current element is smaller than the pivot 
            if (A[j] < x) 
            { 
                i++; 
  
                // swap arr[i] and arr[j] 
                int temp = A[i]; 
                A[i] = A[j]; 
                A[j] = temp; 
            } 
        } 
  
        // swap arr[i+1] and arr[high] (or pivot) 
        int temp = A[i+1]; 
        A[i+1] = A[r]; 
        A[r] = temp; 
  
        return i+1; 
    } 

    static void quicksort(int arr[], int low, int high) 
    { 
        if (low < high) 
        { 
            
            int  q = partition(arr, low, high); 
            quicksort(arr, low, q-1); 
            quicksort(arr, q+1, high); 
        } 
    } 
  
    /* A utility function to print array of size n */
    static void display(int arr[]) 
    { 
        int n = arr.length; 
        for (int i=0; i<n; ++i) 
            System.out.print(arr[i]+" "); 
        System.out.println(); 
    } 
  
    public static void main(String args[]) 
    { 
        int arr[] = {10, 7, 8, 9, 1, 5}; 
        int n = arr.length; 
        System.out.println("Original Array: ");
        display(arr);
        quicksort(arr, 0, n-1); 
  
        System.out.println("Sorted Array: "); 
        display(arr); 
    } 
}
