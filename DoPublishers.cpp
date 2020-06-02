#include "StdAfx.h"
#include "DoPublishers.h"

DoPublishers::DoPublishers(void)
{
	init();
}

DoPublishers::~DoPublishers(void)
{
}

void DoPublishers::init()
{
	Publishers tu;
	ofstream f1("Publishers.txt", ios::out | ios::app);
	f1.close();
	ifstream fin("Publishers.txt");
	if (!fin)
	{
		cerr << "Publishers文件打开失败" << endl;
		exit(1);
	}
	while (fin.peek() != EOF)
	{
		fin >> tu.ID >> tu.name >> tu.address;
		vPublishers.push_back(tu);
	}
	fin.close();
}
void DoPublishers::displayallPublishers()
{
	int i = 0;
	while (i < vPublishers.size())
	{
		cout << "ID：" << vPublishers.at(i).ID << "\t出版社名：" << vPublishers.at(i).name << "\t地址：" << vPublishers.at(i).address << endl;
		i++;
	}
}
void DoPublishers::insertonePublishers()
{
	Publishers tu;
	cout << "请输入新ID：";
	cin >> tu.ID;
	cout << "请输入新出版社名：";
	cin >> tu.name;
	cout << "请输入新地址：";
	cin >> tu.address;
	vPublishers.push_back(tu);
	cout << "插入新出版社成功。" << endl;
	saveall();
}
void DoPublishers::deleteonePublishers()
{
	int i = 0;
	string tname;
	cout << "请输入希望删除的出版社名：";
	cin >> tname;
	vector<Publishers>::iterator theIterator;
	for (theIterator = vPublishers.begin(); theIterator < vPublishers.end(); theIterator++)
	{
		if (vPublishers.at(i).name == tname)
		{
			vPublishers.erase(theIterator);
			break;
		}
		i++;
	}
	if (i >= vPublishers.size())
		cout << "该图书不存在，删除出版社失败。" << endl;
	else
	{
		cout << "删除出版社成功。" << endl;
	}
	saveall();
}
void DoPublishers::selectonePublishers()
{
	int i = 0;
	string tname;
	cout << "请输入希望查找的出版社名：";
	cin >> tname;
	for (; i < vPublishers.size(); i++)
	{
		if (vPublishers.at(i).name == tname)
		{
			cout << "该出版社名是：" << vPublishers.at(i).name << endl;
			cout << "该出版社ID是：" << vPublishers.at(i).ID << endl;
			cout << "该出版社名地址是：" << vPublishers.at(i).address << endl;
			break;
		}
	}
	if (i >= vPublishers.size())
		cout << "该出版社不存在，查找出版社失败。" << endl;
	else
	{
		cout << "查找出版社成功。" << endl;
	}
}
void DoPublishers::modifyonePublishers()
{
	string tname;
	cout << "请输入希望修改的出版社名：";
	cin >> tname;
	int newID;
	int i = 0;
	string newaddress;
	while (i < vPublishers.size())
	{
		if (vPublishers.at(i).name == tname)
		{
			cout << "请输入新ID，不超过20个英文字符：";
			cin >> newID;
			vPublishers.at(i).ID = newID;
			cout << "请输入图书地址：";
			cin >> newaddress;
			vPublishers.at(i).address = newaddress;
			break;
		}
		i++;
	}
	if (i >= vPublishers.size())
		cout << "该图书不存在，图书资料修改失败。" << endl;
	else
	{
		cout << "图书资料修改成功。" << endl;
	}
	saveall();
}
void DoPublishers::saveall()
{
	ofstream fout("Publishers.txt");
	if (!fout)
	{
		cerr << "文件打开失败" << endl;
		exit(1);
	}
	for (int i = 0; i < vPublishers.size(); i++)
	{
		fout << vPublishers[i].ID << " " << vPublishers[i].name << " " << vPublishers[i].address;
		if (i < vPublishers.size() - 1)
			fout << endl;
	}
	fout.close();
}
