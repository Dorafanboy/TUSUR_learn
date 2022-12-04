#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


double series (double x, double e)
{
    double a = (2 * x), s = 0;
    int n = 0;

    while (sqrt(a*a) >= e)
    {
        s = s + a;
        n = n + 1;
        a = (a * 4 * x * x) / (4 * n * n + 2 * n);
    }

    return s;
}


int main ()
{
    setlocale (LC_CTYPE, "RUSSIAN");

    printf ("\t���������� � �������� ������� �������� ������� F(x), �������� ����� �������.\n\n");

    printf ("\n\t\t   ������������� \n");
    printf ("\t\t\t__      2n+1 \n");
    printf ("\t\t        \\   (2x) \n");
    printf ("\t�������:  F(x) = > -------. \n");
    printf ("\t\t\t/  (2n+1)! \n");
    printf ("\t\t\tTT \n");
    printf ("\t\t\tn=0 \n\n");
    printf ("\t������� ����� ������� ����� \".\". \n");
    printf ("      ____________________________________________________________________________________\n\n\n");

    double A, B;

    printf ("\t������� ������� ���������. \n\n");
    printf ("\t\t�����: ");
    scanf ("%lf", &A);
    printf ("\t\t������: ");
    scanf ("%lf", &B);
    printf ("\n\n");

    while (A == B)
    {
        printf ("\t������! \n\t������� ���������� �������� ������ ���������. \n\t������� ������ ���������. \n");
        printf ("\t\t�����: ");
        scanf ("%lf", &A);
        printf ("\t\t������: ");
        scanf ("%lf", &B);
        printf ("\n\n");
    }

    double r;

    printf ("\t������� ��� �������������: ");
    scanf ("%lf", &r);
    printf ("\n\n");

    while (r == 0)
    {
        printf ("\t������! \n\t��� ������������� ����� 0. \n\t������� ������ ��������: ");
        scanf ("%lf", &r);
        printf ("\n\n");
    }

    while (sqrt(r * r) > sqrt((A - B) * (A - B)))
    {
        printf ("\t������! \n\t����� ��������� ������ �������� ��� �������������. \n\t������� ������ ��������. \n\n");

        printf ("\t������� ������� ���������. \n\n");
        printf ("\t\t�����: ");
        scanf ("%lf", &A);
        printf ("\t\t������: ");
        scanf ("%lf", &B);
        printf ("\n\n");

        while (A == B)
        {
            printf ("\t������! \n\t������� ���������� �������� ������ ���������. \n\t������� ������ ���������. \n");
            printf ("\t\t�����: ");
            scanf ("%lf", &A);
            printf ("\t\t������: ");
            scanf ("%lf", &B);
            printf ("\n\n");
        }

        printf ("\t������� ��� �������������: ");
        scanf ("%lf", &r);
        printf ("\n\n");

        while (r == 0)
        {
            printf ("\t������! \n\t��� ������������� ����� 0. \n\t������� ������ ��������: ");
            scanf ("%lf", &r);
            printf ("\n\n");
        }
    }

    while (((r > 0) & (A > B)) | ((r < 0) & (A < B)))
    {
        if ((r < 0) & (A < B))
        {
            while ((r < 0) & (A < B))
            {
                printf ("\t������! \n\t�������� ��������� �������������, � ��� ������������� ������ 0. \n\t������� ������ ��������. \n\n");

                printf ("\t������� ������� ���������. \n\n");
                printf ("\t\t�����: ");
                scanf ("%lf", &A);
                printf ("\t\t������: ");
                scanf ("%lf", &B);
                printf ("\n\n");

                while (A == B)
                {
                    printf ("\t������! \n\t������� ���������� �������� ������ ���������. \n\t������� ������ ���������. \n");
                    printf ("\t\t�����: ");
                    scanf ("%lf", &A);
                    printf ("\t\t������: ");
                    scanf ("%lf", &B);
                    printf ("\n\n");
                }

                printf ("\t������� ��� �������������: ");
                scanf ("%lf", &r);
                printf ("\n\n");

                while (r == 0)
                {
                    printf ("\t������! \n\t��� ������������� ����� 0. \n\t������� ������ ��������: ");
                    scanf ("%lf", &r);
                    printf ("\n\n");
                }

                while (sqrt(r * r) > sqrt((A - B) * (A - B)))
                {
                    printf ("\t������! \n\t����� ��������� ������ �������� ��� �������������. \n\t������� ������ ��������. \n\n");

                    printf ("\t������� ������� ���������. \n\n");
                    printf ("\t\t�����: ");
                    scanf ("%lf", &A);
                    printf ("\t\t������: ");
                    scanf ("%lf", &B);
                    printf ("\n\n");

                    while (A == B)
                    {
                        printf ("\t������! \n\t������� ���������� �������� ������ ���������. \n\t������� ������ ���������. \n");
                        printf ("\t\t�����: ");
                        scanf ("%lf", &A);
                        printf ("\t\t������: ");
                        scanf ("%lf", &B);
                        printf ("\n\n");
                    }

                    printf ("\t������� ��� �������������: ");
                    scanf ("%lf", &r);
                    printf ("\n\n");

                    while (r == 0)
                    {
                        printf ("\t������! \n\t��� ������������� ����� 0. \n\t������� ������ ��������: ");
                        scanf ("%lf", &r);
                        printf ("\n\n");
                    }
                }
            }
        }

        if ((r > 0) & (A > B))
        {
            while ((r > 0) & (A > B))
            {
                printf ("\t������! \n\t�������� ��������� �����������, � ��� ������������� ������ 0. \n\t������� ������ ��������. \n\n");

                printf ("\t������� ������� ���������. \n\n");
                printf ("\t\t�����: ");
                scanf ("%lf", &A);
                printf ("\t\t������: ");
                scanf ("%lf", &B);
                printf ("\n\n");

                while (A == B)
                {
                    printf ("\t������! \n\t������� ���������� �������� ������ ���������. \n\t������� ������ ���������. \n");
                    printf ("\t\t�����: ");
                    scanf ("%lf", &A);
                    printf ("\t\t������: ");
                    scanf ("%lf", &B);
                    printf ("\n\n");
                }

                printf ("\t������� ��� �������������: ");
                scanf ("%lf", &r);
                printf ("\n\n");

                while (r == 0)
                {
                    printf ("\t������! \n\t��� ������������� ����� 0. \n\t������� ������ ��������: ");
                    scanf ("%lf", &r);
                    printf ("\n\n");
                }

                while (sqrt(r * r) > sqrt((A - B) * (A - B)))
                {
                    printf ("\t������! \n\t����� ��������� ������ �������� ��� �������������. \n\t������� ������ ��������. \n\n");

                    printf ("\t������� ������� ���������. \n\n");
                    printf ("\t\t�����: ");
                    scanf ("%lf", &A);
                    printf ("\t\t������: ");
                    scanf ("%lf", &B);
                    printf ("\n\n");

                    while (A == B)
                    {
                        printf ("\t������! \n\t������� ���������� �������� ������ ���������. \n\t������� ������ ���������. \n");
                        printf ("\t\t�����: ");
                        scanf ("%lf", &A);
                        printf ("\t\t������: ");
                        scanf ("%lf", &B);
                        printf ("\n\n");
                    }

                    printf ("\t������� ��� �������������: ");
                    scanf ("%lf", &r);
                    printf ("\n\n");

                    while (r == 0)
                    {
                        printf ("\t������! \n\t��� ������������� ����� 0. \n\t������� ������ ��������: ");
                        scanf ("%lf", &r);
                        printf ("\n\n");
                    }
                }
            }
        }
    }

    float e;

    printf ("\t������� ���������� ����������� ����������. \n\t�������� ���������� ����������� ���������� ������ ������� � �������� 0 < e < 1. \n\n\t\t\t\t\t");
    scanf ("%f", &e);

    while ((e <= 0) | (e >= 1))
    {
        printf ("\t������! \n\t�������� ���������� ����������� ���������� �� ������ � �������� 0 < e < 1. \n\t������� ������ ��������: ");
        scanf ("%f", &e);
    }

    printf ("      ____________________________________________________________________________________\n\n");
    printf ("\t\t\t   �������\n\n");
    printf ("\t\t+-----------+----------------+\n");
    printf ("\t\t|     x     |      F(x)      |\n");
    printf ("\t\t+-----------+----------------+\n");

    double x = A, Fx;

    if (A < B)
    {
        while (x <= B)
        {
            Fx = series (x, e);
            printf("\t\t| %9.4lf | %14.9lf |\n", x, Fx);
            x = x + r;
        }
    }
    if (A > B)
    {
        while (x >= B)
        {
            Fx = series (x, e);
            printf("\t\t| %9.4lf | %14.9lf |\n", x, Fx);
            x = x + r;
        }
    }

    printf ("\t\t+-----------+----------------+\n");

    return 0;
}
