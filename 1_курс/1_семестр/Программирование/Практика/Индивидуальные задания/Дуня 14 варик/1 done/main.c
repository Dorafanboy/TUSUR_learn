#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/** ������� ������� IsPowerN(K, N), ������������ ��������� ��������, ���� ����� �������� K > 0
�������� �������� ����� N > 1, � ���� � ��������� ������. ���� ����� N > 1. */

    int main()
{

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

        printf("�������� �� ����� K �������� N?\n");

        int k=64,n=0;

        printf("����� K: %d\n",k);

    while (n<=1)

        {

        printf("������� N > 1\n");

        scanf("%d",&n);

        if (n<=1) {printf("������!\n\n");

        }

}

    int IsPowerN(int,int);

      printf("\n���������: %d\n(1-��, 0-���)",IsPowerN(k,n));

      system("pause");

      return (0);

    }

    int IsPowerN(K,N)

    {

    int flag=0,P=N;

    while (P <= K)

        {

        if (K == P) {flag = 1; P = P * N;}

        else {P = P * N;}

        }

    return (flag);

    }
