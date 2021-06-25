#include "file_selector.h"

int main()
{
	FileSelector fs;
	fs.process(FileSelector::TEXT);
	fs.process(FileSelector::HTML);

	return 0;
}