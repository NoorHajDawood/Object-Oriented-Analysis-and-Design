#ifndef FILE_SELECTOR
#define FILE_SELECTOR


#include "file_director.h"
#include "html_file_builder.h"
#include "text_file_builder.h"


class FileSelector
{
public:
	enum FILE_TYPE {TEXT, HTML};

	inline FileSelector();
	inline ~FileSelector();
	void process(FILE_TYPE ft);

private:
	FileDirector fd;
	TextFileBuilder* ptxtfb; 
	HTMLFileBuilder* phtmlfb;
};


FileSelector::FileSelector()
: ptxtfb (new TextFileBuilder("my_file")), 
  phtmlfb(new HTMLFileBuilder("my_file"))
{}


FileSelector::~FileSelector()
{
	delete ptxtfb;
	delete phtmlfb;
}


void FileSelector::process(FILE_TYPE ft)
{
	switch(ft)
	{
	    case TEXT: fd.setBuilder(ptxtfb);  break;
		case HTML: fd.setBuilder(phtmlfb); break;
	}
		
	fd.construct();
}


#endif