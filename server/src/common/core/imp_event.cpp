#include "event.h"
#include "log.h"

CEvent::CEvent()
{
}

CEvent::~CEvent()
{
}

bool CEvent::Register(const std::string &strName, const std::string &strFile, SEventInfo::FunEvent handler)
{
    SEventInfo info(strFile, handler);
    m_handlers[strName].push_back(info);
    return true;
}

void CEvent::Execute(const std::string &strName, SEventBase *event)
{
    IF_NOTFIND(m_handlers, strName, iterMap)
    {
        return;
    }

    std::vector<SEventInfo> &list = iterMap->second;
    for(std::vector<SEventInfo>::iterator iter = list.begin(); iter != list.end(); )
    {
        event->is_delete = false;
        (iter->handler)(event);
        if(event->is_delete)
        {
            LOG_INFO("Remove event(%s)'s one callback [%s]", iterMap->first.c_str(), iter->path.c_str());
            iter = list.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
}
