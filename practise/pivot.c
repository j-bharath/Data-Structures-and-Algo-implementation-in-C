# include <stdio.h>



/* FOLLOWING FUNCTIONS ARE ONLY FOR SORTING

PURPOSE */

void exchange(int *a, int *b)

{

int temp;

temp = *a;

*a   = *b;

*b   = temp;

}



int compare(int x, int y, int i, int j)

{

if ( (x < y) || (x == y && i < j) )

return 1;

else

return 0;

}



int partition(int A[], int si, int ei)

{

int x = A[ei];

int i = (si - 1);

int j;



for (j = si; j <= ei - 1; j++)

{

if(compare(A[j], x, j, ei) == 1)

{

i++;

exchange(&A, &A[j]);

}

}

exchange (&A, &A[ei]);

return (i + 1);

}



/* Implementation of Quick Sort

A[] --> Array to be sorted

si  --> Starting index

ei  --> Ending index

*/

void quickSort(int A[], int si, int ei)

{

int pi;    /* Partitioning index */

if(si < ei)

{

pi = partition(A, si, ei);

quickSort(A, si, pi - 1);

quickSort(A, pi + 1, ei);

}

}



/* Driver program to test above function */

int main()

{

int A[] = {1, 4, 45, 6, 10, -8}, i;

int arr_size = sizeof(A)/sizeof(A[0]);



quickSort(A, 0, arr_size-1);



for ( i = 0; i < arr_size; i++ )

printf("%d ", A);

getchar();

return 0;

}
