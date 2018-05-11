#include"primary.h"
const char *fileDat = "d:\\Addressbook.dat";          //在D盘建立通讯录文件
const char *RfileDat = "d:\\Relatives Addressbook.dat";
const char *FfileDat = "d:\\Friends Addressbook.dat";
const char *CfileDat = "d:\\Classmates Addressbook.dat";
const char *TfileDat = "d:\\Teacher Addressbook.dat";
const char *OfileDat = "d:\\Others Addressbook.dat";
int main()
{
	char choice;
	while (1)
	{
		cout << "*****************通讯录*****************\n请输入操作选择\n" << "1 : 新建/编辑联系人\t" << "2 : 删除联系人     "
			<< "3 : 查询\t" << "4 : 建立文本\t" << "0 : 初始化\t" << "Q : 退出\n";
		cin >> choice;
		switch (choice)
		{
		case '1':Append(fileDat); break;
		case '2':Delete(fileDat); break;
		case '3':Inquire(fileDat); break;
		case '4':CreateTxt(fileDat); break;
		case '0':Initial(fileDat); break;
		case 'q':
		case 'Q':cout << "退出系统\n"; return 0;
		default:cout << "输入错误，请重新输入\n";
		}
	}
}