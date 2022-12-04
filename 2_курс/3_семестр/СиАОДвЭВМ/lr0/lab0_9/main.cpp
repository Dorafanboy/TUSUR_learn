#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
    int x;
    std::ifstream fin("inputDATA.txt"); //������� ���� ��� ������
    std::ofstream fout("outputDATA.txt"); //������� ���� ��� ������ ����������


    if (!fin.is_open() && !fout.is_open()) // ���� ����� �� �������
        std::cout << "������� ��� �������� ����� �� ����� ���� �������!\n"; // �������� �� ����
    else
    {
        while(!fin.eof())
        {
            fin >> x;
            if(x % 2 == 0)
            {
                std::cout << x << " - evennumber\n";
                fout      << x << " - evennumber\n";
            }
            else
            {
                std::cout << x << " - oddnumber\n";
                fout      << x << " - oddnumber\n";
            }
        }
        fin.close(); // ��������� ������� ����
        fout.close(); // ��������� �������� ����
    }

    system("pause");
    return 0;
}
