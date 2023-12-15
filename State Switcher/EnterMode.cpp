#include "stdafx.h"
#include "EnterMode.h"

EnterMode::EnterMode()
{
}


EnterMode::~EnterMode()
{
}


void EnterMode::ParseLine(const ArgScript::Line& line)
{
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
	auto args = line.GetArguments(1); //get arguments
	auto modemanager = App::IGameModeManager::Get();

	if (line.HasFlag("hexString")) {
		modemanager->SetActiveMode(std::strtol(args[0], nullptr, 16));
	}
	else {
		modemanager->SetActiveModeByName(args[0]);
	}

	return;
}

const char* EnterMode::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat lets you enter any mode, using only names found in animations~/SporeAppStates.trigger";
	}
	else {
		return "\n"
			"This cheat lets you enter any mode, using only names found in animations~/SporeAppStates.trigger\n"
			"This command does not support aliases and does not check if the state is valid. \n"
			"\n"
			"Use the '-hexString' flag to make the command accept a state id (eg. '022d9e01') instead of a state name.\n";
	}
}