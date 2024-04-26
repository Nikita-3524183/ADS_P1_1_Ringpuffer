/*************************************************
* ADS Praktikum 1.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>


class RingNode{
	
private:
	int m_oldAge;
	std::string m_description, m_symbolicData;
	RingNode* m_next;

public:
	RingNode();
	RingNode(int age, std::string description, std::string data);

	int getOldAge();
	void setOldAge(int age);

	std::string getDescription();
	void setDescription(std::string description);

	std::string getSymbolicData();
	void setSymbolicData(std::string data);

	RingNode* getNext();
	void setNext(RingNode* node);

	std::string print();
};
