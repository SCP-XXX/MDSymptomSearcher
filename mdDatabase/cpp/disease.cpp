#include "disease.h"

// Default constructor
Disease::Disease()
{

}

Disease::Disease(std::map<int, std::string> m_cGlobalSymptoms, std::string sDiseaseName, std::vector<int> viDiseaseSymptoms)
{
	m_sDiseaseName = sDiseaseName;

	for (int i = 0; i < viDiseaseSymptoms.size(); i++)
	{
		m_diseaseSymptoms[viDiseaseSymptoms[i]] = m_cGlobalSymptoms.find(viDiseaseSymptoms[i])->second;
		//std::cout << m_sDiseaseName << " symptoms: " << m_diseaseSymptoms[i + 1] << std::endl;
	}
}

std::string Disease::getName()
{
	return m_sDiseaseName;
}

void Disease::printSymptoms()
{
	std::cout << "Symptom list: " << std::endl;

	for (int i = 1; i <= m_diseaseSymptoms.size(); i++)
	{
		std::cout << i << ": " << m_diseaseSymptoms[i] << std::endl;
	}
}

std::map<int, std::string> Disease::getSymptoms()
{
	return m_diseaseSymptoms;
}

bool Disease::compareSymptoms(std::map<int, std::string> m_selectedSymptoms)
{
	/*for (int i = 1; i <= m_diseaseSymptoms.size(); i++)
	{
		std::map<int, std::string>::iterator it = m_selectedSymptoms.find(1);
	}*/

	bool bFound1 = false;
	bool bFound2 = false;

	/*std::cout << m_sDiseaseName << "\n";

	for (auto elem : m_diseaseSymptoms)
	{
		std::cout << elem.first << " " << elem.second << "\n";
	}

	std::cout << "\n";

	for (auto elem : m_selectedSymptoms)
	{
		std::cout << elem.first << " " << elem.second << "\n";
	}

	std::cout << "\n";*/

	for (int i = 1; i <= 23; i++)
	{
		// If selected, give visual representation of selection
		auto it = m_diseaseSymptoms.find(i);
		if (it != m_diseaseSymptoms.end())
		{
			//std::cout << m_diseaseSymptoms.find(i)->second << std::endl;
			bFound1 = true;
		}

		auto it2 = m_selectedSymptoms.find(i);
		if (it2 != m_selectedSymptoms.end())
		{
			//std::cout << m_selectedSymptoms.find(i)->second << std::endl;
			bFound2 = true;
		}

		if (bFound1 && bFound2)
		{
			break;
		}

		bFound1 = false;
		bFound2 = false;
	}

	return (bFound1 && bFound2);
	
	
	/*for (int i = 1; i <= 23; i++)
	{
		if (m_diseaseSymptoms[i] != m_selectedSymptoms[i])
		{
			std::cout << m_diseaseSymptoms[i] << " - " << m_selectedSymptoms[i] << std::endl;
			return false;
		}
	}
	
	return true*/
	
	/*bool bFound1 = false;
	bool bFound2 = false;

	for (int i = 1; i <= 30; i++)
	{
		std::cout << i;

		for (int )

		std::map<int, std::string>::iterator it = m_diseaseSymptoms.find(i);
		if (it != m_diseaseSymptoms.end())
		{
			bFound1 = true;
		}

		std::map<int, std::string>::iterator it2 = m_selectedSymptoms.find(i);
		if (it2 != m_selectedSymptoms.end())
		{
			bFound2 = true;
		}

		if (bFound1 && bFound2)
		{
			return true;
		}

		bFound1 = false;
		bFound2 = false;
	}

	system("pause");

	return false;*/
	
	
	/*for (int i = 1; i <= m_cGlobalSymptoms.size(); i++)
	{
		for (int j = 1; j <= m_selectedSymptoms.size(); j++)
		{
			// If selected, give visual representation of selection
			auto it = m_diseaseSymptoms.find(j);
			if (it != m_diseaseSymptoms.end())
			{
				return true;
			}
		}
	}

	system("pause");*/

	//return false;
}