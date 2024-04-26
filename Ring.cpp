/*************************************************
* ADS Praktikum 1.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

Ring::Ring():m_countNodes(0),m_anker(nullptr){};

void Ring::addNewNode(std::string description, std::string data){

    RingNode* newNode = new RingNode(0,description,data);

    //erstes element ::sollte richtig sein
    if(m_anker == nullptr){
        newNode->setNext(newNode);
        m_anker = newNode;
        m_countNodes++;
    }
    // Ring noch nicht voll :: sollte richtig sein
    else if(m_countNodes != RINGMAXLENGTH){
        addNodeAge();

        newNode->setNext(m_anker->getNext());
        m_anker->setNext(newNode);
        m_countNodes++;
        m_anker = newNode;      
    }
    //Ring voll :: sollte richtig sein
    else{
        addNodeAge();

        newNode->setNext(m_anker->getNext()->getNext());
        delete m_anker->getNext();
        m_anker->setNext(newNode);

        m_anker = newNode;
    }

}

bool Ring::search(std::string data){
    RingNode* current = m_anker;
    for (int i = 0; i < m_countNodes; i++)
    {
        if(current->getSymbolicData() == data){
            return true;
        } 
        else{
         current = current->getNext();
        }
    }
    return false;
}

void Ring::printNode(std::string data){
    RingNode* current = m_anker;
    for (int i = 0; i < m_countNodes; i++)
    {
        if(current->getSymbolicData() == data){
            std::cout << "+Gefunden in Backup: " << current->print() << std::endl;
            return;
        } 
        else{
         current = current->getNext();
        }
    }
    std::cout << "+Datensatz nicht gefunden" << std::endl;
}


void Ring::print(){
    std::string result = "";

    result.append(printHelper(m_anker->getNext()));

    std::cout << result;
}

std::string Ring::printHelper(RingNode* current) {
    std::string out;
    if (current == this->m_anker){
        return ("Alter: "+ std::to_string(current->getOldAge()) 
            + ", Beschreibung: " + current->getDescription() 
            + ", Daten: " + current->getSymbolicData() 
            + "\n");
    }
    else {
        
        out.append(printHelper(current->getNext()));
        out.append("------------- \n");
        out.append("Alter: " + std::to_string(current->getOldAge())
            + ", Beschreibung: " + current->getDescription()
            + ", Daten: " + current->getSymbolicData()
            + "\n");
    }
    return out;

   
}
 
void Ring::addNodeAge(){
    RingNode* current = m_anker;

    for (int i = 0; i < m_countNodes; i++)
    {
        current->setOldAge(current->getOldAge() + 1);
        current = current->getNext();
    }
}