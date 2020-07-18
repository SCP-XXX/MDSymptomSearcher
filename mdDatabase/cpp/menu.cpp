#include "menu.h"

// Constructor
Menu::Menu()
{
	// This is where you would add new symptoms. Kinda spaghetti but I'm too lazy to improve this.
	m_cSymptomList[1] = "Contageous";
	m_cSymptomList[2] = "Coughing";
	m_cSymptomList[3] = "Inhibited movement";
	m_cSymptomList[4] = "Decelerating movement";
	m_cSymptomList[5] = "Headache";
	m_cSymptomList[6] = "Bleeding";
	m_cSymptomList[7] = "Health loss";
	m_cSymptomList[8] = "Long-lasting nausea";
	m_cSymptomList[9] = "Temporary nausea and Vomiting";
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

	// This is where you would add new diseases (int is the 1025 page number). More spaghetti yay, im too noob to be bothered to improve this :)
	// Shivering
	/*m_SymptomMap2[11] = "Shivering";
	Disease oShivering(m_SymptomMap1);
	m_cDiseaseList[1] = oShivering;

	// Injury
	m_SymptomMap2[3] = "Inhibited movement";
	m_SymptomMap1[6] = "Bleeding";
	m_SymptomMap1[14] = "Blurry vision";
	Disease oInjury;
	m_cDiseaseList[2] = oInjury;

	// Injury
	m_SymptomMap3[8] = "Long-lasting nausea";
	Disease oNausea;
	m_cDiseaseList[3] = oNausea;*/

	viShiveringSymptoms = { 11 };
	m_cDiseaseList.insert(std::make_pair(1, new Disease(m_cSymptomList, "Shivering", viShiveringSymptoms)));

	viInjurySymptoms = { 3, 6, 14 };
	m_cDiseaseList.insert(std::make_pair(2, new Disease(m_cSymptomList, "Injury", viInjurySymptoms)));

	viNauseaSymptoms = { 8 };
	m_cDiseaseList.insert(std::make_pair(3, new Disease(m_cSymptomList, "Nausea", viNauseaSymptoms)));

	// This is where you would add new diseases.
	//m_cDiseasesList.insert(std::make_pair(1, new Disease));
	//m_cDiseaseList[1] = Disease oShivering;

	// Default option list is symptom selector
	m_optionsList = m_cSymptomList;

	// Titles for different menu states
	m_cMenuTitles[SymptomSelectDefault] = "Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";
	m_cMenuTitles[SymptomSelectSelected] = "Symptom selected. Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";
	m_cMenuTitles[SymptomSelectInvalid] = "Invalid input. Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";
	m_cMenuTitles[SymptomSelectReset] = "Symptoms deselected. Input a number to choose a symptom, input 'done' once you have listed all of them, or input 'reset' to deselect all symptoms.";

	m_cMenuTitles[DiseaseSelectDefault] = "Input a number to choose a disease with the symptoms you listed. Input 'done' once you have listed all of them, or input 'reset' to deselect all options. Input 'back' to return.";
	m_cMenuTitles[DiseaseSelectSelected] = "Disease selected. Input a number to choose an option, input 'done' once you have listed all of them, or input 'reset' to deselect all options. Input 'back' to return.";
	m_cMenuTitles[DiseaseSelectInvalid] = "Invalid input. Input a number to choose an option, input 'done' once you have listed all of them, or input 'reset' to deselect all options. Input 'back' to return.";
	m_cMenuTitles[DiseaseSelectReset] = "Diseases deselected. Input a number to choose an option, input 'done' once you have listed all of them, or input 'reset' to deselect all options. Input 'back' to return.";

	m_cMenuTitles[DisplayInfo] = "Disease info displayed. Input 'back' to return.";

	// Sets to default state.
	iMenuState = SymptomSelectDefault;

	// Allow multi-select for default
	bMultiSelect = true;
}

void Menu::displayTitle()
{
	std::cout << m_cMenuTitles.find(iMenuState)->second
	<< std::endl
	<< std::endl;
}

void Menu::displayOptions()
{
	if (iMenuState != DisplayInfo)
	{
		system("pause");
		for (int i = 1; i <= m_optionsList.size(); i++)
		{
			system("pause");
			// If selected, give visual representation of selection
			auto it = m_selectedOptionsList.find(i);
			if (it != m_selectedOptionsList.end())
			{
				system("pause");
				std::cout << i << ": " << "[" << m_optionsList.find(i)->second << "]" << std::endl;
			}

			else
			{
				system("pause");
				std::cout << i << ": " << m_optionsList.find(i)->second << std::endl;
			}
		}
		system("pause");
	}

	else
	{
		for (int i = 1; i <= m_optionsList.size(); i++)
		{
			// If selected, give visual representation of selection
			auto it = m_selectedOptionsList.find(i);
			if (it != m_selectedOptionsList.end())
			{
				
				std::cout << m_cDiseaseList.find(i)->second->getName() << std::endl << std::endl;
				m_cDiseaseList.find(i)->second->printSymptoms();
			}
		}
	}

	std::cout << std::endl;
}

// Processes what the user input
bool Menu::processInput(std::string sInput)
{
	if ((iMenuState >= SymptomSelectDefault) && (iMenuState <= SymptomSelectReset))
	{
		// Symptom list should allow multi select
		bMultiSelect = true;

		// Checks if input wants to confirm selection
		if (sInput == "done")
		{
			iMenuState = DiseaseSelectDefault;

			m_selectedSymptomsList = m_selectedOptionsList;

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
		// Disease list shouldn't allow multi select
		bMultiSelect = false;

		// Checks if input wants to confirm selection
		if (sInput == "done")
		{
			iMenuState = DisplayInfo;

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

		// Checks if input intends to return to symptoms
		else if (sInput == "back")
		{
			iMenuState = SymptomSelectDefault;

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

	else if (iMenuState == DisplayInfo)
	{
		// Checks if input intends to return to disease list
		if (sInput == "back")
		{
		iMenuState = DiseaseSelectDefault;

		// Valid input
		return true;
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
		m_selectedOptionsList = {};
	}

	// For resetting disease selection menu
	if ((iMenuState >= DiseaseSelectDefault) && (iMenuState <= DiseaseSelectReset))
	{
		m_optionsList = {};

		/*for (auto elem : m_selectedSymptomsList)
		{
			std::cout << elem.first << " " << elem.second << "\n";
		}*/

		// Changes options to default
		for (int i = 1; i <= m_cDiseaseList.size(); i++)
		{
			if (m_cDiseaseList.find(i)->second->compareSymptoms(m_selectedSymptomsList))
			{
				m_optionsList[i] = m_cDiseaseList.find(i)->second->getName();
			}
		}
		m_selectedOptionsList = {};
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