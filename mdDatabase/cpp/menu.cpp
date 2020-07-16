#include "menu.h"

// Constructor
Menu::Menu()
{
	// Sets to default state.
	iMenuState = SymptomSelectDefault;

	// Allow multi-select for default
	bMultiSelect = true;

	// This is where you would add new symptoms. Kinda spaghetti but I'm too lazy to improve this.
	m_cSymptomList[1] = "Contageous";
	m_cSymptomList[2] = "Coughing";
	m_cSymptomList[3] = "Inhibited movement";
	m_cSymptomList[4] = "Decelerating movement";
	m_cSymptomList[5] = "Headache";
	m_cSymptomList[6] = "Bleeding";
	m_cSymptomList[7] = "Health loss";
	m_cSymptomList[8] = "Permanent nausea";
	m_cSymptomList[9] = "Temporary neausea and Vomiting";
	m_cSymptomList[10] = "Breathlessness";
	m_cSymptomList[11] = "Shivering";
	m_cSymptomList[12] = "Stomach ache";
	m_cSymptomList[13] = "Rash";
	m_cSymptomList[14] = "Blurry vision";
	m_cSymptomList[15] = "Sweating";
	m_cSymptomList[16] = "Audible heartbeat";
	m_cSymptomList[17] = "Inverted controls";
	m_cSymptomList[18] = "Shaking head";
	m_cSymptomList[19] = "Lime green skin";
	m_cSymptomList[20] = "Bleached white skin";
	m_cSymptomList[21] = "Slashing sound upon initial infection";
	m_cSymptomList[22] = "Hair loss";
	m_cSymptomList[23] = "Instantaneous death";

	// Default option list is symptom selector
	m_optionsList = m_cSymptomList;

	// Titles for different menu states
	m_cMenuTitles[SymptomSelectDefault] = "Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";
	m_cMenuTitles[SymptomSelectSelected] = "Symptom selected. Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";
	m_cMenuTitles[SymptomSelectInvalid] = "Invalid input. Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";
	m_cMenuTitles[SymptomSelectReset] = "Symptoms deselected. Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";
	m_cMenuTitles[SymptomSelectDefault] = "Input a number to choose a disease with the symptoms you listed. Input 'done' once you have listed all of them, or input 'reset' to deselect all options. Input 'back' to return.";
	m_cMenuTitles[SymptomSelectSelected] = "Disease selected. Input a number to choose an option, input 'done' once you have listed all of them, or input 'reset' to deselect all options. Input 'back' to return.";
	m_cMenuTitles[SymptomSelectInvalid] = "Invalid input. Input a number to choose an option, input 'done' once you have listed all of them, or input 'reset' to deselect all options. Input 'back' to return.";
	m_cMenuTitles[SymptomSelectReset] = "Diseases deselected. Input a number to choose an option, input 'done' once you have listed all of them, or input 'reset' to deselect all options. Input 'back' to return.";

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
	std::cout << m_cMenuTitles.find(iMenuState)->second
	<< std::endl
	<< std::endl;
}

void Menu::displayOptions()
{
	for (int i = 1; i <= m_optionsList.size(); i++)
	{
		// If selected, give visual representation of selection
		auto it = m_selectedOptionsList.find(i);
		if (it != m_selectedOptionsList.end())
		{
			std::cout << i << ": " << "[" << m_optionsList.find(i)->second << "]" << std::endl;
		}

		else
		{
			std::cout << i << ": " << m_optionsList.find(i)->second << std::endl;
		}
	}

	/*int iCount = 0;

	for (auto it = m_optionsList.begin(); it != m_optionsList.end(); ++it)
	{
		iCount++;
		std::cout << (iCount) << ": " << it->first << std::endl;
	}*/

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

					// Invalid input (not an integer)
					return false;
				}
			}

			int iTempInput = std::stoi(sInput);

			// Check if it is within the range of possible symptoms, if not, input is invalid.
			if ((iTempInput < 1) || (iTempInput > m_optionsList.size()))
			{
				iMenuState = SymptomSelectInvalid;

				// Invalid input (not in range)
				return false;
			}

			else
			{
				iMenuState = SymptomSelectSelected;

				selectOption(iTempInput);

				return true;
			}
		}
	}

	else if ((iMenuState >= DiseaseSelectDefault) && (iMenuState <= DiseaseSelectReset))
	{
		// Checks if input wants to confirm selection
		if (sInput == "done")
		{
			iMenuState = DiseaseSelectDefault;

			// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING// NEEDS CHANGING
			resetOptions();

			// Valid input
			return true;
		}

		// Checks if input intends to reset
		else if (sInput == "reset")
		{
			iMenuState = DiseaseSelectReset;

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
					iMenuState = DiseaseSelectInvalid;

					// Invalid input (not an integer)
					return false;
				}
			}

			int iTempInput = std::stoi(sInput);

			// Check if it is within the range of possible symptoms, if not, input is invalid.
			if ((iTempInput < 1) || (iTempInput > m_optionsList.size()))
			{
				iMenuState = DiseaseSelectInvalid;

				// Invalid input (not in range)
				return false;
			}

			else
			{
				iMenuState = DiseaseSelectSelected;

				selectOption(iTempInput);

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
		// Changes options to default
		m_optionsList = m_cSymptomList;
	}
}

void Menu::selectOption(int iInput)
{
	if (!bMultiSelect)
	{
		resetOptions();
	}
	
	// Adds selected options to a map
	m_selectedOptionsList.insert(std::pair<int, std::string>(iInput, m_optionsList.find(iInput)->second));
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