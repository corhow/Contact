#include"primary.h"
const char * fileTxt = "d:\\addressbook.txt";
void CreateTxt(const char *fileDat)
{
	fstream fdat(fileDat, ios::in | ios::binary);
	fstream ftxt(fileTxt, ios::out);
	fdat.seekp(0, ios::beg);
	peopleData people;
	cout << "*******************�����ı��ļ�*******************" << endl;
	do
	{
		fdat.read((char *)&people, sizeof(peopleData));
		if(!endMark(people))
			ftxt << people.TP << '\t' << people.peopleName << '\t' << "�绰���룺" << people.phoneNumber << '\t'
			<< "�������䣺" << people.emailAddress << '\t' << "QQ�ţ�" << people.QQNumber << endl;
	} while (!endMark(people));
	ftxt.close();
	cout << "�ı��ļ��ѽ�����Ҫ����ļ��𣿣�Y/N��\n";
	char answer, s[200];
	loop:
	cin >> answer;
	if (answer == 'Y' || answer == 'y')
	{
		ftxt.open("d:\\addressbook.dat", ios::in);
		while (!ftxt.eof())
		{
			ftxt.getline(s, 200);
			cout << s << endl;
		}
		ftxt.close();
	}
	else if (answer != 'N' || answer != 'n')
	{
		cout << "����������������룺";
		goto loop;
	}
	fdat.close();
}