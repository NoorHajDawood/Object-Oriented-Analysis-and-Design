#pragma once

#include <string>
#include <memory>
using namespace std;

//template <class T>
class State
{
public:
	State(string state): m_state(state), m_cost(0), m_cameFrom(nullptr){}
	~State() {};

public:
	bool operator == (State& s) { return m_state.compare(s.m_state) == 0; }

private:
	string				m_state;
	//T					m_state;
	double				m_cost;
	unique_ptr<State>	m_cameFrom;
};

