#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//ФПрототип функции для вычисления интеграла
void integral(double f(double), int n, int b, int a);
//Пототип функции первой функции для интегрирования 
double first_function(double x); 
//Прототип функция пвторой функции для интегрирования
double second_function(double x);


int main(){
    
    int N;      
    double b,a;     //Верхний и нижний предел интеграла 

    //Вводим n кратное 3
    printf("Введите n: ");
    scanf("%d", &N);
    if(N%3 != 0){
        printf("Введите число делящиеся на 3\n");
        return 1;
    }

    //Обработка первого интеграла
    a = 4; 
    b = -1;
    printf("Значение 1 интеграла: ");
    integral(first_function,N,b,a); //Вызывваем функцию подсчета интеграла, предавая в него функцию first_function(Первая функция)

    printf("\n");
    //Обработка второго интеграла
    a = 3.5;
    b = 0.5;
    printf("Значение 2 интеграла: ");
    integral(second_function,N,b,a);//Вызывваем функцию подсчета интеграла, предавая в него функцию second_function(Вторая функция)

   
    return 0;
}


//Функция для вычисления интеграла
void integral(double f(double), int n, int b, int a){   

    double dx; 
    double count;                   //Счетчик для цикла
    double *X_N;                    //Указатель на массив x_0, x_1 и тд
    double *Y_N;                    //Указатель на массив y_0, y_1 и тд
    double x_n;                     //Значения на отрезках x
    double sum = 0;                 //Сумма значений функции на каждом отрезке x
    double res;                     //Результат интегрирования функции
    double func;                    //Значение функции на каждом отрзке x

    x_n =  a;                       //начальный элемент отрезков x 
    dx = (double) (3*(b - a))/(8*n); //вычисляем dx
    count = (double) (b-a)/dx;      //Вычисляем счетки для цикла
    count +=1;                      

    //воздаем динамические масссивы для хранения точек x и значений функций y
    X_N = malloc(count * sizeof(double));
    Y_N = malloc(count* sizeof(double));

    //разбивание на равные части x_0, x_1, x_n
    for(int i = 0; i < count ; i++){   
        X_N[i] = x_n;
        x_n += dx;
    }


    //нахождение значений функции на каждом отрезке y_0, y_1, y_n
    for(int j = 0; j < count; j++)
    {
        if( (j!=0) && (j!=(count-1)))
        {
            if(j%3 == 0){
                func = 2*f(X_N[j]);
                Y_N[j] = func;
            }
            else{
                func = 3*f(X_N[j]);
                Y_N[j] = func;
            }
        }
        else{
            func = f(X_N[j]);
            Y_N[j] = func;
        }
    }
    

    //sum += (Y_N[0] + *(Y_N + ((int) count-1)))/2; //получем первое слагаемое - (y_0 + y_n)/2
    //Получаеам оставшиеся слагаемые
    for(int j = 1; j < count-1; j++){   
        sum += Y_N[j];
    }


    res = dx*(sum); //Вычисляем конечный результат

    printf("%lf\n",res);


    free(X_N); // Чистим память занимаемую массивами
    free(Y_N);
}

// Первая функция для интегрирования 
double first_function(double x){ 
    double f;
    f = (2*x)*(x*x+1);
    //Возвращаем значение функции 
    return f;
}

// Вторая функция функция для интегрирования
double second_function(double x){ 
    double f;
    f = (exp(2*x))/2*x;
    //Возвращаем значение функции 
    return f;
}