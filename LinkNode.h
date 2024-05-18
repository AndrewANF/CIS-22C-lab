#include "Currency.h"

class LinkNode
{
public:
    
    Currency* _data;
    LinkNode* _next;

    LinkNode();
    LinkNode(Currency* data);
    LinkNode(Currency* data, LinkNode* next);
    ~LinkNode();

};

LinkNode::LinkNode(){
    _data = nullptr;
    _next = nullptr;
}
LinkNode::LinkNode(Currency* data){
    _data = data;
    _next = nullptr;
}
LinkNode::LinkNode(Currency* data, LinkNode* next){
    _data = data;
    _next = next;
}


LinkNode::~LinkNode()
{
}
