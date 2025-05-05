#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 //q1
int set_even_to_zero(int *block, int size){
    for (int i = 0; i < size; i++){
        if (i % 2 == 0){
            block[i] = 0; 
        }
    }
    return 0;
}
//q2
//index i
int concat_ind(char *str1, char *str2, char **result){
    int i=0;
    while(str1[i]!='\0'){
        i+=1;
    }
   
    int j = 0;
    while(str2[j]!='\0'){
        j+=1;
    }
    
    *result = (char *)malloc((i + j + 1) * sizeof(char));
    for(int k=0; k<i; k++){
        (*result)[k]=str1[k];
    }
    for(int m=0;m<j;m++){
        (*result)[i+m]=str2[m];
    }
    (*result)[i + j] = '\0';
    return 0; 

    
}
//pointer arithmetic

int concat_point(char *str1, char*str2, char**result){
    int i=0;
    while(str1[i]!='\0'){
        i+=1;
    }
   
    int j = 0;
    while(str2[j]!='\0'){
        j+=1;
    }
    
    *result = (char *)malloc((i + j + 1) * sizeof(char));
    for(int k=0; k<i; k++){
        *(*(result)+k)=str1[k];
    }
    for(int m=0;m<j;m++){
        *(*(result)+i+m)=str2[m];
    }
    *(*(result)+i+j) = '\0';
    return 0; 
}
//q3
int my_strcmp_rec(char *s1, char *s2){
    if (s1[0] == '\0' && s2[0] == '\0') {
        return 0; 
    }
    if (s1[0] != s2[0]){
            return 1;
    }else{
        char *new_s1 = &s1[1];
        char *new_s2 = &s2[1];
        my_strcmp_rec(new_s1,new_s2);  
    }
    return 0;
}
//q4 on python
//q5
int my_atoi(char* str){
    int i =0;
    int integer = 0;
    while(str[i]!='\0'){
        integer = integer*10 + str[i]- '0';
        i+=1;
    }
    return integer;
}

//main function 
int main(){
    printf("test");
    //q1
    int arr[] = {5,6,7,8};
    set_even_to_zero(arr, 4);
    printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
    return 0;

    //q2
    char str1[20]="This is ", str2[20]="concatenize";
    char *result = NULL;
    concat_ind(str1, str2, &result);
    puts(result);

    char *result2=NULL;
    concat_point(str1, str2, &result2);
    puts(result2);
    //q3
    char *s1 = "Yay"; 
    char *s2 = "Yay"; 

    my_strcmp_rec(s1, s2);
    printf("This is your first string: %s\n",s1);
    printf("This is your second string: %s\n",s2);
    if (my_strcmp_rec(s1, s2) == 0)
    {
        printf("Your strings are the same");
    }
    else
    {
        printf("Your strings are not the same");
    }
    //q4 on python
    //q5
    char *string="123";
    int int1 = my_atoi(string);
    printf("%d\n", int1);
    return 0;
}