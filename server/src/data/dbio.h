#ifndef _DATA_DBIO_H_
#define _DATA_DBIO_H_

#include "common/core/thread.h"
#include "common/core/mutex.h"
#include "common/core/mysql.h"
#include "common/msg/user.h"
#include "module.h"

// CLoader
class CLoader : public CThread
{
public:
    CLoader() { }
    ~CLoader(){ }

    bool Init();
    void Run();
    void Load(SUser *user);
    void GetLoadedList(std::vector<SUser*> &list);

private:
    typedef std::map<uint, SUser*> LoadingMap;
    typedef std::vector<SUser*>    LoadedList;

    LoadingMap mLoadings;
    LoadedList mLoadeds;
    CMutex     mMutexLoading;
    CMutex     mMutexLoaded;
    CMysql     mMysql;
};

// CSaver
class CSaver : public CThread
{
public:
    CSaver() { }
    ~CSaver(){ }

public:
    bool Init();
    void Run();
    void DecodeModule(uint uid, uint module, const SBytes &data);

private:
    void Save(const SUser &user, uint module);

private:
    typedef std::map<uint, bool> DirtyUserMap;

    CMysql       mMysql;
    CMutex       mMutex;
    DirtyUserMap mDirties;
};

// CDBIniter
class CDBIniter
{
public:
    //static bool InitMysql(CMysql &mysql);
};

#endif
