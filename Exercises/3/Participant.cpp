#include "Participant.h"

/*----------------------------------------------------------------------------*/
istream& Participant::read(istream &in)
{
	return in >> m_name >> m_useMic >> m_useCam;
}
/*----------------------------------------------------------------------------*/
ostream& Participant::write(ostream &out)
{
	return out << m_name << std::endl << m_useMic << std::endl << m_useCam << std::endl;
}