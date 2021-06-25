#include "ZoomMeeting.h"
#include "Host.h"
#include "Regular.h"

/*----------------------------------------------------------------------------*/
ZoomMeeting::ZoomMeeting(
	const string &name,
	const string &date,
	const string &startTime,
	const string &endTime,
	const string &id,
	int numOfParticipants,
	Participant **participants)
	: m_name(name),
	  m_date(date),
	  m_startTime(startTime),
	  m_endTime(endTime),
	  m_Id(id),
	  m_numOfParticipants(numOfParticipants)
{
	if (numOfParticipants > 0)
		m_participants.reserve(numOfParticipants);
	for (int i = 0; i < numOfParticipants; i++)
	{
		m_participants.push_back(std::shared_ptr<Participant>(participants[i]));
	}
}
/*----------------------------------------------------------------------------*/
void ZoomMeeting::cleanParticipants()
{
	m_participants.clear();
}
/*----------------------------------------------------------------------------*/
ZoomMeeting::~ZoomMeeting()
{
	cleanParticipants();
}
/*----------------------------------------------------------------------------*/
void ZoomMeeting::read(istream &in)
{
	cleanParticipants();
	in >> m_name >> m_date >> m_startTime >> m_endTime >> m_Id >> m_numOfParticipants;
	if (m_numOfParticipants > 0)
		m_participants.reserve(m_numOfParticipants);
	for (int i = 0; i < m_numOfParticipants; i++)
	{
		m_participants.push_back(std::shared_ptr<Participant>(readParticipant(in)));
	}
}
/*----------------------------------------------------------------------------*/
Participant *ZoomMeeting::readParticipant(istream &in)
{
	char c;
	in >> c;
	Participant *p = 0;
	if (c == 'H')
		p = new Host();
	else if (c == 'R')
		p = new Regular();
	else
		throw invalid_argument("no participant of this kind");
	p->read(in);
	return p;
}
/*----------------------------------------------------------------------------*/
void ZoomMeeting::write(ostream &out) const
{
	out << m_name << std::endl << m_date << std::endl << m_startTime << std::endl << m_endTime << std::endl << m_Id << std::endl << m_numOfParticipants << std::endl;
	for (auto p : m_participants)
	{
		p->write(out);
	}
}
/*----------------------------------------------------------------------------*/
istream &operator>>(istream &in, ZoomMeeting &zoomMeeting)
{
	zoomMeeting.read(in);
	return in;
}
/*----------------------------------------------------------------------------*/
ostream &operator<<(ostream &out, const ZoomMeeting &zoomMeeting)
{
	zoomMeeting.write(out);
	return out;
}
/*----------------------------------------------------------------------------*/