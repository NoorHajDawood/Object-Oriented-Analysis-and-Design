#include <iostream>
using namespace std;

class Button
{
public:
	inline Button (const char * strTextInit);
	inline const char * getText(void) const;
	virtual void show(void) = 0;
	virtual void hide(void) = 0;
	bool isVisible(void) const;
	virtual ~Button(void) = 0;
private:
	char * strText;
	bool   bVisible;
};


Button::Button(const char * strTextInit)
: strText(const_cast<char *>(strTextInit)), bVisible(false)
{}


const char * Button::getText(void) const
{ return strText; }

Button::~Button(void)
{}


void Button::show(void)
{ bVisible = true; }


void Button::hide(void)
{ bVisible = false; }


bool Button::isVisible(void) const
{ return bVisible; }



class TextBox
{
public:
	inline TextBox (const char * strTextInit);
	inline const char * getText(void) const;
	virtual void show(void) = 0;
	virtual void hide(void) = 0;
	bool isVisible(void) const;
	virtual ~TextBox(void) = 0;
private:
	char * strText;
	bool   bVisible;
};


TextBox::TextBox(const char * strTextInit)
: strText(const_cast<char *>(strTextInit)), bVisible(false)
{}


const char * TextBox::getText(void) const
{ return strText; }


TextBox::~TextBox(void)
{}


void TextBox::show(void)
{ bVisible = true; }


void TextBox::hide(void)
{ bVisible = false; }


bool TextBox::isVisible(void) const
{ return bVisible; }



class SystemTextBox : public TextBox
{
public:
	inline SystemTextBox(const char * strTextInit);
	virtual void show(void);
	virtual void hide(void);
};


SystemTextBox::SystemTextBox(const char * strTextInit)
: TextBox(strTextInit)
{}


void SystemTextBox::show(void)
{
	TextBox::show();
	cout << "Drawing a SystemButton" << endl; 
}


void SystemTextBox::hide(void)
{
	TextBox::hide();
	cout << "Hiding a SystemButton" << endl; 
}



class SystemButton : public Button
{
public:
	inline SystemButton(const char * strTextInit);
	virtual void show(void);
	virtual void hide(void);
};


SystemButton::SystemButton(const char * strTextInit)
: Button(strTextInit)
{}


void SystemButton::show(void)
{
	Button::show();
	cout << "Drawing a SystemButton" << endl; 
}


void SystemButton::hide(void)
{
	Button::hide();
	cout << "Hiding a SystemButton" << endl; 
}



class MetalTextBox : public TextBox
{
public:
	inline MetalTextBox(const char * strTextInit);
	virtual void show(void);
	virtual void hide(void);
};


MetalTextBox::MetalTextBox(const char * strTextInit)
	: TextBox(strTextInit)
{}


void MetalTextBox::show(void)
{
	TextBox::show();
	cout << "Drawing a MetalTextBox" << endl; 
}


void MetalTextBox::hide(void)
{
	TextBox::hide();
	cout << "Hiding a MetalTextBox" << endl; 
}



class MetalButton : public Button
{
public:
	inline MetalButton(const char * strTextInit);
	virtual void show(void);
	virtual void hide(void);
};


MetalButton::MetalButton(const char * strTextInit)
: Button(strTextInit)
{}


void MetalButton::show(void)
{
	Button::show();
	cout << "Drawing a MetalButton" << endl; 
}


void MetalButton::hide(void)
{
	Button::hide();
	cout << "Hiding a MetalButton" << endl; 
}



class UIFactory
{
public:
	// All protocol will be pure virutal to be implemented in the subclasses
	virtual Button * createButton(const char *strText) = 0;
	virtual TextBox * createTextBox(const char *strText) = 0;
	virtual ~UIFactory(void) = 0;
};


UIFactory::~UIFactory(void)
{}



class SystemUIFactory : public UIFactory
{
public:
	inline virtual Button * createButton(const char *strText);
	virtual TextBox * createTextBox(const char *strText);
};


TextBox * SystemUIFactory::createTextBox(const char *strText)
{ return new SystemTextBox(strText); }


Button * SystemUIFactory::createButton(const char *strText)
{ return new SystemButton(strText); }



class MetalUIFactory : public UIFactory
{
public:
	inline virtual Button * createButton(const char *strText);
	virtual TextBox * createTextBox(const char *strText);
};


Button * MetalUIFactory::createButton(const char *strText)
{ return new MetalButton(strText); }


TextBox * MetalUIFactory::createTextBox(const char *strText)
{ return new MetalTextBox(strText); }




int main(void)
{
	UIFactory * pUIFactory = new MetalUIFactory();
	Button *pb = pUIFactory->createButton("Ok");
	TextBox *ps = pUIFactory->createTextBox("Ok");

	pb->show();
	ps->show();

	delete pb;
	delete ps;
	delete pUIFactory;
	return 0;
}

/**** output ****
Drawing a MetalButton
Drawing a MetalTextBox
*****************/
