#include"primary.h"
extern const peopleData mark;

void Initial(const char *fileDat)
{
	fstream fdat(fileDat, ios::out | ios::binary);
	cout << "若通讯录文件存在，则将删除原有数据，要进行文件初始化吗？（Y/N）\n";
	char answer;
	loop:
	cin >> answer;
	if (answer == 'Y' || answer == 'y')
	{
		fdat.seekp(0, ios::beg);
		fdat.write((char*)&mark, sizeof(peopleData));
		cout << "文件已经初始化。\n";
	}
	else if (answer == 'N' || answer == 'n')
		cout << "取消操作\n";
	else
	{
		cout << "输入不合法，请重新输入。\n";
		goto loop;
	}
	fdat.close();
}