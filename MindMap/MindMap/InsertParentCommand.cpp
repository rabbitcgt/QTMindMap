#include "InsertParentCommand.h"

InsertParentCommand::InsertParentCommand(Component* component, Component* parent, MindMapModel* model)
{
    _component = component->getDecorator();
    _newParent = parent;
    _oldParent = _component->getParent();
    _model = model;
}

InsertParentCommand::~InsertParentCommand()
{
    if (_newParent != NULL)
    {
        _newParent->clearNodeList();
    }
    delete _newParent;
}

void InsertParentCommand::execute()
{
    _component->addParent(_newParent);
    _model->doInsertNode(_newParent);
}

void InsertParentCommand::unexcute()
{
    _oldParent->deleteNodeByNode(_newParent);
    _oldParent->addChild(_component);
    _model->doUninsertNode(_newParent);
}