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
		m_diseaseSymptoms[i + 1] = m_cGlobalSymptoms.find(viDiseaseSymptoms[i])->second;
		std::cout << m_sDiseaseName << " symptoms: " << m_diseaseSymptoms[i + 1] << std::endl;
	}
}

std::string Disease::getName()
{
	return m_sDiseaseName;
}

void Disease::printSymptoms()
{
	std::cout << "Symptom list: " << std::endl;

	for (int i = 1; i < m_diseaseSymptoms.size(); i++)
	{
		std::cout << i << ": " << m_diseaseSymptoms[i] << std::endl;
	}
}