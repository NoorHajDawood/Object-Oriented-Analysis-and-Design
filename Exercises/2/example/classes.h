#pragma once

#include <String>

using namespace std;

struct Pos
{
	Pos(int x, int y) { x = x; y = y; }
	Pos move(int dx, int dy) 
	{ 
		x += dx;
		y += dy;
		return *this;
	}

	float x, y;
};

class Person
{
public:
	Person(string name, Pos p, bool infected = false) 
		: 
		m_name(name), 
		m_pos(p), 
		m_isCovidInfected( infected)
	{
	}

	float x() const { return m_pos.x; }
	float y() const { return m_pos.y; }
	string name() const { return m_name; }
	bool infected() const { return m_isCovidInfected; }

private:
	Pos		m_pos;
	string	m_name = "";
	bool	m_isCovidInfected = false;
};


class Police
{
public:
	Police(Pos p)
		:
		m_pos(p),
		m_ticketCounter(0)
	{
	}

	void writeTicket() { ++m_ticketCounter; }
	float x() const { return m_pos.x; }
	float y() const { return m_pos.y; }
	int tickets() const { return m_ticketCounter; }
private:
	Pos		m_pos;
	int		m_ticketCounter;
};



