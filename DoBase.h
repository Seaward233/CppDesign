#pragma once
#include <vector>
#include "Base.h"
namespace DoBase
{
	void init();		   //初始化，读取磁盘文件，赋值给Book向量
	void displayallBase(); //显示所有用户的个人信息
	void modifyoneBase();  //修改用户记录
	void insertoneBase();  //插入一条新用户记录
	void deleteoneBase();  //删除一条用户记录
	void selectoneBase();  //查找并显示一条用户记录
	void saveall();		   //存盘，将vuser写入磁盘文件
} // namespace DoBase
