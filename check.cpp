#include"primary.h"

bool check(fstream *fileDat)
{
	if (!fileDat)
	{
		cout << "ͨѶ¼�ļ������ڣ�����г�ʼ��������\n";
		return true;
	}
	return false;
}

template<typename T>
void ending(fstream &fdat,T&A)
{
	fdat.seekg(0, ios::beg);
	do
	{
		fdat.read((char*)&A, sizeof(peopleData));
	} while (!endMark(A));
	fdat.seekp(-long(sizeof(peopleData)), ios::cur);
}

template void ending<relativesData>(fstream&, relativesData&);
template void ending<friendsData>(fstream&, friendsData&);
template void ending<classmatesData>(fstream&, classmatesData&);
template void ending<teachersData>(fstream&, teachersData&);
template void ending<othersData>(fstream&, othersData&);