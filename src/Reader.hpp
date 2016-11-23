#ifndef Reader_hpp
#define Reader_hpp

#include "Command.hpp"
#include "Database.hpp"
#include "Transaction.hpp"
#include "Printer.hpp"
#include <stack>
#include <sstream>

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
    Reader(std::shared_ptr<Database> inDb);
    
    void run(std::string& inCmd);
    
private:
    std::shared_ptr<Database> db;
    std::stack<std::shared_ptr<Transaction> > tranStk;
    
    void execute(std::shared_ptr<Command> cmd);
    bool isPrefix(const std::string& haystack, const std::string& needle);
};

#endif /* Reader_hpp */
