#pragma once
#include "Currency.h"

class LinkNode
{
public:
	LinkNode() : _data(nullptr), _next(nullptr) {};
	LinkNode(Currency* data) : _data(data), _next(nullptr) {};
	LinkNode(Currency* data, LinkNode* next) : _data(data), _next(next) {};
	~LinkNode() { delete _data; }

	// private: // I wonder if the node needs private data + getter & setter?
	Currency* _data;
	LinkNode* _next;
};