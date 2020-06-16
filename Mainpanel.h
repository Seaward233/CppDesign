#pragma once

#include "DoUser.h"
#include "DoBook.h"
#include "DoPublishers.h"
#include "DoBase.h"
#include "DoPurchases.h"
class Mainpanel
{
public:
	Mainpanel(void);
	~Mainpanel(void);
	void welcome();
	void mainwindow();			 //程序的主界面
	void adminwindow();			 //管理员的主界面
	void userwindow();			 //普通用户的主界面
	void handlewindow(int kind); //管理员维护资料的主界面，根据参数不同，分别维护：用户、图书、书商、采购单、采购单详情、订单、订单详情
	string username;
	string password;
	int usergrade;
	DoUser mydouser;
	DoPublishers myDoPublishers;
	DoBase myDoBase;
};
