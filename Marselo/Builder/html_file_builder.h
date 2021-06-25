#ifndef HTML_FILE_BUILDER_H
#define HTML_FILE_BUILDER_H


#include "file_builder.h"


class HTMLFileBuilder : public FileBuilder
{
public:
	inline HTMLFileBuilder(string strFileName);
	virtual inline void buildNextRow(string strRow);
	virtual inline void closeFile();
};


HTMLFileBuilder::HTMLFileBuilder(string strFileName)
: FileBuilder(strFileName.append(".html"))
{
	FileBuilder::buildNextRow("<HTML>\n<BODY>\n");
}


void HTMLFileBuilder::buildNextRow(string strRow)
{
	FileBuilder::buildNextRow(strRow.append("<br>\n"));
}


void HTMLFileBuilder::closeFile()
{
	FileBuilder::buildNextRow("</BODY>\n</HTML>");
	FileBuilder::closeFile();
}


#endif