#include <stdio.h>
#include <stdlib.h>

void f1 (int);
void f2 (int, double);
void f3 (int);
void f4 (int);
void f5 (int);

int var_global = 1000;

int main()
{
    /* ������ ������� */
    printf("Adress of main : %p\n", main);
    printf("Adress of f1   : %p\n", f1);
    printf("Adress of f2   : %p\n", f2);
    printf("Adress of f3   : %p\n", f3);
    printf("Adress of f4   : %p\n", f4);
    printf("Adress of f5   : %p\n\n", f5);

    /* ����� ���������� ���������� */
    printf("var_global : adress : %p\tvalue : %d\n\n", &var_global, var_global);

    /* ������ ��������� ���������� */
    int var_main = 100;
    printf("var_main     : adress : %p\tvalue : %d\n", &var_main, var_main);

    void * pointer1_main = malloc (1024);
    printf("pointer1_main : adress : %p\t", &pointer1_main);
    printf("value : %p\tmemory block size : %d bytes\n",  pointer1_main, 1024); /* ����� ����������� ����������� ����� ������ */
    free(pointer1_main);    /* ������������ ������ */
    printf("pointer1_main memory free\n\n");

    /* ������ �������. ������ ������� f1 ���� ����������� ���������� � ������������� ���� ������ */
    f1(1);
    f2(2,3.0);

    pointer1_main = malloc (1024); /* ��������� ��������� ������ ���� �� ������ */
    printf("pointer1_main : new value : %p\tmemory block size : %d bytes\n\n",  pointer1_main, 1024);

    /* ��������� � ������������ ���������� ����� ������ */
    void * pointer2_main = malloc (1024);
    printf("pointer2_main : adress : %p\tvalue : %p\tmemory block size : %d bytes\n\n", &pointer2_main, pointer2_main, 1024);
    free (pointer2_main);
    printf("pointer2_main memory free\n\n");

    f1(4);
    f3(5);
    f4(6);
    f3(7);

    free (pointer1_main);
    printf("pointer1_main memory free\n\n");
    return 0;
}

void f1 (int param_f1)
{
    printf("FUNCTION f1\n");
    int var_f1 = 11;
    void * pointer_f1 = malloc(param_f1*1024);
    printf("param_f1     : adress : %p\tvalue : %d\n", &param_f1, param_f1);
    printf("var_f1       : adress : %p\tvalue : %d\n", &var_f1, var_f1);
    printf("pointer_f1   : adress : %p\tvalue : %p\tmemory block size : %d bytes\n", &pointer_f1, pointer_f1, param_f1*1024);
    free(pointer_f1);
    printf("pointer_f1 memory free\n");
    var_f1++; /* ��������� �������� �������������� ���������� */
    printf ("EXIT f1\n\n");
}

void f2 (int param1_f2, double param2_f2)
{
    printf("FUNCTION f2\n");
    int var_f2 = 20;
    printf("param1_f2 : adress : %p\tvalue : %d\n", &param1_f2, param1_f2);
    printf("param2_f2 : adress : %p\tvalue : %.1f\n", &param2_f2, param2_f2);
    printf("var_f2    : adress : %p\tvalue : %d\n\n", &var_f2, var_f2);
    f1 ( var_f2 + 5 );
    printf ("EXIT f2\n\n");
}

void f3 (int param_f3)
{
    printf("FUNCTION f3\n");
    static int var_f3 = 30;
    printf("param_f3 : adress : %p\tvalue : %d\n", &param_f3, param_f3);
    printf("var_f3   : adress : %p\tvalue : %d\n", &var_f3, var_f3);
    var_f3++;   /* ��������� �������� ���������� ������ static */
    printf ("EXIT f3\n\n");
}

void f4 (int param_f4)
{
    printf("FUNCTION f4\n");
    printf("param_f4 : adress : %p\tvalue : %d\n\n", &param_f4, param_f4);
    f5 (param_f4+1);
    printf ("EXIT f4\n\n");
}

void f5 (int param_f5)
{
    printf("FUNCTION f5\n");
    printf("param_f5 : adress : %p\tvalue : %d\n\n", &param_f5, param_f5);
    if ( param_f5 > 0 )
       f5 ( param_f5 - 1 );
    printf ("EXIT f5\n\n");
}
