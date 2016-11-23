#ifndef Database_hpp
#define Database_hpp

#include <string>
#include <unordered_map>

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
    
    Database() {}; // Default constructor.
    int dbSet(const std::string& key, const std::string& value); // Set a key-value pair in the database.
    int dbUnset(const std::string& key); // Erase a key-value pair with given key.
    
    int dbGet(const std::string& key, std::string& value); // Get a value associated a given key.
    int dbNumEqualTo(const std::string& value, int& count); // Get the number of entries that has a specific value.
    
private:
    std::unordered_map<std::string, std::string> keyToValue; // A map that stores key-value pairs from input.
    std::unordered_map<std::string, int> valueToCount; // A map that stores the count of entries in keyToValue with a specific value.
    
    int decOldValue(const std::string& key); // Decrease the value-count by one, if the count is 0, delete the value.
};

#endif /* Database_hpp */
