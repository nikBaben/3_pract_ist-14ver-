#include <stdlib.h>
#include <stdio.h> 
#include "3task.h"


//Функция выделения памяти под динамическую матрицу
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

//Функция отчистки памяти динамической матрицы
void clear_memmory_of_matrix(void **matrix,int row){
    for(int i = 0; i < row; i++)
        free(matrix[i]);
}

//Функция заполнения целочисленной динамической матрицы
void add_int_elements_in_matrix(int **matrix,int row,int column){
    //заполняем матрицу по строчно
    for(int i=0;i<row;i++)
    {
        add_int_elements_in_array(*(matrix+i),column);//Вызываем функию заполенния одномерного массива
    }
}

//Функция заполнения вещественной динамической матрицы
void add_double_elements_in_matrix(double **matrix,int row,int column){
    //заполняем матрицу по строчно
    for(int i=0;i<row;i++)
    {
        add_double_elements_in_array(*(matrix+i),column);//Вызываем функию заполенния одномерного массива
    }
}

//Функция вывода целочисленной матрицы
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

//Функция вывода вещественной матрицы 
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