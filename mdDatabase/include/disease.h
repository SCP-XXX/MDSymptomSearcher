#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "disease.h"

class Disease
{
private:
	std::map<int, std::string> m_diseaseSymptoms;
	std::string m_sDiseaseName;

	/*std::vector<std::string> v_sSymptomList;
	std::vector<std::string> v_sCauseList;
	std::vector<std::string> v_sCureList;*/
public:
	Disease();
	Disease(std::map<int, std::string> m_cGlobalSymptoms, std::string sDiseaseName, std::vector<int> viDiseaseSymptoms);
	std::string getName();
	//std::map<int, std::string> getSymptoms();
	void printSymptoms();
	std::map<int, std::string> getSymptoms();
	bool compareSymptoms(std::map<int, std::string> m_selectedSymptoms);
	/*std::string getSymptoms();
	std::string getCauses();
	std::string getCures();*/
};