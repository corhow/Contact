#include"primary.h"
extern bool check(fstream *fileDat);

extern const char *RfileDat;
extern const char *FfileDat;
extern const char *CfileDat;
extern const char *TfileDat;
extern const char *OfileDat;
extern const peopleData mark;

vector<relativesData>relatives;
vector<friendsData>friends;
vector<classmatesData>classmate;
vector<teachersData>teacher;
vector<othersData>others;

void classify(peopleData *people)
{
	char choice;
	cout << "请输入与该联系人的关系\n" << "1 : 亲人\t" << "2 : 朋友\t" << "3 : 同学\t" << "4 ; 老师\t" << "5 : 其他" << endl;
	cin >> choice;
	switch (choice)
	{
	case '1':
	{
		relativesData Rda;
		fstream fdat(RfileDat, ios::in | ios::out | ios::binary);
		if (check(&fdat))
			return;
		strcpy(Rda.peopleName, people->peopleName);
		strcpy(Rda.phoneNumber, people->phoneNumber);
		strcpy(Rda.emailAddress, people->emailAddress);
		strcpy(Rda.QQNumber, people->emailAddress);
		relatives.push_back(Rda);
//		ending();
		fdat.write((char *)&Rda, sizeof(peopleData));
		fdat.write((char *)&mark, sizeof(peopleData));
		fdat.close();
		people->whereis = "relatives";
	}break;
	case '2':
	{
		friendsData Fri;
		fstream fdat(FfileDat, ios::in | ios::out | ios::binary);
		if (check(&fdat))
			return;
		strcpy(Fri.peopleName, people->peopleName);
		strcpy(Fri.phoneNumber, people->phoneNumber);
		strcpy(Fri.emailAddress, people->emailAddress);
		strcpy(Fri.QQNumber, people->emailAddress);
		friends.push_back(Fri);
		fdat.write((char *)&Fri, sizeof(peopleData));
		fdat.write((char *)&mark, sizeof(peopleData));
		fdat.close();
		people->whereis = "friends";
	}break;
	case '3':
	{
		classmatesData Cla;
		fstream fdat(CfileDat, ios::in | ios::out | ios::binary);
		if (check(&fdat))
			return;
		strcpy(Cla.peopleName, people->peopleName);
		strcpy(Cla.phoneNumber, people->phoneNumber);
		strcpy(Cla.emailAddress, people->emailAddress);
		strcpy(Cla.QQNumber, people->emailAddress);
		classmate.push_back(Cla);
		fdat.write((char *)&Cla, sizeof(peopleData));
		fdat.write((char *)&mark, sizeof(peopleData));
		fdat.close();
		people->whereis = "classmates";
	}break;
	case '4':
	{
		teachersData Tea;
		fstream fdat(TfileDat, ios::in | ios::out | ios::binary);
		if (check(&fdat))
			return;
		strcpy(Tea.peopleName, people->peopleName);
		strcpy(Tea.phoneNumber, people->phoneNumber);
		strcpy(Tea.emailAddress, people->emailAddress);
		strcpy(Tea.QQNumber, people->emailAddress);
		teacher.push_back(Tea);
		fdat.write((char *)&Tea, sizeof(peopleData));
		fdat.write((char *)&mark, sizeof(peopleData));
		fdat.close();
		people->whereis = "teachers";
	}break;
	case '5':
	{
		othersData Oth;
		fstream fdat(OfileDat, ios::in | ios::out | ios::binary);
		if (check(&fdat))
			return;
		strcpy(Oth.peopleName, people->peopleName);
		strcpy(Oth.phoneNumber, people->phoneNumber);
		strcpy(Oth.emailAddress, people->emailAddress);
		strcpy(Oth.QQNumber, people->emailAddress);
		others.push_back(Oth);
		fdat.write((char *)&Oth, sizeof(peopleData));
		fdat.write((char *)&mark, sizeof(peopleData));
		fdat.close();
		people->whereis = "others";
	}break;
	default:cout << "不存在此分类，请重新输入：";
	}
}