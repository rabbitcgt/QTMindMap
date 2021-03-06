#pragma once
#include "Command.h"
#include "MindMapModel.h"

class DeleteComponentCommand : public Command
{
    public:
        DeleteComponentCommand(Component*, MindMapModel*);
        ~DeleteComponentCommand();
        void execute();
        void unexcute();
    private:
        Component* _component;
        Component* _parent;
        Component* _decorator;
        MindMapModel* _model;
        list<Component*> _oldNodeList;
        list<Component*> _oldChildList;
        list<Component*> _oldParentList;
};

