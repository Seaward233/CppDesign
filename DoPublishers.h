#pragma once
#include <vector>
#include "Publishers.h"
namespace DoPublishers
{
	void init();				 //初始化，读取磁盘文件，赋值给Book向量
	void displayallPublishers(); //显示所有用户的个人信息
	void modifyonePublishers();	 //修改用户记录
	void insertonePublishers();	 //插入一条新用户记录
	void deleteonePublishers();	 //删除一条用户记录
	void selectonePublishers();	 //查找并显示一条用户记录
	void saveall();				 //存盘，将vuser写入磁盘文件
} // namespace DoPublishers
