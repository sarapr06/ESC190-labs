#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//question 1
void set_int1(int x)
{
    x = 42;
}
void set_int2(int *p_x)
{
    *p_x = 42;
}
//question 2
typedef struct student1{
    char name[200]; 
    char student_number[11];
    int year;
} student1;
int print_student(student1 student){
    printf("Name: %s\n", student.name);
    printf("SN: %s\n", student.student_number);
    printf("year: %d\n", student.year);
    return 0;
}
//question 3.a
void set_default_name(student1 *p_s){
    strcpy(p_s->name,"Default Student");//points p_s to a different string
    p_s->year = 0;
    //takes in pointer to student1 and sets name to 'default student'
}
//3.b
void set_default_name_wrong(student1 s){
    strcpy(s.name, "Default Student");//will NOT work because it's trying to assign an array
    s.year = 0; //does work because it's just reassigning an int
}
//4
void create_block1(student1 **p_p_s, int n_students){
    //uses malloc
    //takes in pointer to student and sets pointer to block of n_students*students1
    *p_p_s = (student1 *)malloc(n_students * sizeof(student1));
}
//5
/**/
void set_name(student1 *s, char *name) {
    strcpy(s->name, name);
}

//q6
void destroy_block1(student1 *p_s) {
    free(p_s);
}
//7
typedef struct student2{
    char *name; 
    char *student_number;
    int year;
} student2;

void create_block2(student2 **p_p_s, int num_students) {
    *p_p_s = (student2 *)malloc(num_students * sizeof(student2));
    for (int i = 0; i < num_students; i++) {
        (*p_p_s)[i].name = 0;
        (*p_p_s)[i].student_number = 0;
    }
}
//8
void set_name2(student2 *s, char *name) {
    s->name = (char *)malloc(strlen(name) + 1);
    strcpy(s->name, name);
    *((s->name)+strlen(name)) = '\0';
}
//9
void destroy_block2(student2 *p_s, int num){
    for(int i=0;i<num;i++){
        free(p_s[i].name);
        free(p_s[i].student_number);
    }
    free(p_s);
}


//10
void modify_name(student1 s) {
    strcpy(s.name, "Modified");//changes the LOCAL s, does nothing for the outside of the function
}

void modify_name_ptr(student2 s) {
    strcpy(s.name, "Modified");

}
//question 13
void print_file_contents(char *filename) {
    char line[200];
    FILE *fp=fopen(filename,"r");
    while(fgets(line,sizeof(line),fp)){
        printf("%s\n", line);
    }
    fclose(fp);
}
//q14
void calculate_average( char *filename) {
    char line[200];
    FILE *fp=fopen(filename,"r");
    int sum, count=0;
    while(fgets(line,sizeof(line),fp)){
        sum+=atoi(line);
        count++;
    }
    fclose(fp);
    printf("Average: %f\n", (double)sum/count);
}


int main(){
    //q1
    //using set_int1:
    int a = 1;
    set_int1(a); // no effect on a because it only changes local a
    //using set_int2
    set_int2(&a); // changes a to 42, because it modifies its address

    //q2
    student1 s1={"Sara P", "10100913451", 2024};
    print_student(s1);
    
    //q3
    set_default_name(&s1);
    print_student(s1);
    //q4
    
    student1 *students;
    create_block1(&students, 5);//creates block of 5 students in this example
    set_default_name(&students[2]);
    print_student(students[2]);
    destroy_block1(students);
    
    //5
    student1 s={0};
    char *new_name = "SKDJFNSDLKJFNSDLKJFN";
    set_name(&s, new_name);
    printf("Name: %s\n", s.name);

    
    //8
    student2 *students2;
    create_block2(&students2, 3);
    set_name2(&students2[0], "John Doe");
    // Verify that the name was set correctly
    printf("Student 1 Name: %s\n", students2[0].name);
    destroy_block2(students2, 3);



    //10
    student1 s3={"hi"};
    modify_name(s3); // array is inside struct (local so doesnt change in global)
    printf("Name: %s\n", s3.name);
    student2 s4;
    set_name2(&s4, "John Doe");
    modify_name_ptr(s4); 
    printf("Name: %s\n", s4.name); // char* points and can change the address
    
    //14
    char *filename="text.txt";
    print_file_contents(filename);
    calculate_average(filename);
    return 0;
}