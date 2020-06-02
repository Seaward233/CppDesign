#include "StdAfx.h"
#include "DoBase.h"

DoBase::DoBase(void)
{
	init();
}

DoBase::~DoBase(void)
{
}

void DoBase::init()
{
	Base tu;
	ofstream f1("Base.txt", ios::out | ios::app);
	f1.close();
	ifstream fin("Base.txt");
	if (!fin)
	{
		cerr << "Base文件打开失败" << endl;
		exit(1);
	}
	while (fin.peek() != EOF)
	{
		fin >> tu.ID >> tu.name >> tu.address;
		vBase.push_back(tu);
	}
	fin.close();
}
void DoBase::displayallBase()
{
	int i = 0;
	while (i < vBase.size())
	{
		cout << "ID：" << vBase.at(i).ID << "\t仓库名：" << vBase.at(i).name << "\t地址：" << vBase.at(i).address << endl;
		i++;
	}
}
void DoBase::insertoneBase()
{
	Base tu;
	cout << "请输入新ID：";
	cin >> tu.ID;
	cout << "请输入新仓库名：";
	cin >> tu.name;
	cout << "请输入新地址：";
	cin >> tu.address;
	vBase.push_back(tu);
	cout << "插入新仓库成功。" << endl;
	saveall();
}
void DoBase::deleteoneBase()
{
	int i = 0;
	string tname;
	cout << "请输入希望删除的仓库名：";
	cin >> tname;
	vector<Base>::iterator theIterator;
	for (theIterator = vBase.begin(); theIterator < vBase.end(); theIterator++)
	{
		if (vBase.at(i).name == tname)
		{
			vBase.erase(theIterator);
			break;
		}
		i++;
	}
	if (i >= vBase.size())
		cout << "该仓库不存在，删除仓库失败。" << endl;
	else
	{
		cout << "删除仓库成功。" << endl;
	}
	saveall();
}
void DoBase::selectoneBase()
{
	int i = 0;
	string tname;
	cout << "请输入希望查找的仓库名：";
	cin >> tname;
	for (; i < vBase.size(); i++)
	{
		if (vBase.at(i).name == tname)
		{
			cout << "该仓库名是：" << vBase.at(i).name << endl;
			cout << "该仓库ID是：" << vBase.at(i).ID << endl;
			cout << "该仓库地址是：" << vBase.at(i).address << endl;
			break;
		}
	}
	if (i >= vBase.size())
		cout << "该仓库不存在，查找仓库失败。" << endl;
	else
	{
		cout << "查找仓库成功。" << endl;
	}
}
void DoBase::modifyoneBase()
{
	string tname;
	cout << "请输入希望修改的仓库名：";
	cin >> tname;
	int newID;
	int i = 0;
	string newaddress;
	while (i < vBase.size())
	{
		if (vBase.at(i).name == tname)
		{
			cout << "请输入新ID，不超过20个英文字符：";
			cin >> newID;
			vBase.at(i).ID = newID;
			cout << "请输入仓库地址：";
			cin >> newaddress;
			vBase.at(i).address = newaddress;
			break;
		}
		i++;
	}
	if (i >= vBase.size())
		cout << "该仓库不存在，仓库资料修改失败。" << endl;
	else
	{
		cout << "仓库资料修改成功。" << endl;
	}
	saveall();
}
void DoBase::saveall()
{
	ofstream fout("Base.txt");
	if (!fout)
	{
		cerr << "文件打开失败" << endl;
		exit(1);
	}
	for (int i = 0; i < vBase.size(); i++)
	{
		fout << vBase[i].ID << " " << vBase[i].name << " " << vBase[i].address;
		if (i < vBase.size() - 1)
			fout << endl;
	}
	fout.close();
}
