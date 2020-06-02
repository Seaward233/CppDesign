#pragma once
class User
{
public:
	User(void);
	~User(void);
	string name;
	string password;
	int grade; //0为管理员，1为普通用户
};
