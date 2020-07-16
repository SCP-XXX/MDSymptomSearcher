#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "disease.h"

class Menu
{
private:
	// Map of symptoms, technically constant. Edited by developer.
	std::map<std::string, bool> m_cSymptomList;//

	// Map of current options, changes depending on menu state
	std::map<std::string, bool> m_optionsList;

	// Map of menu titles for different states.
	std::map<int, std::string> m_cMenuTitles;

	// Enum for state of menu.
	const enum eMenuStates {SymptomSelectDefault = 1, SymptomSelectSelected = 2, SymptomSelectInvalid = 3, SymptomSelectReset = 4};

	// Current menu state.
	int iMenuState;

	// Does this menu allow multiple selections?
	bool bMultiSelect;

	/////////////// spaghetti below
	
	//std::vector<Disease> v_oDiseaseList;
	//std::vector<std::string> v_sSymptomList;
	//std::vector<std::string> v_sEditableSymptomList;
	//std::vector<bool> v_bSelectedSymptoms;
	//std::string sAskSymptomsTitle;
	int iValidInput;
	std::string sValidInput;

	int iLayer;
public:
	Menu();

	void displayTitle();
	void displayOptions();
	void resetOptions();
	bool processInput(std::string sInput);
	void selectOption();

	/////////////// spaghetti below

	void displayMatchingDiseases();
};