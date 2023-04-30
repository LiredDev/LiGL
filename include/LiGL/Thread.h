// this was added because mingw doesnt have threads by default
#pragma once
#include <windows.h>
#include <process.h>

class Thread
{
public:
    Thread() : m_handle(NULL), m_id(0) {}
    virtual ~Thread() {}
    bool start()
    {
        m_handle = (HANDLE)_beginthreadex(NULL, 0, Thread::threadProc, (void *)this, 0, &m_id);
        return m_handle != NULL;
    }
    void join()
    {
        if (m_handle != NULL)
        {
            WaitForSingleObject(m_handle, INFINITE);
            CloseHandle(m_handle);
            m_handle = NULL;
            m_id = 0;
        }
    }
    virtual void run() = 0;

private:
    static unsigned int __stdcall threadProc(void *param)
    {
        Thread *pThread = reinterpret_cast<Thread *>(param);
        pThread->run();
        return 0;
    }
    HANDLE m_handle;
    unsigned int m_id;
};