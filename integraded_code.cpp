#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <memory>

//using namespace std;

class Printer {
public:
    static Printer& getInstance() {
        static Printer printer;
        return printer;
    }

    template <typename T>
    void print(const T& value) {
        std::cout << value << std::endl;
    }
    
private:
    Printer() {}
    Printer(const Printer& printer);
    Printer& operator=(const Printer& printer);
};

/**
 * This class provides the underlying data structure and methods that manipulate the data for the in-memory database.
 * The key-value store is implemented using an unordered_map, so the Set(), Get(), Unset() methods have O(1) average-case
 * time complexity. To effectively retrieve the number of key-value pairs equal to a given value, another unordered_map
 * is used, so the NumEqualTo() method also has average-case time complexity O(1).
 */
class Database
{
public:
    enum
    {
        DB_GOOD,
        DB_NOT_FOUND,
        DB_ERROR
    };
    
    Database() {} // Default constructor.
    
    int dbSet(const std::string& key, const std::string& value) // Set a key-value pair in the database.
    {
        decOldValue(key);
        this->keyToValue[key] = value;
        this->valueToCount[value]++;
        return DB_GOOD;
    }
    
    int dbUnset(const std::string& key) // Erase a key-value pair with given key.
    {
        if(decOldValue(key) == DB_NOT_FOUND)
            return DB_NOT_FOUND;
        this->keyToValue.erase(key);
        return DB_GOOD;
    }
    
    int dbGet(const std::string& key, std::string& value) // Get a value associated a given key.
    {
        auto iter = this->keyToValue.find(key);
        if(iter == this->keyToValue.end())
            return DB_NOT_FOUND;
        value = iter->second;
        return DB_GOOD;
    }
    
    int dbNumEqualTo(const std::string& value, int& count) // Get the number of entries that has a specific value.
    {
        count = 0;
        auto iter = this->valueToCount.find(value);
        if(iter == this->valueToCount.end())
            return DB_NOT_FOUND;
        else
        {
            count = this->valueToCount[value];
            return DB_GOOD;
        }
    }
    
private:
    std::unordered_map<std::string, std::string> keyToValue; // A map that stores key-value pairs from input.
    std::unordered_map<std::string, int> valueToCount; // A map that stores the count of entries in keyToValue with a specific value.
    
    int decOldValue(const std::string& key) // Decrease the value-count by one, if the count is 0, delete the value.
    {
        auto iter = this->keyToValue.find(key);
        if(iter != this->keyToValue.end())
        {
            this->valueToCount[iter->second]--;
            if(this->valueToCount[iter->second] == 0)
                this->valueToCount.erase(iter->second);
            return DB_GOOD;
        }
        else
            return DB_NOT_FOUND;
    }
};

/**
 * This class provides a structure with abstraction and encapsulation that fit the requirements of an in-memory database.
 * First, an interface, Command, is created on top of all required database commands. Then, each database command inherits this
 * interface, overrides the virtual function defined in the interface, and implements their own logics. Note that for write-method,
 * such as Set() and Unset(), a private member variable is used to record the old value, so that it can be rollbacked when indicated.
 */
class Command
{
public:
    enum
    {
        CMD_SET,
        CMD_UNSET,
        CMD_GET,
        CMD_NUMEQUALTO,
        CMD_BEGIN,
        CMD_COMMIT,
        CMD_ROLLBACK,
        CMD_END
    };
    
    virtual int execute(std::shared_ptr<Database> db) = 0;
    virtual int undo(std::shared_ptr<Database> db) = 0;
    virtual int name() const = 0 ;
    virtual std::string toString() const = 0;
};

class CmdSet: public Command
{
public:
    CmdSet(const std::string& inKey, const std::string& inValue): key(inKey), value(inValue), oldValue("") {}
    
    virtual int name() const {return Command::CMD_SET;}
    
    virtual int execute(std::shared_ptr<Database> db)
    {
        Printer::getInstance().print(toString());
        db->dbGet(key, this->oldValue);
        return db->dbSet(key, value);
    }
    
    virtual int undo(std::shared_ptr<Database> db)
    {
        if(this->oldValue == "")
            return db->dbUnset(key);
        else
            return db->dbSet(key, oldValue);
    }
    
    virtual std::string toString() const
    {
        return "SET " + this->key + " " + this->value;
    }
    
private:
    std::string key;
    std::string value;
    std::string oldValue;
};

class CmdUnset: public Command
{
public:
    CmdUnset(const std::string& inKey): key(inKey), oldValue("") {}
    
    virtual int name() const {return Command::CMD_UNSET;}
    
    virtual int execute(std::shared_ptr<Database> db)
    {
        Printer::getInstance().print(toString());
        db->dbGet(key, oldValue);
        return db->dbUnset(key);
    }
    
    virtual int undo(std::shared_ptr<Database> db)
    {
        if(this->oldValue != "")
            return db->dbSet(key, oldValue);
        else
            return Database::DB_GOOD;
    }
    
    virtual std::string toString() const
    {
        return "UNSET " + this->key;
    }
    
private:
    std::string key;
    std::string oldValue;
};

class CmdGet: public Command
{
public:
    CmdGet(const std::string& inKey): key(inKey) {}
    
    virtual int name() const {return Command::CMD_GET;}
    
    virtual int execute(std::shared_ptr<Database> db)
    {
        Printer::getInstance().print(toString());
        std::string value = "";
        int status = db->dbGet(key, value);
        if(status == Database::DB_NOT_FOUND)
            Printer::getInstance().print("> NULL");
        else
            Printer::getInstance().print("> " + value);
        return status;
    }
    
    virtual int undo(std::shared_ptr<Database> db) {return Database::DB_GOOD;}
    
    virtual std::string toString() const
    {
        return "GET " + this->key;
    }
    
private:
    std::string key;
};

class CmdNumEqualTo: public Command
{
public:
    CmdNumEqualTo(const std::string& inValue): value(inValue) {}
    
    virtual int name() const {return Command::CMD_NUMEQUALTO;}
    
    virtual int execute(std::shared_ptr<Database> db)
    {
        Printer::getInstance().print(toString());
        int count = 0;
        int status = db->dbNumEqualTo(value, count);
        Printer::getInstance().print("> " + std::to_string(count));
        return status;
    }
    
    virtual int undo(std::shared_ptr<Database> db)
    {
        return Database::DB_GOOD;
    }
    
    virtual std::string toString() const
    {
        return "NUMEQUALTO " + this->value;
    }
    
private:
    std::string value;
};

class CmdBegin: public Command
{
public:
    CmdBegin() {}
    
    virtual int name() const {return Command::CMD_BEGIN;}
    
    virtual int execute(std::shared_ptr<Database> db)
    {
        Printer::getInstance().print(toString());
        return Database::DB_GOOD;
    }
    virtual int undo(std::shared_ptr<Database> db) {return Database::DB_GOOD;}
    
    virtual std::string toString() const
    {
        return "BEGIN";
    }
};

class CmdRollback: public Command
{
public:
    CmdRollback() {}
    
    virtual int name() const {return Command::CMD_ROLLBACK;}
    
    virtual int execute(std::shared_ptr<Database> db)
    {
        Printer::getInstance().print(toString());
        return Database::DB_GOOD;
    }
    virtual int undo(std::shared_ptr<Database> db) {return Database::DB_GOOD;}
    
    virtual std::string toString() const
    {
        return "ROLLBACK";
    }
};

class CmdCommit: public Command
{
public:
    CmdCommit() {}
    
    virtual int name() const {return Command::CMD_COMMIT;}
    
    virtual int execute(std::shared_ptr<Database> db)
    {
        Printer::getInstance().print(toString());
        return Database::DB_GOOD;
    }
    
    virtual int undo(std::shared_ptr<Database> db) {return Database::DB_GOOD;}
    
    virtual std::string toString() const
    {
        return "COMMIT";
    }
};

class CmdEnd: public Command
{
public:
    CmdEnd() {}
    
    virtual int name() const {return Command::CMD_END;}
    
    virtual int execute(std::shared_ptr<Database> db)
    {
        Printer::getInstance().print(toString());
        return Database::DB_GOOD;
    }
    
    virtual int undo(std::shared_ptr<Database> db) {return Database::DB_GOOD;}
    
    virtual std::string toString() const
    {
        return "END";
    }
};

class Transaction
{
public:
    Transaction(std::shared_ptr<Database> inDb): db(inDb) {}
    
    void record(std::shared_ptr<Command> cmd)
    {
        this->cmdStk.push(cmd);
        return;
    }
    
    void rollback()
    {
        while(!this->cmdStk.empty())
        {
            std::shared_ptr<Command> cmd = this->cmdStk.top();
            this->cmdStk.pop();
            cmd->undo(this->db);
        }
        return;
    }
    
private:
    std::shared_ptr<Database> db;
    std::stack<std::shared_ptr<Command> > cmdStk;
};

/**
 * This class provides an API, run(), for the database users. It reads a line of command, parses it, and call
 * a private method, execute(), to handle operation required by the input command on the in-memory database.
 * To satisfy the rollback operation of transaction, a FILO stack is used to store all pending transaction that
 * are initiated after the most recent Commit() operation. When a Rollback() command is initiated by user, the
 * most recent transaction, which is on the top of the stack, will be popped from the stack and rollbacked. When
 * a Commit() operation is initiated by user, all transactions in the stack will be popped, without any impact on
 * the underlying in-memory database.
 */
class Reader
{
public:
    Reader(std::shared_ptr<Database> inDb): db(inDb) {}
    
    void run(std::string& inCmd)
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
    
private:
    std::shared_ptr<Database> db;
    std::stack<std::shared_ptr<Transaction> > tranStk;
    
    void execute(std::shared_ptr<Command> cmd)
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
    
    bool isPrefix(const std::string& haystack, const std::string& needle)
    {
        return haystack.substr(0, needle.size()) == needle;
    }
};

int main() {
    std::string line;
    auto db = std::shared_ptr<Database>(new Database());
    Reader reader(db);
    while(true) 
    {
        std::getline(std::cin, line);
        reader.run(line);
        if(line.substr(0, 3) == "END") break;
    }
    return 0;
}
