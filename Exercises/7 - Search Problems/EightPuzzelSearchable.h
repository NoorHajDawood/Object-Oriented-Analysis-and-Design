#pragma once
#include "Searchable.h"
#include "EightPuzzel.h"

class EightPuzzelSearchable : public Searchable
{
public:
	EightPuzzelSearchable(EightPuzzel& puzzel): m_puzzel(puzzel){}

public:
	//ADD implementation for those methodes
	virtual State& getStartState() { }//return m_puzzel.getStart(); };
	//virtual State<string>& getStartState() { m_puzzel.getStart(); };

	virtual State& getGoalState() { }//return m_puzzel.getEnd(); };
	//virtual State<string>& getGoalState() { m_puzzel.getEnd(); };

	virtual std::vector<State> getAllPossibleStates(State& s) {/*m_puzzel.calculateStates()*/};
	//virtual std::vector<State<string>> getAllPossibleStates(State& s) {/*m_puzzel.calculateStates()*/ };

private:
	EightPuzzel m_puzzel;
};