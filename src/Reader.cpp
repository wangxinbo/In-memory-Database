#include "Reader.hpp"

Reader::Reader(std::shared_ptr<Database> inDb): db(inDb) {}

void Reader::run(std::string& inCmd)
{
    std::stringstream buffer(inCmd);
    if(isPrefix(inCmd, "SET"))
    {
        std::string cmd, key, value;
        buffer >> cmd >> key >> value;
        if(value != "") execute(std::shared_ptr<Command>(new CmdSet(key, value)));
    }
    else if(isPrefix(inCmd, "UNSET"))
    {
        std::string cmd, key;
        buffer >> cmd >> key;
        execute(std::shared_ptr<Command>(new CmdUnset(key)));
    }
    else if(isPrefix(inCmd, "GET"))
    {
        std::string cmd, key;
        buffer >> cmd >> key;
        execute(std::shared_ptr<Command>(new CmdGet(key)));
    }
    else if(isPrefix(inCmd, "NUMEQUALTO"))
    {
        std::string cmd, value;
        buffer >> cmd >> value;
        execute(std::shared_ptr<Command>(new CmdNumEqualTo(value)));
    }
    else if(isPrefix(inCmd, "BEGIN"))
        execute(std::shared_ptr<Command>(new CmdBegin()));
    else if(isPrefix(inCmd, "ROLLBACK"))
        execute(std::shared_ptr<Command>(new CmdRollback()));
    else if(isPrefix(inCmd, "COMMIT"))
        execute(std::shared_ptr<Command>(new CmdCommit()));
    else if(isPrefix(inCmd, "END"))
        execute(std::shared_ptr<Command>(new CmdEnd()));
}

void Reader::execute(std::shared_ptr<Command> cmd)
{
    if(cmd->name() == Command::CMD_SET || cmd->name() == Command::CMD_UNSET)
    {
        cmd->execute(db);
        if(!this->tranStk.empty())
        {
            std::shared_ptr<Transaction> tran = this->tranStk.top();
            tran->record(cmd);
        }
        return;
    }
    else if(cmd->name() == Command::CMD_GET || cmd->name() == Command::CMD_NUMEQUALTO)
    {
        cmd->execute(db);
        return;
    }
    else if(cmd->name() == Command::CMD_BEGIN)
    {
        cmd->execute(db);
        std::shared_ptr<Transaction> tran(new Transaction(db));
        this->tranStk.push(tran);
        return;
    }
    else if(cmd->name() == Command::CMD_ROLLBACK)
    {
        cmd->execute(db);
        if(this->tranStk.empty())
            Printer::getInstance().print("> NO TRANSACTION");
        else
        {
            std::shared_ptr<Transaction> tran = this->tranStk.top();
            this->tranStk.pop();
            tran->rollback();
        }
        return;
    }
    else if(cmd->name() == Command::CMD_COMMIT)
    {
        cmd->execute(db);
        if(this->tranStk.empty())
            Printer::getInstance().print("> NO TRANSACTION");
        while(!this->tranStk.empty())
            this->tranStk.pop();
        return;
    }
    else if(cmd->name() == Command::CMD_END)
    {
        cmd->execute(db);
        return;
    }
    
}

bool Reader::isPrefix(const std::string &haystack, const std::string &needle)
{
    return haystack.substr(0, needle.size()) == needle;
}
