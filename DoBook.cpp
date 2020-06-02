#include "StdAfx.h"
#include "DoBook.h"

DoBook::DoBook(void)
{
	init();
}

DoBook::~DoBook(void)
{
}

void DoBook::init()
{
	Book tu;
	ofstream f1("Book.txt", ios::out | ios::app);
	f1.close();
	ifstream fin("Book.txt");
	if (!fin)
	{
		cerr << "Book文件打开失败" << endl;
		exit(1);
	}
	while (fin.peek() != EOF)
	{
		fin >> tu.ISBN >> tu.name >> tu.price;
		vBook.push_back(tu);
	}
	fin.close();
}
void DoBook::displayallBook()
{
	int i = 0;
	while (i < vBook.size())
	{
		cout << "ISBN：" << vBook.at(i).ISBN << "\t书名：" << vBook.at(i).name << "\t价格：" << vBook.at(i).price << endl;
		i++;
	}
}
void DoBook::insertoneBook()
{
	Book tu;
	cout << "请输入新ISBN：";
	cin >> tu.ISBN;
	cout << "请输入新书名：";
	cin >> tu.name;
	cout << "请输入新价格：";
	cin >> tu.price;
	vBook.push_back(tu);
	cout << "插入新图书成功。" << endl;
	saveall();
}
void DoBook::deleteoneBook()
{
	int i = 0;
	string tname;
	cout << "请输入希望删除的书名：";
	cin >> tname;
	vector<Book>::iterator theIterator;
	for (theIterator = vBook.begin(); theIterator < vBook.end(); theIterator++)
	{
		if (vBook.at(i).name == tname)
		{
			vBook.erase(theIterator);
			break;
		}
		i++;
	}
	if (i >= vBook.size())
		cout << "该图书不存在，删除图书失败。" << endl;
	else
	{
		cout << "删除图书成功。" << endl;
	}
	saveall();
}
void DoBook::deleteoneBookByISBN()
{
	int i = 0;
	string tISBN;
	cout << "请输入希望删除的ISBN：";
	cin >> tISBN;
	vector<Book>::iterator theIterator;
	for (theIterator = vBook.begin(); theIterator < vBook.end(); theIterator++)
	{
		if (vBook.at(i).ISBN == tISBN)
		{
			vBook.erase(theIterator);
			break;
		}
		i++;
	}
	if (i >= vBook.size())
		cout << "该图书不存在，删除图书失败。" << endl;
	else
	{
		cout << "删除图书成功。" << endl;
	}
	saveall();
}
void DoBook::selectoneBook()
{
	int i = 0;
	string tname;
	cout << "请输入希望查找的图书名：";
	cin >> tname;
	for (; i < vBook.size(); i++)
	{
		if (vBook.at(i).name == tname)
		{
			cout << "该图书名是：" << vBook.at(i).name << endl;
			cout << "该图书ISBN是：" << vBook.at(i).ISBN << endl;
			cout << "该图书名价格是：" << vBook.at(i).price << endl;
			break;
		}
	}
	if (i >= vBook.size())
		cout << "该图书不存在，查找图书失败。" << endl;
	else
	{
		cout << "查找图书成功。" << endl;
	}
}
void DoBook::selectoneBookByAWord()
{
	int i = 0;
	string tname;
	string ch;
	cout << "允许我们输入一个字符串，根据该字符进行模糊查找。";
	cout << "请输入希望查找的图书名中包含的字符串：";
	cin >> ch;
	int index = 0;
	bool flag = false;
	for (; i < vBook.size(); i++)
	{
		index = 0;
		flag = false;
		if ((index = vBook.at(i).name.find(ch, index)) < vBook.at(i).name.length())
		{
			cout << "该图书名是：" << vBook.at(i).name << endl;
			cout << "该图书ISBN是：" << vBook.at(i).ISBN << endl;
			cout << "该图书名价格是：" << vBook.at(i).price << endl;
			flag = true;
			//break;
		}
	}
	if (flag == false)
		cout << "该图书不存在，查找图书失败。" << endl;
	else
	{
		cout << "查找图书成功。" << endl;
	}
}
void DoBook::modifyoneBook()
{
	string tname;
	cout << "请输入希望修改的图书名：";
	cin >> tname;
	string newISBN;
	int i = 0;
	float newprice;
	while (i < vBook.size())
	{
		if (vBook.at(i).name == tname)
		{
			cout << "请输入新ISBN，不超过20个英文字符：";
			cin >> newISBN;
			vBook.at(i).ISBN = newISBN;
			cout << "请输入图书jiage：";
			cin >> newprice;
			vBook.at(i).price = newprice;
			break;
		}
		i++;
	}
	if (i >= vBook.size())
		cout << "该图书不存在，图书资料修改失败。" << endl;
	else
	{
		cout << "图书资料修改成功。" << endl;
	}
	saveall();
}
void DoBook::saveall()
{
	ofstream fout("Book.txt");
	if (!fout)
	{
		cerr << "文件打开失败" << endl;
		exit(1);
	}
	for (int i = 0; i < vBook.size(); i++)
	{
		fout << vBook[i].ISBN << " " << vBook[i].name << " " << vBook[i].price;
		if (i < vBook.size() - 1)
			fout << endl;
	}
	fout.close();
}
