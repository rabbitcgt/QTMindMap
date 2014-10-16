#include "CommandManager.h"
#include "ConstString.h"

CommandManager::CommandManager()
{
}

CommandManager::~CommandManager()
{
}

void CommandManager::execute(Command* command)
{
    command->execute();
    _undoCommand.push(command);
    while (!_redoCommand.empty())
    {
        delete _redoCommand.top();
        _redoCommand.pop();
    }
}

void CommandManager::redo()
{
    if (_redoCommand.empty() == true)
    {
        throw ERROR_REDO;
    }
    Command* command = _redoCommand.top();
    command->execute();
    _undoCommand.push(command);
    _redoCommand.pop();
}

void CommandManager::undo()
{
    if (_undoCommand.empty() == true)
    {
        throw ERROR_UNDO;
    }
    Command* command = _undoCommand.top();
    command->unexcute();
    _redoCommand.push(command);
    _undoCommand.pop();
}

void CommandManager::clearAllCommand()   //�M���Ҧ�Command
{
    while (!_redoCommand.empty())
    {
        delete _redoCommand.top();
        _redoCommand.pop();
    }
    while (!_undoCommand.empty())
    {
        Command* command = _undoCommand.top();
        command->deleteCommand();
        delete command;
        _undoCommand.pop();
    }
}