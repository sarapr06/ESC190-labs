#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//q2
double my_atof(const char *str) {
    int i = 0;// initialize
    int sign = 1; //assume positive
    double result = 0.0; // double
    double fraction = 0.0; // double
    double divisor = 10.0; //for fractions
    int is_fraction = 0;//false at first
    
    if (str[i] == '-') {// adds a negative
        sign = -1;
        i++;
    }
    
    while (str[i] != '\0') {
        if (str[i] == '.') {//if a fraction
            is_fraction = 1;//fraction is true
            i++;//increment
            continue;
        }
        if (!isdigit(str[i])) {//if not is digit then stop! cant compute (works in the case that there are words after a digit)
            break;
        }
        if (is_fraction) {//if we run into a fraction
            fraction += (str[i] - '0') / divisor; //"turning" into a number from another lab
            divisor *= 10.0;//times ten, increment into the fraction
        } else {// if not a fraction
            result = result * 10.0 + (str[i] - '0');//last digit, again "turning" into a number
        }
        i++;//increment i
    }
    return sign * (result + fraction);
}
//q3
void change_name(char *name, const char *new_name) {
    strncpy(name, new_name, 3);
    name[2] = '\0'; // Ensure null termination
}


int main() {
    FILE *file = fopen("lab4test.txt", "r");
    char line[100];
    double sum = 0.0;
    
    while (fgets(line, sizeof(line), file)) {//same code as last lab
        char *ptr = line;
        while (*ptr && *ptr != '='){
            ptr++; // Find '='
        }
        if (*ptr == '='){
            ptr++; // Move past '='
        }

        while (*ptr == ' '){
            ptr++; // Skip spaces
        }
        sum += my_atof(ptr);//sum happens starting where the pointer starts, up until the next line!
    }
    
    fclose(file);
    printf("Sum of constants: %.12f\n", sum);
    

    // Demonstrate change_name function
    char student_name[3] = "ab";
    printf("Original name: %s\n", student_name);
    change_name(student_name, "bc");
    printf("Updated name: %s\n", student_name);
    
    return 0;
}

