#ifndef TRACELEVEL_H
#define TRACELEVEL_H

enum TraceLevel {CRITICAL = 0, ERROR, WARN, INFO, DEBUG, TRACE};

inline TraceLevel operator ++(TraceLevel &level, int)
{
   TraceLevel currentLevel = level;

   if (DEBUG < level + 1) 
   		currentLevel = DEBUG;
   else 
   		currentLevel = static_cast<TraceLevel>(level + 1);

   return currentLevel;
}

#endif