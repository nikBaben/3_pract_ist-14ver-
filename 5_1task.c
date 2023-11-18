#include <stdio.h>
#include <stdlib.h>
#include "4task.h"
#include <math.h> //Импортируем нашу библиотеку для работы с матрицами и строками.


//Прототип функции суммы элементов вектора.
int sum_of_vector(int *vector, int n);
//Прототип функции числителя.
int count_chislit(double *x, double*y,int n); 
//Прототип функции подсчета знаменателя.
int count_znamenat(double *x, double *y, int n);


int main(){

    int n;                      //Кол-во элементов у вектора.
    double *x,*y;               //Указатели на вещественные массивы.
    double chislit,znamenat;    //Значения числителя и знаменателя.
    double answer;              //Значения функции.


    scanf("%d", &n); 
    add_double_elements_in_array(x,n);  //Вызываем функцию заполнения массива.
    add_double_elements_in_array(y,n);  //Вызываем функцию заполнения массива.
    chislit = count_chislit(x,y,n);     //Вызываем функцию подсчета числителя функции(Возвращаемое значение - численное значение числителя).
    znamenat = count_znamenat(x,y,n);   //Вызываем функцию подсчета знаменателя функции((Возвращаемое значение - численное значение знаменателя)).
    answer = chislit/ znamenat;         

    printf("%lf\n", answer);

    return 0;

}


//Функция суммы элементов вектора.
int sum_of_vector(int *vector, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += vector[i];
    }

    return sum;
}

//Функция подсчета числителя.
int count_chislit(double *x, double*y,int n){

    double sumX = 0;    //Сумма всех элементов веткора x.
    double sumY = 0;    //Сумма всех элементов ветктора Y.
    double all_sum = 0; // Значение первого слагаемого числителя.
    double n_y;         
    double otv = 0;     //Значение числителя.

    sumX = sum_of_vector(x,n);   //Вызываем функцию для подсчета суммы всех элеметов вектора X.
    sumY = sum_od_vector(y,n);   //Вызываем функцию для подсчета суммы всех элеметов вектора Y.

    //Считаем Первое слагаемое числителя.
    for(int j = 0; j < n; j++){
        n_y = y[j] *(sumX *n);
        all_sum +=n_y; //Первое слагамое.
    }


    //Значение числителя.
    otv =  (all_sum - (sumX*sumY));
    return otv;

}

//Функция подсчета знаменателя.
int count_znamenat(double *x, double *y, int n){

    double sumX,sumX_2;    //Значение сумм слагаемых.
    double sumY,sumY_2;    
    double otv;             //Значение знаменателя.
    double first,second;    //Значение первого и второго множителей.

    //Первое слагаемое.
    for(int i = 0; i < n; i++){
        sumX += (x[i])*(x[i]);
    }
    //Второе слагаемое.
    sumX_2 = sum_of_vector(x,n);//Вызываем функцию для подсчета суммы всех элеметов вектора X.
    sumX_2 = sumX_2*sumX_2;
    //Первый множитель.
    first = sumX - sumX_2;
    


    //Первое слагаемое.
    for(int j = 0; j< n; j++){
        sumY += (y[j])*(y[j]);
    }
    //Второе слагаемое.
    sumY_2 = sum_of_vector(x,n);//Вызываем функцию для подсчета суммы всех элеметов вектора X.
    sumX_2 = sumX_2*sumX_2;
    //Второй множитель.
    second = sumY - sumY_2;

    //Численное значение знаменателя.
    otv = first*second; 
    otv = sqrt(otv);
    return otv;
}