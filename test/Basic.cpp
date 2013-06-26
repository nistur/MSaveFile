#include "MSaveFileImpl.h"
#include "tests.h"

#define TEST_FILENAME "test.sav"

TEST(InitTerminate, Basic, 0,
// init
{},
// cleanup
{},
// test
{
    MSaveFileImpl* save;
    save = (MSaveFileImpl*)MSaveFileImpl::getNew();
    ASSERT(save);
    save->destroy();
},
// data
{})

TEST(GetSetInt, Basic, 0,
// init
{
    m_data.save = (MSaveFileImpl*)MSaveFileImpl::getNew();
},
// cleanup
{
    m_data.save->destroy();
},
// test
{
    m_data.save->setInt("test.path", 99);
    int val = 0;
    m_data.save->getInt("test.path", val);
    ASSERT(val == 99);
},
// data
{
    MSaveFileImpl* save;
})

TEST(GetSetFloat, Basic, 0,
// init
{
    m_data.save = (MSaveFileImpl*)MSaveFileImpl::getNew();
},
// cleanup
{
    m_data.save->destroy();
},
// test
{
    m_data.save->setFloat("test.path", 123.456f);
    float val = 0;
    m_data.save->getFloat("test.path", val);
    ASSERT(val == 123.456f);
},
// data
{
    MSaveFileImpl* save;
})

TEST(GetSetString, Basic, 0,
// init
{
    m_data.save = (MSaveFileImpl*)MSaveFileImpl::getNew();
},
// cleanup
{
    m_data.save->destroy();
},
// test
{
    m_data.save->setString("test.path", "test value");
    char val[256];
    memset(val, 0, 256);
    m_data.save->getString("test.path", val);
    ASSERT(strcmp(val, "test value") == 0);
},
// data
{
    MSaveFileImpl* save;
}) 

TEST(SaveLoad, Basic, 0,
// init
{},
// cleanup
{},
// test
{
    MSaveFileImpl* save = (MSaveFileImpl*)MSaveFileImpl::getNew();
    save->load(TEST_FILENAME, M_SAVE_FILE_MODE_ANY);
    save->setInt("test.path", 99);
    save->destroy();
    save = NULL;

    // try loading the file again
    save = (MSaveFileImpl*)MSaveFileImpl::getNew();
    save->load(TEST_FILENAME, M_SAVE_FILE_MODE_ANY);
    int val = 0;
    save->getInt("test.path", val);
    save->destroy();
    save = NULL;

    ASSERT(val == 99);
},
// data
{})