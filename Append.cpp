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
	cout << "*************新建/编辑联系人*************" << endl;
	while (1)
	{
		loop:
		cout << "请输入操作选择\n" << "1 : 新建联系人\t" << "2 : 编辑联系人\t" << "Q : 退出\n";
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
			cout << "接下来需分别输入编号，姓名，电话号码，电子邮箱，QQ号。\t(若不存在则输入“0”)\n";
			cout << "编号（TP）：";
			cin >> people.TP;
			cout << "姓名：";
			cin >> people.peopleName;
			cout << "电话号码：";
			cin >> people.phoneNumber;
			cout << "电子邮箱：";
			cin >> people.emailAddress;
			cout << "QQ号：";
			cin >> people.QQNumber;
			fdat.write((char *)&people, sizeof(peopleData));
			fdat.write((char *)&mark, sizeof(peopleData));
			classify(&people);
			break;
		}
		case '2':
		{
			fdat.seekg(0, ios::beg);
			cout << "编号（TP）：\n";
			cin >> key;
			do
			{
				fdat.read((char *)&people, sizeof(peopleData));
			} while (people.TP != key && !endMark(people));
			if (people.TP == key)
			{
				cout << people.TP << '\t' << people.peopleName << '\t' << "电话号码：" << people.phoneNumber << '\t'
					<< "电子邮箱：" << people.emailAddress << '\t' << "QQ号" << people.QQNumber << endl;
				while (1);
				{
					cout << "请输入操作选择\n" << "1 : 编辑电话号码\t" << "2 : 编辑邮箱地址\t" << "3 : 编辑QQ号\t" <<"4 : 编辑联系人关系"<< "Q : 返回\n";
					cin >> choice[1];
					switch (choice[1])
					{
					case '1':
					{
						cout << "电话号码：";
						cin >> people.phoneNumber;
						break;
					}
					case '2':
					{
						cout << "电子邮箱：";
						cin >> people.emailAddress;
						break;
					}
					case '3':
					{
						cout << "QQ号：";
						cin >> people.QQNumber;
						break;
					}
					case '4':
					{
						classify(&people);
					}
					case 'q':
					case 'Q':goto loop;
					default:cout << "输入错误，请重新输入：";
					}
				}
				fdat.seekp(-long(sizeof(peopleData)), ios::cur);
				fdat.write((char *)&people, sizeof(peopleData));
				cout << people.TP << '\t' << people.peopleName << '\t' << "电话号码：" << people.phoneNumber
					<< '\t' << "电子邮箱：" << people.emailAddress << '\t' << "QQ号：" << people.QQNumber << endl;
			}
			else
				cout << "编号输入错误\n";
			break;
		}
		case 'q':
		case 'Q': return;
		default:{
			cout << "输入错误，请重新输入!!!\n";
			goto loop;
		}
		}
	}
	fdat.close();
}
