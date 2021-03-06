#pragma once
#include "Component.h"
class Decorator : public Component
{
    public:
        Decorator(int);
        Decorator();
        ~Decorator();
        void addDecorator(Component*);
        void addChild(Component*);
        void addParent(Component*);
        void addSibling(Component*);
        void clearNodeList();
        void deleteNodeByNode(Component*);
        void display(stringstream&, string, bool = true);
        void setParent(Component*);
        bool isParent(Component*);
        void addChilds(list<Component*>);
        Component* getParent();
        list<Component*> getNodeList();
        void calculatePos(int&, int, MindMapSceneAdapter*, string);
        void setChildrenYPoint(int);
        void setChildrenXPoint(int, bool);
        Component* getDecorator();
        bool isDecorator();
        void changeNodeByNode(Component*, Component*);
        void up(Component*);
        void down(Component*);
        bool isUpComonent(Component*);
        bool isUnderComonent(Component*);
        string getSide();
    protected:
        Component* _child;
        Component* _parent;
};

