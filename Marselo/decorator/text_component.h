#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H


#include "decorator.h"


class TextComponent : public Component
{
public:
	inline TextComponent(string strInit);
	inline virtual void show(ofstream& out);

private:
	string str;
};


TextComponent::TextComponent(string strInit)
: str(strInit)
{}


void TextComponent::show(ofstream& out)
{
	out << str.data();	
}


#endif