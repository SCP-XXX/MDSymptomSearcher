#pragma once

#include <vector>
#include "disease.h"

class Disease
{
private:
	std::string sName;
	std::vector<std::string> v_sSymptomList;
	std::vector<std::string> v_sCauseList;
	std::vector<std::string> v_sCureList;
public:
	std::string getName();
	std::string getSymptoms();
	std::string getCauses();
	std::string getCures();
};