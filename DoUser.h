#pragma once
#include <vector>
#include "User.h"
class DoUser
{
public:
	DoUser(void);
	~DoUser(void);

	vector<User> vuser;				//User向量，用来存储磁盘文件的内容
	void init();					//初始化，读取磁盘文件，赋值给User向量
	bool checkuser(string, string); //检查用户名和密码
	void displayoneself();			//显示当前登录用户的个人信息
	void displayalluser();			//显示所有用户的个人信息
	void modifypassword();			//修改当前登录用户的密码
	void modifyoneuser();			//修改用户记录
	void insertoneuser();			//插入一条新用户记录
	void deleteoneuser();			//删除一条用户记录
	void selectoneuser();			//查找并显示一条用户记录
	void saveall();					//存盘，将vuser写入磁盘文件
	string thistimename;
	string thistimepassword;
	int thistimeusergrade;
};
