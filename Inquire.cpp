#include"primary.h"
void Inquire(const char * fileDat)
{
	char choice;
	peopleData people;
	int key;
	fstream fdat(fileDat, ios::in | ios::binary);
	cout << "**************��ѯ**************" << endl;
	while (1)
	{
		cout << "���������ѡ��\n" << "1 : ����Ų�ѯ\t" << "2 : ���\t" << "Q : �˳�\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			fdat.seekg(0, ios::beg);
			cout << "��ţ�TP����";
			cin >> key;
			do
			{
				fdat.read((char *)&people, sizeof(peopleData));
			} while (people.TP != key && !endMark(people));
			if(people.TP==key)
				cout << people.TP << '\t' << people.peopleName << '\t' << "�绰���룺" << people.phoneNumber << '\t'
				<< "�������䣺" << people.emailAddress << '\t' << "QQ�ţ�" << people.QQNumber << endl;
			else
			{
				cout << "��������������������\n";
				continue;
			}
			break;
		}
		case '2':
		{
			fdat.seekg(0, ios::beg);
			do
			{
				fdat.read((char *)&people,sizeof(peopleData));
				if(!endMark(people))
					cout << people.TP << '\t' << people.peopleName << '\t' << "�绰���룺" << people.phoneNumber << '\t'
					<< "�������䣺" << people.emailAddress << '\t' << "QQ��" << people.QQNumber << endl;
			} while (!endMark(people));
			break;
		}
		case 'q':
		case 'Q': return;
		}
	}
	fdat.close();
}