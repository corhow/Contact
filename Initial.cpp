#include"primary.h"
extern const peopleData mark;

void Initial(const char *fileDat)
{
	fstream fdat(fileDat, ios::out | ios::binary);
	cout << "��ͨѶ¼�ļ����ڣ���ɾ��ԭ�����ݣ�Ҫ�����ļ���ʼ���𣿣�Y/N��\n";
	char answer;
	loop:
	cin >> answer;
	if (answer == 'Y' || answer == 'y')
	{
		fdat.seekp(0, ios::beg);
		fdat.write((char*)&mark, sizeof(peopleData));
		cout << "�ļ��Ѿ���ʼ����\n";
	}
	else if (answer == 'N' || answer == 'n')
		cout << "ȡ������\n";
	else
	{
		cout << "���벻�Ϸ������������롣\n";
		goto loop;
	}
	fdat.close();
}