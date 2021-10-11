#include<stdio.h>                    //header files
#include<stdlib.h>
int main(){                      //main function
    int t;                 //taking input the no. of test cases
    printf("Enter number of test cases: ");
    scanf("%d",&t);
    while(t--){

        int n,k,far,min,near,max;            //declaring variables
        printf("Enter number of Integers : ");          //no. of integers to be input
        scanf("%d",&n);

        int *arr=(int *)malloc(n*sizeof(int));     //dynamic allocation of arrar arr

        printf("Enter distinct Integers :  ");      //taking input array elements
        for (int j=0;j<n;j++){
            scanf("%d",(arr+j));
        }
        printf("Enter the value of K: ");         //input of integer K
        scanf("%d",&k);

        min=abs(*(arr)-(k));      //storing min value by supposing first element's diff is min
        max=abs(*(arr)-(k));      //storing max value by supposing first element's diff is max

        for (int i=0;i<n;i++){         //checking another elements to be farthest and nearest
            if((abs(*(arr+i)-k))<min){
                min=(abs(*(arr+i)-k));
            }
            if((abs(*(arr+i)-k))>max){
                max=(abs(*(arr+i)-k));
            }
        }

        printf("Farthest Element: ");     //printing farthest no.
        for (int j=0;j<n;j++){
            if((abs(*(arr+j)-k))==max){
                printf("%d ",*(arr+j));
            }
        }
        printf("\n");

        printf("Nearest Element: ");      //printing nearest no.
        for (int j=0;j<n;j++){
            if((abs(*(arr+j)-k))==min){
                printf("%d ",*(arr+j));
            }
        }

        free(arr);   //free up  the memeory of arr
        printf("\n\n");
    }
    return 0;
}
