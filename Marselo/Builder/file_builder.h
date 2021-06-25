#ifndef FILE_BUILDER_H
#define FILE_BUILDER_H


#include <iostream>
#include <fstream>
using namespace std;


class FileBuilder
{
public:
	inline FileBuilder(string strFileName);
	virtual inline void buildNextRow(string strRow)=0;
	virtual inline void closeFile();

private:
	ofstream out;
};


FileBuilder::FileBuilder(string strFileName)
{
	out.open(strFileName.data(), ios::out);
}


void FileBuilder::buildNextRow(string strRow)
{
	out<<strRow.data();
}


void FileBuilder::closeFile()
{
	out.close();
}



#endif