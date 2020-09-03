#ifndef TRACELEVEL_H
#define TRACELEVEL_H

enum class TraceLevel {CRITICAL = 0, ERR, WARN, INFO, DEBUG, TRACE};

// inline TraceLevel operator ++(TraceLevel &level, int)
// {
//    TraceLevel currentLevel = level;

//    if (TraceLevel::DEBUG < level + 1) 
//    		currentLevel = TraceLevel::DEBUG;
//    else 
//    		currentLevel = static_cast<TraceLevel>(level + 1);

//    return currentLevel;
// }

#endif