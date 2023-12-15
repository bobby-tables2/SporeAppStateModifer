#include "stdafx.h"
#include "EnterState.h"

EnterState::EnterState()
{
}


EnterState::~EnterState()
{
}


void EnterState::ParseLine(const ArgScript::Line& line)
{
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
	auto args = line.GetArguments(1); //get arguments
	auto statemanager = App::IStateManager::Get();

	if (line.HasFlag("currentStateName")) {
		App::ConsolePrintF(statemanager->CurrentStateName());
	}
	else if (line.HasFlag("hexString")) {
		statemanager->SwitchToState(std::strtol(args[0], nullptr, 16));
	}
	else {
		statemanager->SwitchToState(statemanager->StateIDFromName(args[0]));
	}
	
	return;
}

const char* EnterState::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat lets you enter any state, using only names found in animations~/SporeAppStates.trigger";
	}
	else {
		return "\n"
			"This cheat lets you enter any state, using only names found in animations~/SporeAppStates.trigger\n"
			"This command does not support aliases and does not check if the state is valid. \n"
			"\n"
			"Use the '-currentStateName' flag to print the name of the current state, and makes the command ignore the first argument.\n"
			"Use the '-hexString' flag to make the command accept a state id (eg. '022d9e01') instead of a state name.\n";
	}
}