#ifndef __REF_PTR_TEST_H__
#define __REF_PTR_TEST_H__

#include <string>                       // for string
#include "CCPlatformMacros.h"           // for CREATE_FUNC
#include "UnitTest.h"                   // for UnitTestDemo

class RefPtrTest : public UnitTestDemo
{
public:
    
    CREATE_FUNC(RefPtrTest);
    
    virtual void onEnter() override;
    
    virtual std::string subtitle() const override;
};

#endif /* __REF_PTR_TEST_H__ */
