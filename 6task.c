#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void integral(double f(double), int n, int b, int a){   

    double dx; 
    double count;
    double *X_N;
    double *Y_N;
    double x_n; 
    double sum = 0;
    double res;
    double func;
    
    x_n =  a;
    dx = (double) (3*(b - a))/(8*n); //вычисляем dx
    count = (double) (b-a)/dx;
    count +=1;

    //воздаем динамические масссивы для хранения точек x и значений функций y
    X_N = malloc(count * sizeof(double));
    Y_N = malloc(count* sizeof(double));

    //разбивание на равные части x_0, x_1, x_n
    for(int i = 0; i < count ; i++)
    {   
        X_N[i] = x_n;
        x_n += dx;
    }


    //нахождение значений функции на каждом отрезке y_0, y_1, y_n
    for(int j = 0; j < count; j++)
    {
        if( (j!=0) && (j!=(count-1)))
        {
            if(j%3 == 0)
            {
                func = 2*f(X_N[j]);
                Y_N[j] = func;
            }
            else
            {
                func = 3*f(X_N[j]);
                Y_N[j] = func;
            }
        }
        else
        {
            func = f(X_N[j]);
            Y_N[j] = func;
        }
    }
    

    //sum += (Y_N[0] + *(Y_N + ((int) count-1)))/2; //получем первое слагаемое - (y_0 + y_n)/2
    //Получаеам оставшиеся слагаемые
    for(int j = 1; j < count-1; j++)
    {   
        sum += Y_N[j];
    }


    res = dx*(sum); //Вычисляем конечный результат

    printf("%lf\n",res);


    free(X_N); // Чистим память занимаемую массивами
    free(Y_N);
}

double first_function(double x){ // Первая функция для интегрирования 
    double f;
    f = (2*x)*(x*x+1);
    return f;
}


double second_function(double x){ // Вторая функция функция для интегрирования
    double f;
    f = (exp(2*x))/2*x;
    return f;
}

int main(){
    
    int N;
    double b,a;
    printf("Введите n: ");
    scanf("%d", &N);
    if(N%3 != 0){
        printf("Введите число деляешься на 3\n");
        return 1;
    }
    a = 4; 
    b = -1;
    printf("Значение 1 интеграла: ");
    integral(first_function,N,b,a);
    printf("\n");
    a = 3.5;
    b = 0.5;
    printf("Значение 2 интеграла: ");
    integral(second_function,N,b,a);

   
    return 0;
}
