#ifndef ECCommand_h
#define ECCommand_h

#include <vector>

// ******************************************************
// Implement command design pattern

class ECCommand
{
public:
    virtual ~ECCommand() {}
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
};

// ******************************************************
// Implement command history

class ECCommandHistory
{
public:
    ECCommandHistory() : posCurrCmd(-1), posCheckpoint(-1) {} ;
    virtual ~ECCommandHistory();
    bool Undo();
    bool Redo();
    void ExecuteCmd( ECCommand *pCmd );
    void AddCheckpoint(int x);
    
private:
    std::vector<ECCommand *> listCommands;
    int posCurrCmd;
    std::vector<int> checkpoints;
    int posCheckpoint;
};


#endif /* ECCommand_h */
