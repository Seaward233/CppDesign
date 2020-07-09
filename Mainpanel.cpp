#include "StdAfx.h"
#include "Mainpanel.h"

Mainpanel::Mainpanel(void)
{
	mainwindow();
}
Mainpanel::~Mainpanel(void)
{
}

void Mainpanel::mainwindow()
{
	welcome();
	DoUser::init();
	while (1)
	{
		cout << "请输入您的用户名：";
		cin >> username;
		cout << "请输入您的密码：";
		cin >> password;
		if (DoUser::checkuser(username, password))
		{
			cout << "尊敬的" << username << "，欢迎使用本软件。" << endl;
			usergrade = DoUser::passThisTimeUserGrade();
			break;
		}
		else
		{
			cout << "您输入的信息有误，请重新输入。" << endl;
		}
	}
	if (usergrade == 0)
	{
		adminwindow();
	}
	else
	{
		userwindow();
	}
}
void Mainpanel::welcome()
{
	cout << "\t\t***************************************************" << endl;
	cout << "\t\t*                                                 *" << endl;
	cout << "\t\t*           欢迎使用书店管理系统                  *" << endl;
	cout << "\t\t*             Version:00.01.23                    *" << endl;
	cout << "\t\t*                 2020.06.11                      *" << endl;
	cout << "\t\t*                                                 *" << endl;
	cout << "\t\t***************************************************" << endl;
}
void Mainpanel::adminwindow()
{
	int flag;
	while (1)
	{
		cout << "\t\t***************************************************" << endl;
		cout << "\t\t*      1：查看个人信息请按1                       *" << endl;
		cout << "\t\t*      2：修改个人信息请按2                       *" << endl;
		cout << "\t\t*      3：维护用户资料请按3                       *" << endl;
		cout << "\t\t*      4：维护图书资料请按4                       *" << endl;
		cout << "\t\t*      5：维护书商资料请按5                       *" << endl;
		cout << "\t\t*      6：维护采购单资料请按6                     *" << endl;
		cout << "\t\t*      8：维护订单资料请按8                       *" << endl;
		cout << "\t\t*      9：维护订单详情资料请按9                   *" << endl;
		cout << "\t\t*     10：维护仓库资料请按10                      *" << endl;
		cout << "\t\t*      0：退出请按0                               *" << endl;
		cout << "\t\t***************************************************" << endl;
		cout << "请输入数字选择对应的操作：";
		cin >> flag;
		if (flag == 0)
			break;
		else
		{
			switch (flag)
			{
			case 1:
				DoUser::displayoneself();
				break;
			case 2:
				DoUser::modifypassword();
				break;
			case 3:
				handlewindow(3);
				break;
			case 4:
				handlewindow(4);
				break;
			case 5:
				handlewindow(5);
				break;
			case 6:
				handlewindow(6);
				break;
			case 8:
				handlewindow(8);
				break;
			case 9:
				handlewindow(9);
				break;
			case 10:
				handlewindow(10);
				break;
			default:
				cout << "输入有误，请重试！";
				break;
			}
		}
	}
	cout << endl;
}
void Mainpanel::userwindow()
{
	int flag;
	while (1)
	{
		cout << "\t\t***************************************************" << endl;
		cout << "\t\t*      1：查看个人信息请按1                       *" << endl;
		cout << "\t\t*      2：修改密码请按2                           *" << endl;
		cout << "\t\t*      3：查看图书信息请按3                       *" << endl;
		cout << "\t\t*      4：查看个人购书记录请按4                   *" << endl;
		cout << "\t\t*      0：退出请按0                               *" << endl;
		cout << "\t\t***************************************************" << endl;
		cout << "请输入数字选择对应的操作：";
		cin >> flag;
		if (flag == 0)
			break;
		else
		{
			switch (flag)
			{
			case 1:
				DoUser::displayoneself();
				break;
			case 2:
				DoUser::modifypassword();
				break;
			case 3:
				cout << "查看图书信息" << endl;
				break;
			case 4:
				cout << "按照用户名查找订单详情中的个人购书记录" << endl;
				break;
			default:
				cout << "输入有误，请重试！" << endl;
				break;
			}
		}
	}
	cout << endl;
}
void Mainpanel::handlewindow(int kind)
{
	DoPurchases::init();
	DoBook::init();
	DoBase::init();
	DoPublishers::init();
	string s;
	switch (kind)
	{
	case 3:
		s = "用户";
		break;
	case 4:
		s = "图书";
		break;
	case 5:
		s = "书商";
		break;
	case 6:
		s = "采购单";
		break;
	case 7:
		s = "采购单详情";
		break;
	case 8:
		s = "订单";
		break;
	case 9:
		s = "订单详情";
		break;
	case 10:
		s = "仓库";
		break;
	}
	int flag;
	while (1)
	{
		cout << "\t\t***************************************************" << endl;
		cout << "\t\t*      1：查看所有" << s << "信息请按1                 *" << endl;
		cout << "\t\t*      2：修改一条" << s << "信息请按2                 *" << endl;
		cout << "\t\t*      3：插入一条新" << s << "信息请按3               *" << endl;
		cout << "\t\t*      4：删除一条" << s << "信息请按4                 *" << endl;
		cout << "\t\t*      5：查找并显示一条" << s << "信息请按5           *" << endl;
		cout << "\t\t*      0：返回上级菜单请按0                        *" << endl;
		cout << "\t\t***************************************************" << endl;
		cout << "请输入数字选择对应的操作：";
		cin >> flag;
		if (flag == 0)
			break;
		else
		{
			if (kind == 3)
			{
				switch (flag)
				{
				case 1:
					DoUser::displayalluser();
					break;
				case 2:
					DoUser::modifyoneuser();
					break;
				case 3:
					DoUser::insertoneuser();
					break;
				case 4:
					DoUser::deleteoneuser();
					break;
				case 5:
					DoUser::selectoneuser();
					break;
				default:
					cout << "输入有误，请重试！";
					break;
				}
			}
			else if (kind == 4)
			{
				DoBook::init();
				switch (flag)
				{
				case 1:
					DoBook::displayallBook();
					break;
				case 2:
					DoBook::modifyoneBook();
					break;
				case 3:
					DoBook::insertoneBook();
					break;
				case 4:
					DoBook::deleteoneBookByISBN();
					break;
				case 5:
					DoBook::selectoneBookByAWord();
					break;
				default:
					cout << "输入有误，请重试！";
					break;
				}
			}
			else if (kind == 5)
			{
				switch (flag)
				{
				case 1:
					DoPublishers::displayallPublishers();
					break;
				case 2:
					DoPublishers::modifyonePublishers();
					break;
				case 3:
					DoPublishers::insertonePublishers();
					break;
				case 4:
					DoPublishers::deleteonePublishers();
					break;
				case 5:
					DoPublishers::selectonePublishers();
					break;
				default:
					cout << "输入有误，请重试！";
					break;
				}
			}
			else if (kind == 6)
			{
				switch (flag)
				{
				case 1:
					DoPurchases::displayAllPurchases();
					break;
				case 2:
					DoPurchases::modifyOnePurchases();
					break;
				case 3:
					DoPurchases::newPurchases();
					break;
				case 4:
					DoPurchases::deletOnePurchases();
					break;
				}
			}

			else if (kind == 10)
			{
				switch (flag)
				{
				case 1:
					DoBase::displayallBase();
					break;
				case 2:
					DoBase::modifyoneBase();
					break;
				case 3:
					DoBase::insertoneBase();
					break;
				case 4:
					DoBase::deleteoneBase();
					break;
				case 5:
					DoBase::selectoneBase();
					break;
				default:
					cout << "输入有误，请重试！";
					break;
				}
			}
		}
	}
	cout << endl;
}
