#pragma once
#include <vector>
#include "Book.h"
class DoBook
{
public:
	DoBook(void);
	~DoBook(void);
	vector<Book> vBook;			 //User向量，用来存储磁盘文件的内容
	void init();				 //初始化，读取磁盘文件，赋值给Book向量
	void displayallBook();		 //显示所有用户的个人信息
	void modifyoneBook();		 //修改用户记录
	void insertoneBook();		 //插入一条新用户记录
	void deleteoneBook();		 //删除一条用户记录
	void deleteoneBookByISBN();	 //根据ISBN号，删除一条图书记录
	void selectoneBook();		 //查找并显示一条用户记录
	void selectoneBookByAWord(); //查找并显示一条用户记录
	void saveall();				 //存盘，将vuser写入磁盘文件
};
