/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>

int main()
{
    int arr[100], ind, i, num, arrTemp[50], j=0, chk=0;
    printf("Enter the Size for Array Size: ");
    scanf("%d", &ind);
    printf("Enter %d Array Elements: ", ind);
    
    for(i=0; i<ind;i++)
        scanf("%d", &arr[i]);

    printf("\nEnter the Number to Search: ");
    scanf("%d", &num);

    for(i=0; i<ind;i++)
    {
        if(arr[i] == num)
        {
            arrTemp[j] = i;
            j++;
            chk++;
        }
    }

    if(chk > 0)
    {
        printf("\nNumber Found at Index No. ");
        ind=chk;
        for(i=0; i<ind;i++)
            printf("%d ", arrTemp[i]);
    }
    else
        printf("\nNumber not found!");

    printf("\n");
    return 0;
}
