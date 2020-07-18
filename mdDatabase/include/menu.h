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
	std::map<int, std::string> m_cSymptomList;

	// Vectors of symptoms for different diseases
	std::vector<int> viShiveringSymptoms;
	std::vector<int> viInjurySymptoms;
	std::vector<int> viNauseaSymptoms;

	// Map of diseases, technically constant. Edited by developer.
	std::map<int, Disease*> m_cDiseaseList;

	// Map of current options, changes visually if something is selected
	std::map<int, std::string> m_optionsList;

	// Map of selected options
	std::map<int, std::string> m_selectedOptionsList;

	// Map of selected symptoms for when checking against diseases
	std::map<int, std::string> m_selectedSymptomsList;

	// Map of menu titles for different states.
	std::map<int, std::string> m_cMenuTitles;

	// map of 1025 page number + disease name
	// seperate disease classes, compare selected symptom map with disease's individual symptom map

	// Enum for state of menu.
	const enum eMenuStates
	{SymptomSelectDefault = 1, SymptomSelectSelected = 2, SymptomSelectInvalid = 3, SymptomSelectReset = 4,
	DiseaseSelectDefault = 5, DiseaseSelectSelected = 6, DiseaseSelectInvalid = 7, DiseaseSelectReset = 8,
	DisplayInfo = 9};

	// Current menu state.
	int iMenuState;

	// Does this menu allow multiple selections?
	bool bMultiSelect;
public:
	Menu();

	void displayTitle();
	void displayOptions();
	void resetOptions();
	bool processInput(std::string sInput);
	void selectOption(int iInput);
};