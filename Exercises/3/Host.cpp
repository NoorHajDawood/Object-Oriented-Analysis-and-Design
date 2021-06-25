#include "Host.h"


/*----------------------------------------------------------------------------*/
istream& Host::read(istream& in)
{
	Participant::read(in);
	return in >> m_shareScreen;
}
/*----------------------------------------------------------------------------*/
ostream& Host::write(ostream& out)
{
	out << 'H' << std::endl;
	Participant::write(out);
	return out << m_shareScreen << std::endl;
}