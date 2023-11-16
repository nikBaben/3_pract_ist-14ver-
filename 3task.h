#include <stdio.h>
#include <stdlib.h>


//Функция ввода одномерного массива 
void add_int_elements_in_array(int *array,int size_array){
    for(int i = 0; i< size_array; i++)
    {   
        scanf("%d", array+i);
    }
}

void add_double_elements_in_array(double *array,int size_array){
    for(int i = 0; i< size_array; i++)
    {   
        scanf("%lf", array+i);
    }
}


//Функция вывода массива в виде непрерывной последовательности чисел разделенных пробелами
void output_int_array(int *array,int size_array){
    printf("Ваш массив: ");
    for(int i = 0; i< size_array; i++)
    {
        printf("%d ", *(array+i));
    }
    printf("\n");
}  

void output_double_array(double *array,int size_array){
    printf("Ваш массив: ");
    for(int i = 0; i< size_array; i++)
    {
        printf("%lf ", *(array+i));
    }
    printf("\n");
}  

//Функция вывода массива в виде таблицы
void output_int_array_table(int *array,int size_array){
    printf("Ваш массив в виде таблицы: ");
    for(int i = 0; i< size_array; i++)
    {   
        printf("|%5d| ", *(array+i));
    }
    printf("\n");
} 


void output_double_array_table(double *array,int size_array){
    printf("Ваш массив в виде таблицы: ");
    for(int i = 0; i< size_array; i++)
    {   
        printf("|%5lf| ", *(array+i));
    }
    printf("\n");
} 
