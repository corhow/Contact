#include"primary.h"
void Inquire(const char * fileDat)
{
	char choice;
	peopleData people;
	int key;
	fstream fdat(fileDat, ios::in | ios::binary);
	cout << "**************²éÑ¯**************" << endl;
	while (1)
	{
		cout << "ÇëÊäÈë²Ù×÷Ñ¡Ôñ\n" << "1 : °´±àºÅ²éÑ¯\t" << "2 : ä¯ÀÀ\t" << "Q : ÍË³ö\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			fdat.seekg(0, ios::beg);
			cout << "±àºÅ£¨TP£©£º";
			cin >> key;
			do
			{
				fdat.read((char *)&people, sizeof(peopleData));
			} while (people.TP != key && !endMark(people));
			if(people.TP==key)
				cout << people.TP << '\t' << people.peopleName << '\t' << "µç»°ºÅÂë£º" << people.phoneNumber << '\t'
				<< "µç×ÓÓÊÏä£º" << people.emailAddress << '\t' << "QQºÅ£º" << people.QQNumber << endl;
			else
			{
				cout << "±àºÅÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë\n";
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
					cout << people.TP << '\t' << people.peopleName << '\t' << "µç»°ºÅÂë£º" << people.phoneNumber << '\t'
					<< "µç×ÓÓÊÏä£º" << people.emailAddress << '\t' << "QQºÅ" << people.QQNumber << endl;
			} while (!endMark(people));
			break;
		}
		case 'q':
		case 'Q': return;
		}
	}
	fdat.close();
}