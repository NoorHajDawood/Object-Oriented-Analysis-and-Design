#include "text_component.h" 
#include "resize_decorator.h"
#include "color_decorator.h"


int main()
{
	ofstream out("my_file.html", ios::out);

	out << "<HTML>" << endl
		<< "<BODY>" << endl;


	////////////////////
	//// cd1 -> tc1 ////
	////////////////////
	TextComponent  tc1("A line of text");    
	ColorDecorator cd1(tc1, "GREEN");
	cd1.show(out);

	out << "<BR>" << endl;

	
	////////////////////
	//// rd1 -> tc2 ////
	////////////////////
	TextComponent   tc2("Another line of text");
	ResizeDecorator rd1(tc2, true);
	rd1.show(out);

	out << "<BR>" << endl;

	
	//////////////////////////////////
	//// cd2 -> rd2 -> rd1 -> tc2 ////
	//////////////////////////////////
	ResizeDecorator rd2(rd1, true);
	ColorDecorator  cd2(rd2, "RED");
	cd2.show(out);

	out << "<BR>" << endl;
	

	out << "</BODY>" << endl
		<< "</HTML>" << endl;

	out.close();

	return 0;
}