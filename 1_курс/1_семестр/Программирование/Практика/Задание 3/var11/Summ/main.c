#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);

    printf("�������� ����� N ��������� ��������, ����������� �� �������\n"
           "\n\ta = i/3 ���� i ������ 3, � ��������� ������ a = i/(i-3),\n"
           "\t��� i = 1, 2,..., N.\n"
           "\n������� �������� ���������� ���������: ");
    int N;
    scanf ("%d", &N);

/**     ��������� �������� ����� S */

    double a,
           S= 0.0,
           k = 0,
           b = 0;
    int i = 1;

    while (i <= N)
    {
        if (i%3 == 0)
        {
            a = (double)i / 3;
            k = k + 1;
        }

        else
        {
            a = (double)i / (i - 3);
            b = b + 1;
        }


        S = S + a * a;
        i = i + 1;
    }

    printf ("\n\n\t��� N = %d ����� S = %8.4f\n", N, S);
    printf ("\n\t�������� a = i/3 ��������� k = %5.2f ���; �������� a = i/(i-3) - b = %5.1f ���.\n", k, b);

    return 0;
}
