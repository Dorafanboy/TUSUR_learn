#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

/** ���� ����� ����� N � ����� �� N ����� �����, ���������� �� ������� ���� ���
����. ������� ����� ����� �� ������� ������, ������������� ����� ������ �
��������� ����� (���� ������ � ��������� ���� ���� ������, �� ������� 0). */

    int main()
{

    srand(time(NULL));

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

        printf("���������� ����� ����� ������ � ��������������� ����: \n");

        int N, Nt, S, i;

          printf("������� N: ");

          scanf("%d",&N);

    int OzAs(int,int,int); ///���������� ������� OzAs

	for (i=1; i <= N; i++){

            Nt = rand();

            if (Nt< 10000) {Nt=0;}
                                                      ///��������� ��������� �����
            else {if (Nt< 25000) {Nt=2;} else{Nt=3;}

	}

    S= OzAs(N, Nt, i);
}

    printf("\nC���� ����� ����� ������ � ��������� ������: %d\n",S);

    system("pause");

    return(0);

}

	int flag =0,S=0,Smb=0; /// ���������� ����������

	int OzAs(N, Nt, i){    ///������� OzAs

	if (i < N/2){          ///��������� ������ ����� ����

            printf("%d ",Nt); ///����� ����� �� �����

            if (Nt == 0){flag++;}

              if (flag == 1){S=S+Nt;}

                if (flag > 1){

                  if (Nt == 0){S=S+Smb;Smb=0;}

                      else{Smb=Smb+Nt;}

                        }
            }

	else {///��������� ������ ����� ����

        if(flag < 2){Nt=0;}

            printf("%d ",Nt); ///����� ����� �� �����

              if (Nt == 0){flag++;}

                if (flag == 1){S=S+Nt;}

                  if (flag > 1){

                    if (Nt == 0){S=S+Smb;Smb=0;}

                    else{Smb=Smb+Nt;

		    }

            }



     }

    return(S);  ///������� S

}
