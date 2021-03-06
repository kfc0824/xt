#ifndef _COMMON_CORE_UTIL_H_
#define _COMMON_CORE_UTIL_H_

#include "core.h"

class CUtil
{
public:
    static bool StartupAsDaemon();
    static bool SleepMillisecond(uint ms);
    static bool SleepSecond(uint s) { return SleepMillisecond(s * 1000); }
    static uint GetIpInt(const string &ip);
    static uint ToInt(const string &value);
    static string GetIpString(uint ip);
    static string ToString(uint value);
    static StringList SplitString(const string &strBase, const string &strSpliter);
    static UIntList SplitInt(const string &strBase, const string &strSpliter);
    static void MergeList(S2UIntList &list, const S2UIntList &added);
    static void MergeList(S3UIntList &list, const S3UIntList &added);
    static void Trim(string &strBase);
    static void Replace(string &strBase, const string &strOld, const string &strNew);
    static void ReplaceAllSpace(string &strBase) { Replace(strBase, " ", ""); }

    // random
    static uint Rand(uint min, uint max);
    static uint Rand(uint value) { return Rand(0, value); }
    static uint RandIndex(UIntList probs, uint size);
    static bool RandMany(UIntList& listResult, uint min, uint max, uint count, bool isDiff);

private:
    CUtil();
    ~CUtil();
};

#endif
