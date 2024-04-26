/*************************************************
* ADS Praktikum 1.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"

RingNode::RingNode(){};
RingNode::RingNode(int age, std::string description, std::string data):
    m_oldAge(age), m_description(description), m_symbolicData(data),m_next(nullptr){};

int RingNode::getOldAge(){return this->m_oldAge;}
void RingNode::setOldAge(int age){this->m_oldAge = age;};

std::string RingNode::getDescription(){return this->m_description;};
void RingNode::setDescription(std::string description){this->m_description = description;};

std::string RingNode::getSymbolicData(){return this->m_symbolicData;};
void RingNode::setSymbolicData(std::string data){this->m_symbolicData = data;};

RingNode* RingNode::getNext(){return this->m_next;};
void RingNode::setNext(RingNode* node){this->m_next = node;};

std::string RingNode::print(){
    return "OldAge: " + std::to_string(this->m_oldAge) + " Description: " + this->m_description + " Data: " + this->m_symbolicData + "\n";
}