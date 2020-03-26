
#include <stdio.h>
#include <gtest/gtest.h>
// #include "geek_test.h" // 替换掉原 gtest/gtest.h 头文件

// 判断一个数字 x 是否是素数
int is_prime(int x) {
    for (int i = 2; i * i < x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

// 第一个测试用例
TEST(test1, test_is_prime) {
    EXPECT_EQ(is_prime(3), 1);
    EXPECT_EQ(is_prime(5), 1);
    EXPECT_EQ(is_prime(7), 1);
}

// 第二个测试用例
TEST(test2, test_is_prime) {
    EXPECT_EQ(is_prime(4), 0);
    EXPECT_EQ(is_prime(0), 0);
    EXPECT_EQ(is_prime(1), 0);
}

int main() {
    return RUN_ALL_TESTS();
}

/* error message
happyjoo@DESKTOP:~/gitrepository/CLearningScript$ g++ -lgtest -lpthread MyTestFramework/testFramework.cpp 
/tmp/cc6bPtpA.o: In function `test1_test_is_prime_Test::TestBody()':
testFramework.cpp:(.text+0xac): undefined reference to `testing::Message::Message()'
testFramework.cpp:(.text+0xdb): undefined reference to `testing::internal::AssertHelper::AssertHelper(testing::TestPartResult::Type, char const*, int, char const*)'
testFramework.cpp:(.text+0xee): undefined reference to `testing::internal::AssertHelper::operator=(testing::Message const&) const'
testFramework.cpp:(.text+0xfa): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
testFramework.cpp:(.text+0x16a): undefined reference to `testing::Message::Message()'
testFramework.cpp:(.text+0x199): undefined reference to `testing::internal::AssertHelper::AssertHelper(testing::TestPartResult::Type, char const*, int, char const*)'
testFramework.cpp:(.text+0x1ac): undefined reference to `testing::internal::AssertHelper::operator=(testing::Message const&) const'
testFramework.cpp:(.text+0x1b8): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
testFramework.cpp:(.text+0x228): undefined reference to `testing::Message::Message()'
testFramework.cpp:(.text+0x257): undefined reference to `testing::internal::AssertHelper::AssertHelper(testing::TestPartResult::Type, char const*, int, char const*)'
testFramework.cpp:(.text+0x26a): undefined reference to `testing::internal::AssertHelper::operator=(testing::Message const&) const'
testFramework.cpp:(.text+0x276): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
testFramework.cpp:(.text+0x2b6): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
testFramework.cpp:(.text+0x2f2): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
testFramework.cpp:(.text+0x32e): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
/tmp/cc6bPtpA.o: In function `test2_test_is_prime_Test::TestBody()':
testFramework.cpp:(.text+0x3dc): undefined reference to `testing::Message::Message()'
testFramework.cpp:(.text+0x40b): undefined reference to `testing::internal::AssertHelper::AssertHelper(testing::TestPartResult::Type, char const*, int, char const*)'
testFramework.cpp:(.text+0x41e): undefined reference to `testing::internal::AssertHelper::operator=(testing::Message const&) const'
testFramework.cpp:(.text+0x42a): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
testFramework.cpp:(.text+0x49a): undefined reference to `testing::Message::Message()'
testFramework.cpp:(.text+0x4c9): undefined reference to `testing::internal::AssertHelper::AssertHelper(testing::TestPartResult::Type, char const*, int, char const*)'
testFramework.cpp:(.text+0x4dc): undefined reference to `testing::internal::AssertHelper::operator=(testing::Message const&) const'
testFramework.cpp:(.text+0x4e8): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
testFramework.cpp:(.text+0x558): undefined reference to `testing::Message::Message()'
testFramework.cpp:(.text+0x587): undefined reference to `testing::internal::AssertHelper::AssertHelper(testing::TestPartResult::Type, char const*, int, char const*)'
testFramework.cpp:(.text+0x59a): undefined reference to `testing::internal::AssertHelper::operator=(testing::Message const&) const'
testFramework.cpp:(.text+0x5a6): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
testFramework.cpp:(.text+0x5e6): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
testFramework.cpp:(.text+0x622): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
testFramework.cpp:(.text+0x65e): undefined reference to `testing::internal::AssertHelper::~AssertHelper()'
/tmp/cc6bPtpA.o: In function `__static_initialization_and_destruction_0(int, int)':
testFramework.cpp:(.text+0x754): undefined reference to `testing::internal::GetTestTypeId()'
testFramework.cpp:(.text+0x7c2): undefined reference to `testing::internal::MakeAndRegisterTestInfo(char const*, char const*, char const*, char const*, testing::internal::CodeLocation, void const*, void (*)(), void (*)(), testing::internal::TestFactoryBase*)'
testFramework.cpp:(.text+0x833): undefined reference to `testing::internal::GetTestTypeId()'
testFramework.cpp:(.text+0x8a1): undefined reference to `testing::internal::MakeAndRegisterTestInfo(char const*, char const*, char const*, char const*, testing::internal::CodeLocation, void const*, void (*)(), void (*)(), testing::internal::TestFactoryBase*)'
/tmp/cc6bPtpA.o: In function `RUN_ALL_TESTS()':
testFramework.cpp:(.text._Z13RUN_ALL_TESTSv[_Z13RUN_ALL_TESTSv]+0x5): undefined reference to `testing::UnitTest::GetInstance()'
testFramework.cpp:(.text._Z13RUN_ALL_TESTSv[_Z13RUN_ALL_TESTSv]+0xd): undefined reference to `testing::UnitTest::Run()'
/tmp/cc6bPtpA.o: In function `test1_test_is_prime_Test::test1_test_is_prime_Test()':
testFramework.cpp:(.text._ZN24test1_test_is_prime_TestC2Ev[_ZN24test1_test_is_prime_TestC5Ev]+0x14): undefined reference to `testing::Test::Test()'
/tmp/cc6bPtpA.o: In function `test2_test_is_prime_Test::test2_test_is_prime_Test()':
testFramework.cpp:(.text._ZN24test2_test_is_prime_TestC2Ev[_ZN24test2_test_is_prime_TestC5Ev]+0x14): undefined reference to `testing::Test::Test()'
/tmp/cc6bPtpA.o: In function `testing::internal::SuiteApiResolver<testing::Test>::GetSetUpCaseOrSuite(char const*, int)':
testFramework.cpp:(.text._ZN7testing8internal16SuiteApiResolverINS_4TestEE19GetSetUpCaseOrSuiteEPKci[_ZN7testing8internal16SuiteApiResolverINS_4TestEE19GetSetUpCaseOrSuiteEPKci]+0x6d): undefined reference to `testing::internal::IsTrue(bool)'
testFramework.cpp:(.text._ZN7testing8internal16SuiteApiResolverINS_4TestEE19GetSetUpCaseOrSuiteEPKci[_ZN7testing8internal16SuiteApiResolverINS_4TestEE19GetSetUpCaseOrSuiteEPKci]+0x92): undefined reference to `testing::internal::GTestLog::GTestLog(testing::internal::GTestLogSeverity, char const*, int)'
testFramework.cpp:(.text._ZN7testing8internal16SuiteApiResolverINS_4TestEE19GetSetUpCaseOrSuiteEPKci[_ZN7testing8internal16SuiteApiResolverINS_4TestEE19GetSetUpCaseOrSuiteEPKci]+0xf9): undefined reference to `testing::internal::GTestLog::~GTestLog()'
testFramework.cpp:(.text._ZN7testing8internal16SuiteApiResolverINS_4TestEE19GetSetUpCaseOrSuiteEPKci[_ZN7testing8internal16SuiteApiResolverINS_4TestEE19GetSetUpCaseOrSuiteEPKci]+0x12a): undefined reference to `testing::internal::GTestLog::~GTestLog()'
/tmp/cc6bPtpA.o: In function `testing::internal::SuiteApiResolver<testing::Test>::GetTearDownCaseOrSuite(char const*, int)':
testFramework.cpp:(.text._ZN7testing8internal16SuiteApiResolverINS_4TestEE22GetTearDownCaseOrSuiteEPKci[_ZN7testing8internal16SuiteApiResolverINS_4TestEE22GetTearDownCaseOrSuiteEPKci]+0x6d): undefined reference to `testing::internal::IsTrue(bool)'
testFramework.cpp:(.text._ZN7testing8internal16SuiteApiResolverINS_4TestEE22GetTearDownCaseOrSuiteEPKci[_ZN7testing8internal16SuiteApiResolverINS_4TestEE22GetTearDownCaseOrSuiteEPKci]+0x92): undefined reference to `testing::internal::GTestLog::GTestLog(testing::internal::GTestLogSeverity, char const*, int)'
testFramework.cpp:(.text._ZN7testing8internal16SuiteApiResolverINS_4TestEE22GetTearDownCaseOrSuiteEPKci[_ZN7testing8internal16SuiteApiResolverINS_4TestEE22GetTearDownCaseOrSuiteEPKci]+0xf9): undefined reference to `testing::internal::GTestLog::~GTestLog()'
testFramework.cpp:(.text._ZN7testing8internal16SuiteApiResolverINS_4TestEE22GetTearDownCaseOrSuiteEPKci[_ZN7testing8internal16SuiteApiResolverINS_4TestEE22GetTearDownCaseOrSuiteEPKci]+0x12a): undefined reference to `testing::internal::GTestLog::~GTestLog()'
/tmp/cc6bPtpA.o: In function `testing::AssertionResult testing::internal::CmpHelperEQ<int, int>(char const*, char const*, int const&, int const&)':
testFramework.cpp:(.text._ZN7testing8internal11CmpHelperEQIiiEENS_15AssertionResultEPKcS4_RKT_RKT0_[_ZN7testing8internal11CmpHelperEQIiiEENS_15AssertionResultEPKcS4_RKT_RKT0_]+0x43): undefined reference to `testing::AssertionSuccess()'
/tmp/cc6bPtpA.o: In function `testing::AssertionResult testing::internal::CmpHelperEQFailure<int, int>(char const*, char const*, int const&, int const&)':
testFramework.cpp:(.text._ZN7testing8internal18CmpHelperEQFailureIiiEENS_15AssertionResultEPKcS4_RKT_RKT0_[_ZN7testing8internal18CmpHelperEQFailureIiiEENS_15AssertionResultEPKcS4_RKT_RKT0_]+0x87): undefined reference to `testing::internal::EqFailure(char const*, char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, bool)'
/tmp/cc6bPtpA.o:(.data.rel.ro._ZTV24test2_test_is_prime_Test[_ZTV24test2_test_is_prime_Test]+0x20): undefined reference to `testing::Test::SetUp()'
/tmp/cc6bPtpA.o:(.data.rel.ro._ZTV24test2_test_is_prime_Test[_ZTV24test2_test_is_prime_Test]+0x28): undefined reference to `testing::Test::TearDown()'
/tmp/cc6bPtpA.o: In function `test2_test_is_prime_Test::~test2_test_is_prime_Test()':
testFramework.cpp:(.text._ZN24test2_test_is_prime_TestD2Ev[_ZN24test2_test_is_prime_TestD5Ev]+0x22): undefined reference to `testing::Test::~Test()'
/tmp/cc6bPtpA.o:(.data.rel.ro._ZTV24test1_test_is_prime_Test[_ZTV24test1_test_is_prime_Test]+0x20): undefined reference to `testing::Test::SetUp()'
/tmp/cc6bPtpA.o:(.data.rel.ro._ZTV24test1_test_is_prime_Test[_ZTV24test1_test_is_prime_Test]+0x28): undefined reference to `testing::Test::TearDown()'
/tmp/cc6bPtpA.o: In function `test1_test_is_prime_Test::~test1_test_is_prime_Test()':
testFramework.cpp:(.text._ZN24test1_test_is_prime_TestD2Ev[_ZN24test1_test_is_prime_TestD5Ev]+0x22): undefined reference to `testing::Test::~Test()'
/tmp/cc6bPtpA.o:(.data.rel.ro._ZTI24test2_test_is_prime_Test[_ZTI24test2_test_is_prime_Test]+0x10): undefined reference to `typeinfo for testing::Test'
/tmp/cc6bPtpA.o:(.data.rel.ro._ZTI24test1_test_is_prime_Test[_ZTI24test1_test_is_prime_Test]+0x10): undefined reference to `typeinfo for testing::Test'
collect2: error: ld returned 1 exit status
*/