#include"primary.h"

void Delete(const char *fileDat)
{
	char choice;
	peopleData people;
	int key;
	int num;
	fstream fdat(fileDat, ios::in | ios::out | ios::binary);
	while (1)
	{
		loop:
		cout << "���������ѡ��\n" << "1 : ɾ����ϵ��\t" << "Q : �˳�\n";
		cin >> choice;
		switch (choice)
		{
		case '1': 
		{
			fdat.seekg(0, ios::beg);
			cout << "��ţ�TP����\n";
			cin >> key;
			do
			{
				fdat.read((char *)&people, sizeof(peopleData));
			} while (people.TP != key && !endMark(people));
			if (people.TP == key)
			{
				cout << people.TP << '\t' << people.peopleName << '\t' << "�绰���룺" << people.phoneNumber << '\t'
					<< "�������䣺" << people.emailAddress << '\t' << "QQ��" << people.QQNumber << endl;
				cout << "���������ѡ��\n" << "1 : ɾ���绰����\t" << "2 : ɾ�������ַ\t" << "3 : ɾ��QQ��\t" << "0 : ɾ����ϵ��" << "Q : ����";
				cin >> num;
				switch (num)
				{
				case '1':memset(people.phoneNumber,0,sizeof(people.phoneNumber)); break;
				case '2':memset(people.emailAddress,0,sizeof(people.emailAddress)); break;
				case '3':memset(people.QQNumber, 0, sizeof(people.QQNumber)); break;
					//case '0':
				case 'q':
				case 'Q':goto loop;
				default:cout << "�����������������";
				}
				fdat.seekp(-long(sizeof(peopleData)), ios::cur);
				fdat.write((char *)&people, sizeof(peopleData));
				cout << people.TP << '\t' << people.peopleName << '\t' << "�绰���룺" << people.phoneNumber << '\t'
					<< "�������䣺" << people.emailAddress << '\t' << "QQ�ţ�" << people.QQNumber << endl;
			}
			else
				cout << "����������\n";
			break;
		}
		case 'q':
		case 'Q':return;
		}
	}
	fdat.close();
}