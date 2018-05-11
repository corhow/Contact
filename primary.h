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
void Initial(const char *fileDat);      //通讯录文件初始化
void Append(const char *fileDat);       //新建/编辑联系人
void Delete(const char *fileDat);       //删除联系人
void Inquire(const char *fileDat);      //查询联系人
void CreateTxt(const char *fileDat);    //建立文本文件
int endMark(peopleData people);        //判断空标志记录，即判断文件结束