#ifndef COLOR_DECORATOR_H
#define COLOR_DECORATOR_H


class ColorDecorator : public Decorator
{
public:
	inline ColorDecorator(Component& rcInit, string strColorInit);
	virtual void show(ofstream& out);

private:
	string strColor;
};


ColorDecorator::ColorDecorator(Component& rcInit, string strColorInit)
: Decorator(rcInit), strColor(strColorInit)
{}


void ColorDecorator::show(ofstream& out)
{
	out<< "<FONT color=" << strColor.data() << ">";
	
	Decorator::show(out);
	
	out<< "</FONT>";
}


#endif