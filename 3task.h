#include <stdio.h>
#include <stdlib.h>


//Функция ввода целочисленного одномерного массива. 
void add_int_elements_in_array(int *array,int size_array){
    for(int i = 0; i< size_array; i++){
        scanf("%d", array+i);
    }
}

//Функция ввода вещественного одномерного массива.
void add_double_elements_in_array(double *array,int size_array){
    for(int i = 0; i< size_array; i++){   
        scanf("%lf", array+i);
    }
}

//Функция вывода целочисленного массива в виде непрерывной последовательности чисел разделенных пробелами.
void output_int_array(int *array,int size_array){
    for(int i = 0; i< size_array; i++){
        printf("%d ", *(array+i));
    }
}  

//Функция вывода вещественного  массива в виде непрерывной последовательности чисел разделенных пробелами.
void output_double_array(double *array,int size_array){
    for(int i = 0; i< size_array; i++){
        printf("%lf ", *(array+i));
    }
}  

//Функция вывода целочисленного массива в виде таблицы.
void output_int_array_table(int *array,int size_array){
    for(int i = 0; i< size_array; i++){   
        printf("|%5d| ", *(array+i));
    }
} 

//Функция вывода вещественного массива в виде таблицы.
void output_double_array_table(double *array,int size_array){
    for(int i = 0; i< size_array; i++){   
        printf("|%5lf| ", *(array+i));
    }
} 
