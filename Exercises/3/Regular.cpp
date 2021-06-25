#include "Regular.h"

/*----------------------------------------------------------------------------*/
istream& Regular::read(istream& in)
{
	Participant::read(in);
	return in >> m_viewSharedScreen;
}
/*----------------------------------------------------------------------------*/
ostream& Regular::write(ostream& out)
{
	out << 'R' << std::endl;
	Participant::write(out);
	return out << m_viewSharedScreen << std::endl;
}