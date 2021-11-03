// pi-calculation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "common-header.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

    double pi;
    int ret;

    //std::cout << "1. ���� ���������� ����� �� � ����� ������\n";
    //pi = calc_pi_single_threaded();
    //printf("���������� �������� ����� ��: %15.12f\n", pi);

    //std::cout << "2. ���� ���������� ����� �� � ���������� ������� � ���������� reduction\n";
    //pi = calc_pi_multi_threaded_reduction();
    //printf("���������� �������� ����� ��: %15.12f\n", pi);

    //std::cout << "3. ���� ������������� � ����������� �������� critical � master\n";
    //ret = syncro_demo();

    //std::cout << "4. ���� ���������� ����� �� � ���������� ������� � ���������� critical\n";
    //pi = calc_pi_multi_threaded_critical();
    //printf("���������� �������� ����� ��: %15.12f\n", pi);

    std::cout << "4. ���� ���������� ����� �� � ���������� ������� � ���������� atomic\n";
    pi = calc_pi_multi_threaded_atomic();
    printf("���������� �������� ����� ��: %15.12f\n", pi);

}