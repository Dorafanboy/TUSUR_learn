#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
    int x, subtraction = 0;
    std::ifstream fin("inputDATA.txt"); //������� ���� ��� ������

    if (!fin.is_open()) // ���� ���� �� ������
        std::cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
    else
    {
        fin >> x;
        std::cout << x << " ";
        subtraction = x;

        while(!fin.eof())
        {
            fin >> x;
            std::cout << x << " ";
            subtraction -= x;
        }
        fin.close(); // ��������� ����
        std::cout << std::endl << subtraction << std::endl;
    }
    std::ofstream fout("outputDATA.txt"); //������� ���� ��� ������ ����������
    if (!fout.is_open()) // ���� ���� �� ������
        std::cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
    else
    {
         fout << subtraction;
         fout.close(); // ��������� ����
    }

    system("pause");

    return 0;
}
