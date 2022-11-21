#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

// TIME COMPLEXITY CHART
// TOP = BEST, BOTTOM = WORST
// 1. O(1)
// 2. O(log n)
// 3. O(n)
// 4. O(n log n)
// 5. O(n^2)
// 6. O(2^n)        
// 7. O(n!)


// TIME COMPLEXITY
void square(int n);
void bubbleSort(int A[], int size);
void cube(int n);

void logRecursive(int n);
void logIterative(int n);
int binarySearchRecursive(int A[], int start, int finalIndex, int target);
int binarySearchIterative(int A[], int start, int finalIndex, int target);

void nLogn(int n);
void mergeSort(int A[], int size);
void mergeSortRecursion(int A[], int left, int right);
void mergeSortedArrays(int A[], int left, int mid, int right);

int fib(int n);
void factorial(int n);

// SPACE COMPLEXITY
int countDown(int n);

// COMMON MISTAKES
void twoLoops(int n);
void twoInputsAdd(int a, int b);
void twoInputsMult(int a, int b);

int main(){
    
    // int arr[] = {6, 1, 4, 9};
    // int length = sizeof(arr)/sizeof(arr[0]);
    // mergeSort(arr, length);

    // for(int i=0; i<length; i++){
    //     printf("%d, ", arr[i]);
    // }

    factorial(3);
    
    return 0;
}

void square(int n){ // Big O(n^2) time complexity, square of n
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d, %d\n", i, j); // eg, n = 4 means printf runs 4^2 times, = 16 times
        }
    }
}

void bubbleSort(int A[], int size){ // Bubble sort is O(n^2) for every i until i=size, j must iterate until j=size.
    int temp;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(A[i]<A[j]){
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }

    // FOR MAIN
    // int A[] = {55, 23, 88, 65, 109, 204, 100, 289, 4, 9, 27, 38, 44};
    // int size = sizeof(A)/sizeof(A[0]);
    // BubbleSort(A, size);
    // for(int i=0; i<size; i++){
    //     printf("%d, ", A[i]);
    // }
}

void cube(int n){ // Big O(n^3) time complexity, cube of n
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                printf("%d, %d, %d\n", i, j, k); // eg, n = 4 means printf runs 4^3 times, = 64 times
            }
        }
    }
}

void logRecursive(int n){ // Big O(log n) time complexity, recursive means function calls itself repeatedly
    if(n==0){printf("Done"); return;}
    n = floor(n/2); // base 2
    logRecursive(n); // Runs recursively until n = 0, using base 2, log 2^something = 8, find "something"
                // Will run 3 times because 2^3 = 8
}

void logIterative(int n){ // !(IF N=8)! -> O(log2^8) = 2^? = 8.   2^3 = 8, therefore 3 iterations ran and O(log 8) time complexity
    int count = 0;
    while(n > 1){ // Need to iterate through the while loop log(n) times before we reach 1
        n = floor(n/2);
        count++;
    }
    printf("%d\n", count);
}

int binarySearchRecursive(int A[], int start, int end, int target){ // Binary Search is O(log n)
    int mid = floor((start + end)/2); // find mid point, use floor to remove decimal values (cant have index 5.5)
    if(start>end){return -1;} // If start of array is bigger than end, then the target is not in the array
    if(A[mid]==target){return mid;}
    if(A[mid]>target){return binarySearchRecursive(A, start, mid-1, target);} // If element at mid >(greater than) target, pass through mid-1 as end, to remove that mid element and anything larger than it
    if(A[mid]<target){return binarySearchRecursive(A, mid+1, end, target);} // If element at mid <(smaller than) target, pass mid+1 as start, to remove that mid element and anything smaller than it
    return -1;
}

int binarySearchIterative(int A[], int start, int end, int target){ // Binary Search is O(log n)
    int mid;
    int count = 1;  // Count unnecessary, just shows amount of times the loop runs.
    while(start<=end){
        cout << count << endl; // n = 1024 (size of array), 2^x = 1024, x = 10. The loop will run 10 times every time to find the target (instead of searching through all 1024(n) elements( O(n) )if target is 1024)
        mid = floor((start + end)/2);
        if(A[mid]==target){return mid;}
        if(A[mid]>target){end = mid-1;}
        if(A[mid]<target){start = mid+1;}
        count++;
    }
    return -1;

    // FOR MAIN
    // int A[1024];
    // for(int i=0; i<1024; i++){
    //     A[i] = i;
    // }
    // int size = sizeof(A)/sizeof(A[0]);
    // int index = binarySearchRecursive(A, 0, size-1, 1023);
    // printf("\n%d\n", index);
}

void nLogn(int n){ // O(n log n) time complexity, for each iteration of the top level while loop ( O(log n) ) there is a for loop that iterates through all of n ( O(n) ).
    int y = n;     // also means O(n * log n) for every log n iteration, there is a full n iteration. In this case O(4*2), 2 iterations of the while loop, 4 iterations of for loop per while loop.
    while(n>1){ // O(log n) 
        n = floor(n/2);//^^
        for(int i=0; i<y; i++){ // O(n)
            printf("%d\n", i);
        }
    }
}

void mergeSort(int A[], int length){
    mergeSortRecursion(A, 0, length-1);
}

void mergeSortRecursion(int A[], int left, int right){ // O(n log n) because for example, length of array (n) = 4, then log base2 4 = 2, meaning we have to go 2 levels deep in recursion
    if(left<right){                                    // and for each level, we have to traverse 4 elements in the array, therefore 4 * log base2 4, or 4*2.
        int mid = left + (right-left) / 2;

        mergeSortRecursion(A, left, mid);
        mergeSortRecursion(A, mid+1, right);

        mergeSortedArrays(A, left, mid, right);
    }
}

void mergeSortedArrays(int A[], int left, int mid, int right){
    int leftLength = mid-left+1; // Get length of left array
    int rightLength = right-mid; // Get length of right array

    int tempLeft[leftLength]; // Initialise array of size of left array
    int tempRight[rightLength]; // Initialise array of size of right array

    int i,j,k;

    for(int i=0;i<leftLength;i++){
        tempLeft[i] = A[left+i]; // Put all elements from A that are on the left side into tempLeft
    }

    for(int i=0;i<rightLength;i++){
        tempRight[i] = A[mid+1+i]; // Put all elements from A that are on the right side into tempRight
    }

    for(i=0, j=0, k=left; k<=right; k++){
        if(i<leftLength && (j>=rightLength || tempLeft[i] <= tempRight[j])){ // i tracks tempLeft array, j tracks tempRight array, k tracks A array.
            A[k] = tempLeft[i];                                              // If tempLeft[i] is less than leftLength, AND tempRight[j]>rightLength OR tempLeft[i] <= tempRight[j]
            i++;                                                             // Then add tempLeft[i] to A[k], i must be less than leftLength because otherwise no elements left, AND if
        }else{                                                               // tempRight[j] is greater than rightLength then all elements from right array are added, since both arrays are ordered
            A[k] = tempRight[j];                                             // A[k] = tempLeft[i]; i++; without needing to check if theyre sorted again
            j++;                                                             // ELSE: if above conditions are not filled, then either leftArray has reached its maximum index or tempRight[j]
        }                                                                    // is less than tempLeft[i], therefore tempRight[j] should be next in the A array to order it.
    }
}

int fib(int n){ // O(2^n) in actuality, it is O(2^n-1), but in O we ignore constants, therefore being O(2^n)
    if(n==0){return 0;}
    if(n==1){return 1;}
    return fib(n-1) + fib(n-2); // if not 0 or 1, every fib call will call itself twice, resulting in exponential calling of fib (each call then calls itself twice, those calls call itself twice etc)
            // left side is n-1, while right side is n-2. This means the left tree will be longer than the right tree.
            // In O notation, this doesnt matter as you look for worst case scenario or upper bound instead of how many times it actually calls.
            // if both were n-1, then each side of the tree would perform the same amount of calls.

            // If you type 4 in, this loop will go 3 layers deep, each layer representing 2^x;ie; 2^1, 2^2, 2^3.
}

void factorial(int n){ // O(n!) 
    if(n == 0){
        printf("*****\n"); // For each call to recursive function, if n=0 it will print this. meaning all calls in the last layer will print.
        return; // Return will end the loop
    }
    
    for(int i=0;i<n;i++){ // if starting n = 3, this will mean the function will call factorial 3 times for every n (3 = 0, 1, 2). All of those calls will then perform more calls.
        factorial(n-1);   // -1 means it will eventually finish, but once 3 turns to 2, this for loop will call factorial() twice with n=2, then n(2)-1 = 1,  
    }                     // so factorial will be called again using 1, this will call factorial again once more, for loop can only execute once.
                          
                          // 5! means 1*2*3*4*5, 3! means 1*2*3 etc etc.
                          // if n=3, 3! = 6. printf() statement will execute 6 times.
}

// SPACE COMPLEXITY
int countDown(int n){ // O(n) space complexity
    if(n==0){
        return;
    }
    return countDown(n-1); // For every n, n calls of this function are on the call stack
}

// COMMON MISTAKES
void twoLoops(int n){
    for(int i=0;i<n;i++){
        printf("Cheese\n");
    }                           // These 2 for loops are not nested and is not O(n^2) because one loop does not iterate fully per 1 iteration of the other loop
                                // Both loops are O(n), meaning time complexity is O(2n), but 2 is a constant and we drop constants,
    for(int i=0;i<n;i++){       // therefore time complexity is O(n)
        printf("burger\n");
    } 
}

void twoInputsAdd(int a, int b){
    for(int i=0;i<a;i++){
                            // Might look like O(2n), but this wrong as they are seperate inputs
    }                       // Each input has to be tracked seperately, therefore this is
                            // O(a+b) time complexity
    for(int i=0;i<b;i++){

    }
}

void twoInputsMult(int a, int b){
    for(int i=0;i<a;i++){       // Might look like O(n^2), but this is wrong because seperate inputs.
        for(int i=0;i<b;i++){   // O(n^2) really means O(n*n).
                                // For every element in a, we need to loop through every element in b.
        }                       // This is the same as saying a*b.
    }                           // Therefore, time complexity is O(a*b).
}