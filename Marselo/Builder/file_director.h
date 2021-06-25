#ifndef FILE_DIRECTOR
#define FILE_DERECTOR


#include "file_builder.h"


class FileDirector
{
public:
	inline void setBuilder(FileBuilder* pfbInit);
	inline void construct();

private:
	FileBuilder* pfb;
};


void FileDirector::setBuilder(FileBuilder* pfbInit)
{
	pfb = pfbInit;
}


void FileDirector::construct()
{
	pfb->buildNextRow("Hey,");
	pfb->buildNextRow("This is my file!");
	pfb->closeFile();
}


#endif