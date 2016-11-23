#include "Transaction.hpp"

Transaction::Transaction(std::shared_ptr<Database> inDb): db(inDb) {}

void Transaction::record(std::shared_ptr<Command> cmd)
{
    this->cmdStk.push(cmd);
    return;
}

void Transaction::rollback()
{
    while(!this->cmdStk.empty())
    {
        std::shared_ptr<Command> cmd = this->cmdStk.top();
        this->cmdStk.pop();
        cmd->undo(this->db);
    }
    return;
}
