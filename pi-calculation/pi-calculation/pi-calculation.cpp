// pi-calculation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "common-header.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    double pi;
    int ret;

    //std::cout << "1. Демо вычисления числа Пи в одном потоке\n";
    //pi = calc_pi_single_threaded();
    //printf("Полученное значение числа Пи: %15.12f\n", pi);

    //std::cout << "2. Демо вычисления числа Пи в нескольких потоках с директивой reduction\n";
    //pi = calc_pi_multi_threaded_reduction();
    //printf("Полученное значение числа Пи: %15.12f\n", pi);

    //std::cout << "3. Демо синхронизации с применением директив critical и master\n";
    //ret = syncro_demo();

    //std::cout << "4. Демо вычисления числа Пи в нескольких потоках с директивой critical\n";
    //pi = calc_pi_multi_threaded_critical();
    //printf("Полученное значение числа Пи: %15.12f\n", pi);

    std::cout << "4. Демо вычисления числа Пи в нескольких потоках с директивой atomic\n";
    pi = calc_pi_multi_threaded_atomic();
    printf("Полученное значение числа Пи: %15.12f\n", pi);

}