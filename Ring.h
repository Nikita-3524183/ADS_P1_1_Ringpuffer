/*************************************************
* ADS Praktikum 1.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .h
#pragma once
#include<string>
#include "catch.h"
#include "RingNode.h"

#define RINGMAXLENGTH 6

class Ring{
	
	private:
		int m_countNodes;
		RingNode* m_anker;

		void addNodeAge();
		std::string printHelper(RingNode* current);
	public:
		Ring();

		void addNewNode(std::string description, std::string data);
		bool search(std::string data);

		void print();
		void printNode(std::string data);

		////////////////////////////////////
		// friend Funktionen müssen unangetastet bleiben! 
		friend RingNode * get_anker(Ring& r);
		friend int get_countNodes(Ring& r);
};
