#pragma once
#include "State.h"

class EightPuzzleState : public State
{
public:
	EightPuzzleState(string state) : State(state) {};
	~EightPuzzleState() {};

	double calculateCost(State& targetState){}//TO-DO COST calculation
};

