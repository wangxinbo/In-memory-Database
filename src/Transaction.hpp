#ifndef Transaction_hpp
#define Transaction_hpp

#include "Command.hpp"
#include "Database.hpp"
#include <stack>

/**
 * This class encapsulates a group of database commands to simulate a SQL-like transaction. The databse commands that
 * belongs to a transaction is stored in a FILO stack. When a transaction is rollbacked, each method is popped out from
 * the stack, and undone one by one. Note that the transaction object contains only commands that modifies the in-memory
 * database, such as Set() and Unset(), so it does not contain any read-only commands, such as Get(), NumEqualTo(). This
 * ensures that each transaction should consume at most O(M) additional memory, where M is the number of variables that
 * are updated within a transaction.
 */
class Transaction
{
public:
    Transaction(std::shared_ptr<Database> inDb);
    
    void record(std::shared_ptr<Command> cmd);
    
    void rollback();
    
private:
    std::shared_ptr<Database> db;
    std::stack<std::shared_ptr<Command> > cmdStk;
};

#endif /* Transaction_hpp */
