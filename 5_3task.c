#include <stdio.h>
#include <stdlib.h> 
#include "4task.h" //Импортируем нашу библиотеку для работы с матрицами


//Прототип функции поиска простых чисел у одномерного массива
int find_simple_chars_array(int *array,int size_array);
//Прототип функции поиска простых чисел у матрицы
int find_simple_chars_matrix(int **matrix,int row, int column);




int main(){
    int size_array;                    //Рзамер массива
    int row,column;                    //кол-во строк и столбцов у матрицы
    int *x;                            //указатель на массив
    int size_data;                     //память под 1 элемент матрицы
    void **p;                          //указатель на матрицу
    int simple_array,simple_matrix=0;  //Кол-во простых элементов у массива, матрицы

    //Вводим размер массива
    printf("Введите размер одномерного массива\n");
    scanf("%d", &size_array);
    if(size_array <= 0){
        printf("Размер должен быть > 0.\n");
        return 0;
    }

    //Выделяем память под одномерный массив
    x = (int*)malloc(sizeof(int)*size_array);

    add_int_elements_in_array(x,size_array); //Вызываем функцию добавления элементов в массив
    printf("Ваш массив\n");
    output_int_array(x,size_array);         //Вызываем функцию вывода массива

    simple_array = find_simple_chars_array(x,size_array);   //Вызываем функию поиска простых чисел у массива(Возвращаемое значение кол-во найденых элементов)


    //Вводим кол-во строк, столбцов и определяемую память
    printf("\nВведите кол-во строк, столбцов и память\n");
    scanf("%d %d %d", &row,&column,&size_data);
    if((row && column ) <= 0){
        printf("Размер должен быть > 0.\n");
        return 0;
    }

    p = init_dynamic_matrix(row,column,size_data);  //Вызываем функцию для выделения памяти под матрицу
    int **ptr_matrix = (int**) p;                   //Указатель для целочисленной матрицы 

    add_int_elements_in_matrix(ptr_matrix,row,column); //Вызываем функцию добавления элементов в матрицу
    printf("Ваша матрица\n");
    output_int_matrix(ptr_matrix,row,column);           //Вызываем функцию вывода матрицы

    simple_matrix = find_simple_chars_matrix(ptr_matrix,row,column); //Вызываем функию поиска простых чисел у матрицы(Возвращаемое значение кол-во найденых элементов)

    printf("Кол-во простых чисел у массива: ");
    printf(" %d\n",simple_array);
    printf("Кол-во простых чисел у матрицы: ");
    printf(" %d\n",simple_matrix);

    //Чистим память
    free(x); 
    clear_memmory_of_matrix(p,row);

    
    return 0; 
}


//Функция поиска простых чисел у одномерного массива
int find_simple_chars_array(int *array,int size_array){
    int count = 0;  //Кол-во простых элементов в массиве
    int flag = 0;   //Кол-во делителей у элемента массива

    //Если у элемента массива 2 делителя(само число и 1), то к счетчику простых элементов прибавляем 1
    for(int i = 0; i <size_array; i++){  
        for(int j = 1; j <=size_array; j++){
            if ((*(array+i))% j  == 0){   
                flag +=1;
            }
        }
        if (flag == 2){ 
            count+=1;
        }
        flag = 0;
    }
    //Возвращаем кол-во простых чисел у массива
    return count;
}

//Функцция посика простых элементов у матрицы
int find_simple_chars_matrix(int **matrix,int row, int column){
    int count = 0;      //Кол-во простых элементов у матрицы
    int flag = 0;       //Кол-во делителей у элемента матрицы

    //Если у элемента матрицы 2 делителя(само число и 1), то к счетчику простых элементов прибавляем 1
    for(int i = 0; i < row; i++){    
        for(int j =0; j < column; j++){
            for(int k = 1; k <= (row*column); k++){
                if(matrix[i][j] % k  == 0){   
                    flag +=1;
                }
            }
            if (flag == 2){ 
                count+=1;
            }
            flag = 0;
        }
    }
    //Возвращаем кол-во простых чисел у матрицы
    return count;
}