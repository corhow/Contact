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
		cout << "ÇëÊäÈë²Ù×÷Ñ¡Ôñ\n" << "1 : É¾³ýÁªÏµÈË\t" << "Q : ÍË³ö\n";
		cin >> choice;
		switch (choice)
		{
		case '1': 
		{
			fdat.seekg(0, ios::beg);
			cout << "±àºÅ£¨TP£©£º\n";
			cin >> key;
			do
			{
				fdat.read((char *)&people, sizeof(peopleData));
			} while (people.TP != key && !endMark(people));
			if (people.TP == key)
			{
				cout << people.TP << '\t' << people.peopleName << '\t' << "µç»°ºÅÂë£º" << people.phoneNumber << '\t'
					<< "µç×ÓÓÊÏä£º" << people.emailAddress << '\t' << "QQºÅ" << people.QQNumber << endl;
				cout << "ÇëÊäÈë²Ù×÷Ñ¡Ôñ\n" << "1 : É¾³ýµç»°ºÅÂë\t" << "2 : É¾³ýÓÊÏäµØÖ·\t" << "3 : É¾³ýQQºÅ\t" << "0 : É¾³ýÁªÏµÈË" << "Q : ·µ»Ø";
				cin >> num;
				switch (num)
				{
				case '1':memset(people.phoneNumber,0,sizeof(people.phoneNumber)); break;
				case '2':memset(people.emailAddress,0,sizeof(people.emailAddress)); break;
				case '3':memset(people.QQNumber, 0, sizeof(people.QQNumber)); break;
					//case '0':
				case 'q':
				case 'Q':goto loop;
				default:cout << "ÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë";
				}
				fdat.seekp(-long(sizeof(peopleData)), ios::cur);
				fdat.write((char *)&people, sizeof(peopleData));
				cout << people.TP << '\t' << people.peopleName << '\t' << "µç»°ºÅÂë£º" << people.phoneNumber << '\t'
					<< "µç×ÓÓÊÏä£º" << people.emailAddress << '\t' << "QQºÅ£º" << people.QQNumber << endl;
			}
			else
				cout << "±àºÅÊäÈë´íÎó\n";
			break;
		}
		case 'q':
		case 'Q':return;
		}
	}
	fdat.close();
}