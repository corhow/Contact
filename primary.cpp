#include"primary.h"
const char *fileDat = "d:\\Addressbook.dat";          //��D�̽���ͨѶ¼�ļ�
const char *RfileDat = "d:\\Relatives Addressbook.dat";
const char *FfileDat = "d:\\Friends Addressbook.dat";
const char *CfileDat = "d:\\Classmates Addressbook.dat";
const char *TfileDat = "d:\\Teacher Addressbook.dat";
const char *OfileDat = "d:\\Others Addressbook.dat";
int main()
{
	char choice;
	while (1)
	{
		cout << "*****************ͨѶ¼*****************\n���������ѡ��\n" << "1 : �½�/�༭��ϵ��\t" << "2 : ɾ����ϵ��     "
			<< "3 : ��ѯ\t" << "4 : �����ı�\t" << "0 : ��ʼ��\t" << "Q : �˳�\n";
		cin >> choice;
		switch (choice)
		{
		case '1':Append(fileDat); break;
		case '2':Delete(fileDat); break;
		case '3':Inquire(fileDat); break;
		case '4':CreateTxt(fileDat); break;
		case '0':Initial(fileDat); break;
		case 'q':
		case 'Q':cout << "�˳�ϵͳ\n"; return 0;
		default:cout << "�����������������\n";
		}
	}
}