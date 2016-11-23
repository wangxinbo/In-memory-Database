#ifndef Command_hpp
#define Command_hpp

#include "Database.hpp"
#include "Printer.hpp"
#include <string>

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

#endif
