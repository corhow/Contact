#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class peopleData
{
public:
	int TP;
	char peopleName[20];
	char phoneNumber[11];
	char emailAddress[20];
	char QQNumber[15];
	//peopleData *Next;
	string whereis;
};

class teachersData :public peopleData
{
	
};

class classmatesData :public peopleData
{
	
};

class relativesData :public peopleData
{
	
};

class friendsData :public peopleData
{
	
};

class othersData :public peopleData
{
	
};

static int sumPeople = 0;

const peopleData mark = { 0,"noName\0","0" ,"0","0"};
void Initial(const char *fileDat);      //ͨѶ¼�ļ���ʼ��
void Append(const char *fileDat);       //�½�/�༭��ϵ��
void Delete(const char *fileDat);       //ɾ����ϵ��
void Inquire(const char *fileDat);      //��ѯ��ϵ��
void CreateTxt(const char *fileDat);    //�����ı��ļ�
int endMark(peopleData people);        //�жϿձ�־��¼�����ж��ļ�����