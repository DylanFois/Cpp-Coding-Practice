#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

void pointerTut1();
void pointerTut2();

void pointerToPointer();
void incorrectIncrement(int a);
void correctIncrement(int *p);

void pointerArray();
int SumOfElements(int A[], int size);
void DoubleElements(int* A, int size);
void print(char* C);

void TwoDimensionalArrayPointer();
void ThreeDimensionalArrayPointer();

void cMemAllocation1();
void cMemAllocation2();
void cppMemAllocation();

int add(int a, int b);
int compare(const void* a, const void* b);

int main(){

    int i;
    int A[] = {5,18,99,43,24,37};
    int n = sizeof(A)/sizeof(A[0]);
    qsort(A, n, sizeof(int), compare);
    for(i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    return 0;
}

void pointerTut1(){
    int a = 56;
    int *p = &a;
    cout << "int a: " << a << endl;
    cout << "mem address a: " << &a << endl;
    cout << "p: " << p << endl;
    cout << "mem address p: " << &p << endl;
    cout << "value of pointer p: " << *p << endl;
    *p = 60;
    cout << "value of modified a: " << a << endl;

    p+=1; // increment pointer address
    cout << "memory address of p: " << p << endl;
    cout << "value of new p: " << *p << endl;
}

void pointerTut2(){
    int a = 5345;
    int *p = &a;

    printf("Address = %d, value = %d\n", p, *p); // p shows memory address of a, *p shows value of pointer p, which is value of a
    printf("Address = %d, value = %d\n\n", p+1, *(p+1)); // p+1 increments memory address by 4 bytes (int), *(p+1) increments value of pointer p

    char *p0; 
    p0 = (char*)p;
    printf("Address = %d, value = %d\n", p0, *p0);
    printf("Address = %d, value = %d\n", p0+1, *(p0+1));

}

void pointerToPointer(){
int a = 10;
int *p = &a;
int **q = &p;

printf("int a: %d\n *p addr: %d\n **q addr: %d\n *p val: %d\n **q val: %d\n", a, p, q, *p, **q);
}

void incorrectIncrement(int a){
    a = a+1; // Incrementing function scoped a, not global a
}

void correctIncrement(int *p){
    *p = *p+1; // Incrementing value of pointer p, which points to a, therefore incrementing global a
}

void pointerArray(){
    int A[5] = {2,4,5,8,1};
    printf(" A: %d\n *A: %d\n index 1 A[1] value: %d\n index 1 *(A+1): %d\n", A, *A, A[1], *(A+1));
}

int SumOfElements(int A[], int size){ // Passing array to function passes pointer to A, not the array itself
    int sum = 0;                      // Size needs to be calculated before and passed, else size is sizeof pointer
    
    for(int i=0;i<size;i++){
        sum += A[i];
    }
    return sum;
}

void DoubleElements(int* A, int size){
    for(int i = 0; i<size; i++){
        A[i] = 2*A[i]; // Doubles elements of global A, because pointer A points to memory address of global A
    }
}

void print(char* C){ // Character arrays have null at final index
    while(*C != '\0'){ // Continue printing character array until a null character is encountered
        printf("%c", *C);
        C++; // Increment memory address to next index
    }
    printf("\n");
}

void TwoDimensionalArrayPointer(){
    int B[2][3]; // Array of 2 arrays, each containing 3 integers
    B[0][0] = 2;
    B[0][1] = 3;
    B[0][2] = 6;
    B[1][0] = 4;
    B[1][1] = 5;
    B[1][2] = 8;
    int (*p)[3] = B; // Assign pointer to 1-dimensional array of 3 integers

    printf("B: %d\n", B);
    printf("B+1: %d\n", B+1); // Will move to the next array of 3 ints, not next int in 1st array (4bytes * 3 = 12)
    printf("*(B+1): %d, value: %d\n", *(B+1), *(*(B+1))); // B+1 moves to 2nd array, value of that is the memory address for the first integer in 2nd array
    printf("*(B+1)+2: %d, value: %d\n", *(B+1)+2, *(*(B+1)+2)); // B points to each of the first arrays, +1 moves to 2nd array, value of points to first index of 2nd array. +2 moves to final int of 2nd array, prints address of that int
    printf("*(*B+1): %d\n", *(*B+1)); // Value of B points to first integer mem address in first array, +1 moves to 2nd int in first array. Value of prints 3.
}  

void ThreeDimensionalArrayPointer(){
    int C[3][2][2];
    C[0][0][0] = 2;
    C[0][0][1] = 5;
    C[0][1][0] = 7;
    C[0][1][1] = 9;
    C[1][0][0] = 3;
    C[1][0][1] = 4;
    C[1][1][0] = 6;
    C[1][1][1] = 1;
    C[2][0][0] = 0;
    C[2][0][1] = 8;
    C[2][1][0] = 11;
    C[2][1][1] = 13;

    int (*p)[2][2] = C; // Pointer to 2 dimensional array of 2 integers

    printf("C: %d\n", C); // Pointing to C[0]
    printf("*C: %d\n", *C); // Pointing to C[0][0]
    printf("**C: %d\n", **C); // Pointing to C[0][0][0]
    printf("***C: %d\n", ***C); // Value of C[0][0][0]

    // function(int (*A)[2][2]) to pass 3D array into function. 1st element can be undefined but the rest must be defined.
}

void cMemAllocation1(){
    int a; // Goes on stack memory
    int *p; // Also on stack because local variable to main()
            // Using malloc, can allocate memory to the heap.
            // Returns void pointer to memory address on the heap.
    
    p = (int*)malloc(sizeof(int)); //typecasting void pointer to int pointer, allocating memory for the size of an int (4 bytes)
    *p = 10; // Value of memory address p = 10. Assigned int 10 to heap memory.
    
    free(p); // need to use this command to free the memory if no longer needed.

    p = (int*)malloc(sizeof(int)); // Allocates another 4 byte block of memory on the heap for an int. Note that previous value was never freed (if line 149 commented out)
                                   // Memory still allocated even though the pointer no longer points to the previous int of 10
    
    *p = 20; // New memory block is allocated value of 20, old memory address still assigned 10 but no longer has a pointer to it.
    free(p);

    p = (int*)malloc(20*sizeof(int)); // Allocating an array of 20 integers on the heap by multiplying the size of an int (4 bytes) by the number of elements needed (20)
    // Pointer still only takes up 4 bytes of memory on main(), addresses 20*4 bytes on heap memory.

    p[12] = 50; // Assigning value of 50 to 12 element of heap array
    printf("p[12]: %d\n", p[12]);
    free(p);

    p = (int*)calloc(5,sizeof(int)); // takes 2 arguments, number of elements and size of data type
                                          // malloc does not initialise values (ie contains garbage values)
                                          // calloc initialises all values to 0
    free(p);

    // realloc takes 2 arguments, void pointer and new size of memory block. copies old values into new memory block
}

void cMemAllocation2(){
    int n;
    int g;
    bool b;
    printf("Enter size of array\n");
    scanf("%d", &n);

    printf("Initialise values? 1=true, 0=false\n");
    scanf("%d", &g);

    int *A = (int*)malloc(n*sizeof(int)); // n = num of elements, times size of data type for array (int)
    int *B = (int*)calloc(n, sizeof(int));

    if(g == 1){
        b = true;
    }else{
        b = false;
    }

    if(b){
        for(int i=0;i<n;i++){ // If not initialised, each value would be a garbage value for malloc array (A[])
            A[i] = i+1;
            B[i] = i+1;
        }
    }
    printf("Array values malloc\n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    printf("\nArray values calloc\n");
    for(int i=0;i<n;i++){
        printf("%d ",B[i]);
    }
}

void cppMemAllocation(){
    int a; // Goes on stack
    int *p; // Also on stack

    p = new int; // No typecasting needed, returns type pointer instead of null pointer
    *p = 10;
    delete p;

    p = new int[20];
    delete[] p;
}

int add(int a, int b){
    int c = a+b;
    return c;

    // FOR MAIN
    // int (*p)(int,int); // declaring integer function pointer (if function was void, would need to be void)
    // p = add; // Storing add function memory address into p
    // int c = p(2,5); // Passing parameters into add function
    // cout << c << endl;
}

int compare(const void* a, const void* b){ // Quicksort calls compare with 2 constant void pointers, const means it cannot be changed, and void* means its a generic pointer to any datatype.
    int A = *((int*)a); // Must be converted to integer pointer (because our array is an int array) and use * to get the value from the pointer
    int B = *((int*)b); // ^^
    return A-B; // Return logic, A is the bigger number and B is the smaller number. For A-B, it will be greater than 0 and will sort from lowest to highest.
                // If changed to B-A, then it will be negative and order from highest to lowest

    // FOR MAIN
    // int i;
    // int A[] = {5,18,99,43,24,37};
    // int n = sizeof(A)/sizeof(A[0]);
    // qsort(A, n, sizeof(int), compare); Using quicksort, can pass array, num of elements, sizeof data type, and your comparison logic function for callback
    // for(i=0;i<n;i++){
    //     printf("%d ", A[i]);
    // }
}