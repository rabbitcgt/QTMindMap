#pragma once
#include "Composite.h"
#include "ConstString.h"

class Node :
    public Composite
{
    public:
        Node(int, string);
        Node(int);
        ~Node();
        void addParent(Component*);
        void addSibling(Component*);
        void setParent(Component*);
        bool isParent(Component*);
        Component* getParent();
        Component* clone();
        void calculatePos(int&, int, MindMapSceneAdapter*, string);
        void setChildrenXPoint(int, bool);
        void accept(ComponentVisitor*);
        void up(Component*);
        void down(Component*);
        bool isUpComonent(Component*);
        bool isUnderComonent(Component*);
};

