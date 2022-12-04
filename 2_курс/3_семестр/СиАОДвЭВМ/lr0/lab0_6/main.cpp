#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
    int toSubtraction, start;
    std::ifstream fin("inputDATA.txt"); //������� ���� ��� ������
    std::ofstream fout("outputDATA.txt"); //������� ���� ��� ������ ����������


    if (!fin.is_open() && !fout.is_open()) // ���� ����� �� �������
        std::cout << "������� ��� �������� ����� �� ����� ���� �������!\n"; // �������� �� ����
    else
    {
        fin >> start;
        std::cout << start << std::endl;
        while(!fin.eof())
        {
            fin >> toSubtraction;
            std::cout << toSubtraction << " ";
            fout << start-toSubtraction << " ";
        }
        fin.close(); // ��������� ������� ����
        fout.close(); // ��������� �������� ����
    }

    system("pause");
    return 0;
}
