#include <stdlib.h>
#include <stdio.h>
#include "4task.h" // Данная библиотека уже включает в себя библиотеку 3task


int main(){

    // К библиотеки 3task (3 Задание на массивы)
     // Для типа int
    /*int a[10];
    int *p = a;

    add_int_elements_in_array(p,10);
    output_int_array(p,10);
    output_int_array_table(p,10);*/

    //Для типа double
    /*double a[5];
    double *p = a;

    add_double_elements_in_array(p,5);
    output_double_array(p,5);
    output_double_array_table(p,5);*/

    

    // К библиотеке 4task (4 Задание на двумерные массивы)
    /*void **p; // Указатель на матрицу
    int row = 2, column = 2;
    int size_data = 8; 
    int numbers_after_dot = 3;
    p = init_dynamic_matrix(row,column,size_data); // Инициализируем матрицу*/

    // Вариант для типа double

    /*double **ptr =(double**) p; 
    add_double_elements_in_matrix(ptr,row,column);
    output_double_matrix(ptr,row,column,numbers_after_dot);
    clear_memmory_of_matrix(p,row,column);
    output_double_matrix(ptr,row,column,numbers_after_dot);*/

    // Варинат для типа int
    /*int **ptr =(int**) p; 
    add_int_elements_in_matrix(ptr,row,column);
    output_int_matrix(ptr,row,column);
    clear_memmory_of_matrix(p,row,column);
    output_int_matrix(ptr,row,column);*/
 
    
    return 0; 

}