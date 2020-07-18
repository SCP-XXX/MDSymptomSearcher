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

	// Disease specific symptoms WOW SPAGHETTI EW (if i can be bothered ill make this in a less lazy way at some point)
	/*std::map<int, std::string> m_SymptomMap1;
	std::map<int, std::string> m_SymptomMap2;
	std::map<int, std::string> m_SymptomMap3;
	std::map<int, std::string> m_SymptomMap4;
	std::map<int, std::string> m_SymptomMap5;
	std::map<int, std::string> m_SymptomMap6;
	std::map<int, std::string> m_SymptomMap7;
	std::map<int, std::string> m_SymptomMap8;
	std::map<int, std::string> m_SymptomMap9;
	std::map<int, std::string> m_SymptomMap10;
	std::map<int, std::string> m_SymptomMap11;
	std::map<int, std::string> m_SymptomMap12;
	std::map<int, std::string> m_SymptomMap13;
	std::map<int, std::string> m_SymptomMap14;
	std::map<int, std::string> m_SymptomMap15;
	std::map<int, std::string> m_SymptomMap16;
	std::map<int, std::string> m_SymptomMap17;
	std::map<int, std::string> m_SymptomMap18;
	std::map<int, std::string> m_SymptomMap19;
	std::map<int, std::string> m_SymptomMap20;
	std::map<int, std::string> m_SymptomMap21;
	std::map<int, std::string> m_SymptomMap22;
	std::map<int, std::string> m_SymptomMap23;
	std::map<int, std::string> m_SymptomMap24;
	std::map<int, std::string> m_SymptomMap25;
	std::map<int, std::string> m_SymptomMap26;
	std::map<int, std::string> m_SymptomMap27;
	std::map<int, std::string> m_SymptomMap28;
	std::map<int, std::string> m_SymptomMap29;
	std::map<int, std::string> m_SymptomMap30;
	std::map<int, std::string> m_SymptomMap31;
	std::map<int, std::string> m_SymptomMap32;
	std::map<int, std::string> m_SymptomMap33;
	std::map<int, std::string> m_SymptomMap34;
	std::map<int, std::string> m_SymptomMap35;*/

	// Map of diseases, technically constant. Edited by developer.
	std::map<int, Disease*> m_cDiseaseList;

	// Map of current options, changes visually if something is selected
	std::map<int, std::string> m_optionsList;

	// Map of selected options
	std::map<int, std::string> m_selectedOptionsList;

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