#include <stdlib.h>
#include <stdio.h> 
#include "3task.h"


//Функция выделения памяти под прямоугольную динамическую матрицу
void** init_dynamic_matrix(int row, int column, int size_of_data){
    void **m; 
    m = (void**) malloc(row * size_of_data); 
    for(int i = 0; i < row; i++)
    {
        m[i] =(void*) malloc( column * size_of_data);
    }
    if(!m){
        printf("Память не выделена\n");
        return NULL;
    }
    //printf("Адрес блока начала указателей: %p\n",m);
    return  m;
}

void clear_memmory_of_matrix(void **matrix,int row,int column){
    for(int i = 0; i < row; i++)
        free(matrix[i]);
}

void add_int_elements_in_matrix(int **matrix,int row,int column){
    for(int i=0;i<row;i++)
    {
        add_int_elements_in_array(*(matrix+i),column);
    }
}

void add_double_elements_in_matrix(double **matrix,int row,int column){
    for(int i=0;i<row;i++)
    {
        add_double_elements_in_array(*(matrix+i),column);
    }
}

void output_int_matrix(int **matrix,int row,int column){
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
}

void output_double_matrix(double **matrix,int row,int column, int numbers_after_dot){
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("%lf ",matrix[i][j]);
            //printf("%.d.%lf",matrix[i][j]);
        }
        printf("\n");
    }
}