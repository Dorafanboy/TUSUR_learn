#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

int main()
{
    setlocale (LC_CTYPE, "RUSSIAN");
    printf ("\t�������: ����� ������� ������ � ������� ������������� �������� ������������� ������� A"
            "\n\t\t ������� m*n. �������� ������� ��� ������ � ���� ������� � ������� ���, �����"
            "\n\t\t ������� A11 ��� ������������ ��������� �������.\n\n");

    char b;
    int A[100][100] = {{-1, 4, 7, 3, 6}, {2, -5, 0, 15, 10}, {8, 9, 11, 12, 20}};
    int m = 3, n = 5, max = INT_MIN, i, j, q;

    printf ("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n   ����� �������� �������� ������� (������������� (A), ��������������� ���� (S), ���� ��������� ������� (R)): ");
    scanf ("%c", &b);
    printf ("\n");


    if (b == 'R' || b == 'r' || b == 's' || b == 'S')
    {
        printf ("   ������� ������ �������.\n   ���������� �����: ");
        scanf ("%d", &m);
        printf ("   ���������� ��������: ");
        scanf ("%d", &n);

        while ((n < 1) || (m < 1) || ((n < 1) && (m < 1)))
        {
            printf ("\n   ������ ������� ����� �����������!!!");

            printf ("\n   ������� ������ ������.\n   ���������� �����: ");
            scanf ("%d", &m);
            printf ("   ���������� ��������: ");
            scanf ("%d", &n);
        }

        if (b == 's' || b == 'S')
        {
            for (int s = 0; s < m; s++)
            {
                printf ("\n");

                for (int l = 0; l < n; l++)
                {
                    printf ("   �������[%d][%d]: ", s + 1, l + 1);
                    scanf ("%d", &(*(*(A + s) + l)));
                }
            }
        }

        if (b == 'R' || b == 'r')
            {
                for (int s = 0; s < m; s++)
                    for (int l = 0; l < n; l++)
                        *(*(A + s) + l) = rand() % 100;
            }
    }


    if (!(b == 'A' || b == 'a' || b == 's' || b == 'S' || b == 'R' || b == 'r'))
    {
        printf ("   ������!!!\n");
        return 0;
    }

    printf ("\n   �������� �������:\n");
    for (int s = 0; s < m; s++)
    {
        printf ("   ");

        for (int l = 0; l < n; l++)
            printf ("%5d", *(*(A + s) + l));

        printf ("\n");
    }

    for (int s = 0; s < m; s++)
        for (int l = 0; l < n; l++)
            {
                if (*(*(A + s) + l) > max)
                {
                    max = *(*(A + s) + l);

                    i = s;
                    j = l;
                }
            }

    for (int l = 0; l < n; l++)
    {
        q = *(*(A + 0) + l);
        *(*(A + 0) + l) = *(*(A + i) + l);
        *(*(A + i) + l) = q;
    }

    for (int s = 0; s < m; s++)
    {
        q = *(*(A + s) + 0);
        *(*(A + s) + 0) =*(*(A + s) + j);
        A[s][j] = q;
    }

    printf ("\n    �� ����������� ������ %d � ������� %d ��������� ������������ ������� �������.", i + 1, j + 1);

    printf ("\n\n   ���������� �������:\n");
    for (int s = 0; s < m; s++)
    {
        printf ("   ");

        for (int l = 0; l < n; l++)
            printf ("%5d", *(*(A + s) + l));

        printf ("\n");
    }

    return 0;
}
