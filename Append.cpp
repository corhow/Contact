#include"primary.h"
extern const peopleData mark;
extern void classify(peopleData * people);
extern bool check(fstream *fileDat);
extern void ending(fstream&, relativesData&);

void Append(const char *fileDat)
{
	char choice[2];
	peopleData people;
	int key;
	fstream fdat(fileDat, ios::in | ios::out | ios::binary);
	if (check(&fdat))
		return;
	cout << "*************�½�/�༭��ϵ��*************" << endl;
	while (1)
	{
		loop:
		cout << "���������ѡ��\n" << "1 : �½���ϵ��\t" << "2 : �༭��ϵ��\t" << "Q : �˳�\n";
		cin >> choice[0];
		switch (choice[0])
		{
		case '1':
		{
			fdat.seekg(0, ios::beg);
			do
			{
				fdat.read((char*)&people, sizeof(peopleData));
			} while (!endMark(people));
			fdat.seekp(-long(sizeof(peopleData)), ios::cur);
			cout << "��������ֱ������ţ��������绰���룬�������䣬QQ�š�\t(�������������롰0��)\n";
			cout << "��ţ�TP����";
			cin >> people.TP;
			cout << "������";
			cin >> people.peopleName;
			cout << "�绰���룺";
			cin >> people.phoneNumber;
			cout << "�������䣺";
			cin >> people.emailAddress;
			cout << "QQ�ţ�";
			cin >> people.QQNumber;
			fdat.write((char *)&people, sizeof(peopleData));
			fdat.write((char *)&mark, sizeof(peopleData));
			classify(&people);
			break;
		}
		case '2':
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
				while (1);
				{
					cout << "���������ѡ��\n" << "1 : �༭�绰����\t" << "2 : �༭�����ַ\t" << "3 : �༭QQ��\t" <<"4 : �༭��ϵ�˹�ϵ"<< "Q : ����\n";
					cin >> choice[1];
					switch (choice[1])
					{
					case '1':
					{
						cout << "�绰���룺";
						cin >> people.phoneNumber;
						break;
					}
					case '2':
					{
						cout << "�������䣺";
						cin >> people.emailAddress;
						break;
					}
					case '3':
					{
						cout << "QQ�ţ�";
						cin >> people.QQNumber;
						break;
					}
					case '4':
					{
						classify(&people);
					}
					case 'q':
					case 'Q':goto loop;
					default:cout << "����������������룺";
					}
				}
				fdat.seekp(-long(sizeof(peopleData)), ios::cur);
				fdat.write((char *)&people, sizeof(peopleData));
				cout << people.TP << '\t' << people.peopleName << '\t' << "�绰���룺" << people.phoneNumber
					<< '\t' << "�������䣺" << people.emailAddress << '\t' << "QQ�ţ�" << people.QQNumber << endl;
			}
			else
				cout << "����������\n";
			break;
		}
		case 'q':
		case 'Q': return;
		default:{
			cout << "�����������������!!!\n";
			goto loop;
		}
		}
	}
	fdat.close();
}
