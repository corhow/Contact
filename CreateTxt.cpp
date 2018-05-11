#include"primary.h"
const char * fileTxt = "d:\\addressbook.txt";
void CreateTxt(const char *fileDat)
{
	fstream fdat(fileDat, ios::in | ios::binary);
	fstream ftxt(fileTxt, ios::out);
	fdat.seekp(0, ios::beg);
	peopleData people;
	cout << "*******************建立文本文件*******************" << endl;
	do
	{
		fdat.read((char *)&people, sizeof(peopleData));
		if(!endMark(people))
			ftxt << people.TP << '\t' << people.peopleName << '\t' << "电话号码：" << people.phoneNumber << '\t'
			<< "电子邮箱：" << people.emailAddress << '\t' << "QQ号：" << people.QQNumber << endl;
	} while (!endMark(people));
	ftxt.close();
	cout << "文本文件已建立，要浏览文件吗？（Y/N）\n";
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
		cout << "输入错误，请重新输入：";
		goto loop;
	}
	fdat.close();
}