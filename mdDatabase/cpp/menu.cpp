#include "menu.h"

// Constructor
Menu::Menu()
{
	// Sets to default state.
	iMenuState = SymptomSelectDefault;

	// Allow multi-select for default
	bMultiSelect = true;

	// This is where you would add new symptoms. Kinda spaghetti but I'm too lazy to improve this.
	m_cSymptomList["Contageous"] = false;
	m_cSymptomList["Coughing"] = false;
	m_cSymptomList["Inhibited movement"] = false;
	m_cSymptomList["Decelerating movement"] = false;
	m_cSymptomList["Headache"] = false;
	m_cSymptomList["Bleeding"] = false;
	m_cSymptomList["Health loss"] = false;
	m_cSymptomList["Permanent nausea"] = false;
	m_cSymptomList["Temporary neausea and Vomiting"] = false;
	m_cSymptomList["Breathlessness"] = false;
	m_cSymptomList["Shivering"] = false;
	m_cSymptomList["Stomach ache"] = false;
	m_cSymptomList["Rash"] = false;
	m_cSymptomList["Blurry vision"] = false;
	m_cSymptomList["Sweating"] = false;
	m_cSymptomList["Audible heartbeat"] = false;
	m_cSymptomList["Inverted controls"] = false;
	m_cSymptomList["Lime green skin"] = false;
	m_cSymptomList["Bleached white skin"] = false;
	m_cSymptomList["Slashing sound upon initial infection"] = false;
	m_cSymptomList["Hair loss"] = false;
	m_cSymptomList["Instantaneous death"] = false;

	// Default option list is symptom selector
	m_optionsList = m_cSymptomList;

	// Titles for different menu states
	m_cMenuTitles[SymptomSelectDefault] = "Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";
	m_cMenuTitles[SymptomSelectInvalid] = "Invalid input. Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";
	m_cMenuTitles[SymptomSelectReset] = "Symptoms deselected. Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";

	///////////// spaghetti below

	/*iLayer = 1;

	sAskSymptomsTitle = "Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";

	v_sSymptomList.push_back("Contageous");
	v_sSymptomList.push_back("Coughing");
	v_sSymptomList.push_back("Inhibited movement");
	v_sSymptomList.push_back("Headache");
	v_sSymptomList.push_back("Bleeding");
	v_sSymptomList.push_back("Health loss");
	v_sSymptomList.push_back("Permanant nausea");
	v_sSymptomList.push_back("Temporary nausea and vomiting");
	v_sSymptomList.push_back("Breathlessness");
	v_sSymptomList.push_back("Shivering");
	v_sSymptomList.push_back("Stomach ache");
	v_sSymptomList.push_back("Rash");
	v_sSymptomList.push_back("Stomach ache");
	v_sSymptomList.push_back("Blurry vision");
	v_sSymptomList.push_back("Sweating");
	v_sSymptomList.push_back("Audible heartbeat");
	v_sSymptomList.push_back("Inverted controls");
	v_sSymptomList.push_back("Shaking head");
	v_sSymptomList.push_back("Lime green skin");
	v_sSymptomList.push_back("Bleached white skin");
	v_sSymptomList.push_back("Slashing sound upon infection");
	v_sSymptomList.push_back("Hair loss");
	v_sSymptomList.push_back("Instantaneous death");

	v_sEditableSymptomList = v_sSymptomList;

	for (int i = 0; i < v_sEditableSymptomList.size(); i++)
	{
		v_bSelectedSymptoms.push_back(false);
	}*/

}

void Menu::displayTitle()
{
	std::cout << m_cMenuTitles.find(SymptomSelectDefault)->second
	<< std::endl
	<< std::endl;
}

void Menu::displayOptions()
{
	for (int i = 0; i < m_optionsList.size(); i++)
	{
		//std::cout << (i + 1) << ": " << m_optionsList[i] << std::endl;
	}

	int iCount = 0;

	for (auto it = m_optionsList.begin(); it != m_optionsList.end(); ++it)
	{
		iCount++;
		std::cout << (iCount) << ": " << it->first << std::endl;
	}

	std::cout << std::endl;
}

// Processes what the user input
bool Menu::processInput(std::string sInput)
{
	if ((iMenuState >= SymptomSelectDefault) && (iMenuState <= SymptomSelectReset))
	{
		// Checks if input wants to confirm selection
		if (sInput == "done")
		{
			iMenuState = SymptomSelectDefault;

			// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING
			resetOptions();

			// Valid input
			return true;
		}

		// Checks if input intends to reset
		else if (sInput == "reset")
		{
			iMenuState = SymptomSelectReset;

			// Resets to default
			resetOptions();

			// Valid input
			return true;
		}

		// Checks if input is an integer within the range
		else
		{
			for (int i = 0; i < sInput.length(); i++)
			{
				// If any components of the string are not integers
				if (!isdigit(sInput[i]))
				{
					iMenuState = SymptomSelectInvalid;

					// Invalid input
					return false;
				}
			}

			// Check if it is within the range of possible symptoms, if not, input is invalid.
			if ((std::stoi(sInput) < 1) || (std::stoi(sInput) > m_optionsList.size()))
			{
				iMenuState = SymptomSelectInvalid;

				return false;
			}

			else
			{
				iMenuState = SymptomSelectSelected;

				return true;
			}
		}
	}
}

void Menu::resetOptions()
{
	// For resetting symptom selection menu
	if ((iMenuState >= SymptomSelectDefault) && (iMenuState <= SymptomSelectReset))
	{
		// Sets to reset state.
		iMenuState = SymptomSelectReset;

		// Changes options to default
		m_optionsList = m_cSymptomList;
	}
}

void Menu::selectOption()
{
	if (!bMultiSelect)
	{
		resetOptions();
	}

	v_sEditableSymptomList[iValidInput] = "[" + v_sEditableSymptomList[iValidInput] + "]";

}

/*

int Menu::getLayer()
{
	return iLayer;
}

void Menu::displayMatchingDiseases()
{

}

*/