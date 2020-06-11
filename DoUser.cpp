#include "StdAfx.h"
#include "DoUser.h"
#include "md5.h"

DoUser::DoUser(void)
{
	init();
}

DoUser::~DoUser(void)
{
}

void DoUser::init()
{
	//User tu;
	//tu.name="dxf";
	//tu.password="dxf";
	//tu.grade=0;
	//vuser.push_back(tu);
	//tu.name="aaa";
	//tu.password="aaa";
	//tu.grade=1;
	//vuser.push_back(tu);
	User tu;
	ifstream ftouch("user.txt");
	if (!ftouch)
	{
		cerr << "用户初始化\n";
		ofstream fmake("user.txt");
		if (!fmake)
		{
			cerr << "初始化失败\n";
			exit(1);
		}
		fmake.close();
		userInit();
	}
	ftouch.close();
	ifstream fin("user.txt");
	while (fin.peek() != EOF)
	{
		fin >> tu.name >> tu.password >> tu.grade;
		vuser.push_back(tu);
	}
	fin.close();
}
void DoUser::userInit()
{
	string tempPw;
	User tu;
	cout << "请输入初始用户名：";
	cin >> tu.name;
	cout << "请输入初始密码：";
	cin >> tempPw;
	tu.password = MD5(tempPw).toStr();
	tu.grade = 0;
	vuser.push_back(tu);
	cout << "初始用户创建成功。\n";
	saveall();
}
bool DoUser::checkuser(string tname, string tpw)
{
	tpw = MD5(tpw).toStr();
	int i = 0;
	bool flag = false;
	while (i < vuser.size())
	{
		if (tname == vuser.at(i).name && tpw == vuser.at(i).password)
		{
			flag = true;
			thistimename = vuser.at(i).name;
			thistimepassword = vuser.at(i).password;
			thistimeusergrade = vuser.at(i).grade;
			break;
		}
		i++;
	}
	return flag;
}
void DoUser::displayoneself()
{
	cout << "您的用户名是：" << thistimename << endl;
	cout << "您的等级是：" << thistimeusergrade << endl;
}
void DoUser::displayalluser()
{
	int i = 0;
	while (i < vuser.size())
	{
		cout << "用户名：" << vuser.at(i).name << "\t等级：" << vuser.at(i).grade << endl;
		i++;
	}
}
void DoUser::insertoneuser()
{
	string tempPw;
	User tu;
	cout << "请输入新用户名：";
	cin >> tu.name;
	cout << "请输入新密码：";
	cin >> tempPw;
	tu.password = MD5(tempPw).toStr();
	cout << "请输入新用户等级：";
	cin >> tu.grade;
	vuser.push_back(tu);
	cout << "插入新用户成功。" << endl;
	saveall();
}
void DoUser::deleteoneuser()
{
	int i = 0;
	string tname;
	cout << "请输入希望删除的用户名：";
	cin >> tname;
	vector<User>::iterator theIterator;
	for (theIterator = vuser.begin(); theIterator < vuser.end(); theIterator++)
	{
		if (vuser.at(i).name == tname)
		{
			vuser.erase(theIterator);
			break;
		}
		i++;
	}
	if (i >= vuser.size())
		cout << "该用户不存在，删除用户失败。" << endl;
	else
	{
		cout << "删除用户成功。" << endl;
	}
	saveall();
}
void DoUser::selectoneuser()
{
	int i = 0;
	string tname;
	cout << "请输入希望查找的用户名：";
	cin >> tname;
	for (; i < vuser.size(); i++)
	{
		if (vuser.at(i).name == tname)
		{
			cout << "该用户名是：" << vuser.at(i).name << endl;
			cout << "该用户名的等级是：" << vuser.at(i).grade << endl;
			break;
		}
	}
	if (i >= vuser.size())
		cout << "该用户不存在，查找用户失败。" << endl;
	else
	{
		cout << "查找用户成功。" << endl;
	}
}
void DoUser::modifyoneuser()
{
	string tname;
	cout << "请输入希望修改的用户名：";
	cin >> tname;
	string newpassword;
	int i = 0, newgrade;
	while (i < vuser.size())
	{
		if (vuser.at(i).name == tname)
		{
			cout << "请输入新密码，不超过20个英文字符：";
			cin >> newpassword;
			vuser.at(i).password = MD5(newpassword).toStr();
			if (thistimeusergrade == 0)
			{
				if (thistimename == tname)
				{
					thistimepassword = MD5(newpassword).toStr();
				}
				else
				{
					cout << "请输入用户新等级：";
					cin >> newgrade;
					vuser.at(i).grade = newgrade;
				}
			}
			else
			{
				thistimepassword = MD5(newpassword).toStr();
			}
			break;
		}
		i++;
	}
	if (i >= vuser.size())
		cout << "该用户不存在，用户资料修改失败。" << endl;
	else
	{
		cout << "用户资料修改成功。" << endl;
	}
	saveall();
}
void DoUser::modifypassword()
{
	string newpassword;
	int i = 0;
	while (i < vuser.size())
	{
		if (vuser.at(i).name == thistimename)
		{
			cout << "请输入新密码，不超过20个英文字符：";
			cin >> newpassword;
			vuser.at(i).password = MD5(newpassword).toStr();
			thistimepassword = MD5(newpassword).toStr();
			break;
		}
		i++;
	}
	if (i >= vuser.size())
		cout << "该用户不存在，密码修改失败。" << endl;
	else
	{
		cout << "密码修改成功。" << endl;
	}
	saveall();
}
void DoUser::saveall()
{
	ofstream fout("user.txt");
	if (!fout)
	{
		cerr << "文件打开失败" << endl;
		exit(1);
	}
	for (int i = 0; i < vuser.size(); i++)
	{
		fout << vuser[i].name << " " << vuser[i].password << " " << vuser[i].grade;
		if (i < vuser.size() - 1)
			fout << endl;
	}
	fout.close();
}
