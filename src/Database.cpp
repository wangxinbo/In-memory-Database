#include "Database.hpp"

int Database::dbSet(const std::string& key, const std::string& value)
{
    decOldValue(key);
    this->keyToValue[key] = value;
    this->valueToCount[value]++;
    return DB_GOOD;
}

int Database::dbUnset(const std::string& key)
{
    if(decOldValue(key) == DB_NOT_FOUND)
        return DB_NOT_FOUND;
    this->keyToValue.erase(key);
    return DB_GOOD;
}

int Database::dbGet(const std::string& key, std::string& value)
{
    auto iter = this->keyToValue.find(key);
    if(iter == this->keyToValue.end())
        return DB_NOT_FOUND;
    value = iter->second;
    return DB_GOOD;
}

int Database::dbNumEqualTo(const std::string& value, int& count)
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

int Database::decOldValue(const std::string& key)
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
