#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

 void function (int n)
    {
    int k=0,
        q=2;
    printf("\n�����: ");

    while (n >= (q*q))
    {
        if ((n%(q*q)) == 0)
        {
            if ((n%(q*q*q)) != 0)
            {
                printf("%d",q);
                printf(" ");
                k=k+1;
            }
        }
        q=q+1;
    }
    if (k == 0) printf("0");

    printf("\n");

    return;
    }

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("��������� ���� ����� q, ��� �������:\n"
           "- n ������� �� q^2; \n"
           "- n �� ������� �� q^3.\n");

    int n;
    printf("\n������� �������� n.\n");
    scanf("%d", &n);

    function (n);

    return 0;
}
