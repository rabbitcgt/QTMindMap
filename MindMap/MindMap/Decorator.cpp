#include "Decorator.h"
#include "MindMapSceneAdapter.h"

Decorator::Decorator(int id)
{
    _id = id;
    _parent = NULL;
    _child = NULL;
    setPoint(0, 0);
    _type = "Decorator";
}

Decorator::~Decorator()
{
}

void Decorator::changeNodeByNode(Component* component, Component* decorator)
{
    _parent->changeNodeByNode(this, decorator);
}

void Decorator::addDecorator(Component* decorator)
{
    if (_parent != NULL)
    {
        _parent->changeNodeByNode(this, decorator);
    }
    decorator->addChild(this);
}

void Decorator::addChild(Component* child)
{
    _child = child;
    if (child != NULL)
    {
        _child->setParent(this);
    }
}

void Decorator::addParent(Component* parent)
{
    _parent->deleteNodeByNode(this);
    _parent->addChild(parent);
    parent->addChild(this);
}

void Decorator::addSibling(Component* sibling)
{
    _parent->addChild(sibling);
}

void Decorator::clearNodeList()
{
    _child->clearNodeList();
}

void Decorator::deleteNodeByNode(Component* component)
{
    _parent->deleteNodeByNode(this);
}

void Decorator::display(stringstream& outputStream, string levelString, bool last)
{
    _child->display(outputStream, levelString, last);
}

void Decorator::setParent(Component* parent)
{
    _parent = parent;
}

bool Decorator::isParent(Component* parent)
{
    return _parent->isParent(_parent);
}

void Decorator::addChilds(list<Component*> childs)
{
    _child->addChilds(childs);
}

Component* Decorator::getParent()
{
    return _parent;
}

list<Component*> Decorator::getNodeList()
{
    list<Component*> child;
    child.push_back(_child);
    return child;
}

void Decorator::calculatePos(int& position, int level, MindMapSceneAdapter* scene, string side)
{
    int CHANGE_AMOUNT = 5;
    int ADD_AMOUNT = 10;
    level += CHANGE_AMOUNT;
    position += CHANGE_AMOUNT;
    _child->calculatePos(position, level, scene, side);
    position += CHANGE_AMOUNT;
    if (side == "Left")
    {
        setChildrenXPoint(-CHANGE_AMOUNT, true);
    }
    else
    {
        setChildrenXPoint(CHANGE_AMOUNT, true);
    }
    setPoint(_child->getPoint()[0] - CHANGE_AMOUNT, _child->getPoint()[1] - CHANGE_AMOUNT);
    _height = _child->getHeight() + ADD_AMOUNT;
    _width = _child->getWidth() + ADD_AMOUNT;
}

void Decorator::setChildrenYPoint(int height)
{
    _point[1] += height;
    _child->setChildrenYPoint(height);
}

void Decorator::setChildrenXPoint(int x, bool firstNode)
{
    if (firstNode == false)
    {
        _point[0] += x;
    }
    _child->setChildrenXPoint(x, firstNode);
}

Component* Decorator::getDecorator()
{
    if (_parent != NULL && _parent->isDecorator())
    {
        return _parent->getDecorator();
    }
    else
    {
        return this;
    }
}

bool Decorator::isDecorator()
{
    return true;
}

void Decorator::up(Component* component)
{
}

void Decorator::down(Component* component)
{
}

bool Decorator::isUpComonent(Component* component)
{
    return false;
}

bool Decorator::isUnderComonent(Component* component)
{
    return false;
}

string Decorator::getSide()
{
    return _child->getSide();
}