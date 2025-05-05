#include <stdio.h>
//q2:
void changer(int *a){
    *a=10;
}


//q3:
void arr_change(int *a){
    *a=7;
    *(a+1) = 8;
}

//q4:
void insertion_sort(int *a){
    int b;
    while(*(a+1)!='\0'){
        while(*a>*(a+1)){
            b=*a;
            *a=*(a+1);
            *(a+1)=b; 
        }
        a+=1;
    }
}
//q5
void length_counter(char *cha, int *num){
    int i=0;
    while(*cha!='\0'){
        i+=1;
        cha+=1;
    }
    *num = i;
}
//q6
void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz){//runtime of O(n*m) -- n = length of arr1, m=length of arr2
    int i = 0;//checkpoint
    int false_1 = 0;//boolean
    while (i<=arr1_sz){
        if (*(arr1+i) == *(arr2)){
            int j = 0;//checkpoint
            while (j<arr2_sz){
                if (*(arr1+i+j)!=*(arr2+j)){
                    false_1=1;
                }
                j+=1;
            }
            if (false_1==0){
                int a = 0;//checkpoint
                while (a<arr2_sz){
                    *(arr1+i)=0;
                    arr1+=1;
                    a+=1;
                }
            }
        }
        false_1=0;
        i++;
    }
}

int main()
{
    int a =5;
    printf("before: %d\n", a);
    changer(&a);
    printf("after: %d\n", a);

    //q3
    int arr[100];
    arr_change(arr);

    //q4:
    int arrr[3]={3,2,4};
    //int i = 0;
    for(int i=0;i<3;i++){
        printf("%d\n", arrr[i]);
    }
    insertion_sort(arrr);
    for(int i=0;i<3;i++){
        printf("%d\n", arrr[i]);
    }
    //q5:
    
    char *s="abc";
    int length = 1;
    length_counter(s, &length);
    printf("%d\n", length);

    //q6:
    int arr1[]={1,2,3,4};
    int arr2[] = {1,2};
    seq_replace(arr1, 4, arr2, 2);
    for(int i=0;i<4;i++){
        printf("%d\n", arr1[i]);
    }


}