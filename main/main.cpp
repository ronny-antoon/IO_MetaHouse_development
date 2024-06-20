extern "C" {
#include <unity.h>
#include <unity_fixture.h>

#include <ButtonModule.hpp>
#include <RelayModule.hpp>

// Test group setup
TEST_GROUP(ButtonModule_test);
TEST_SETUP(ButtonModule_test) {}
TEST_TEAR_DOWN(ButtonModule_test) {}

TEST(ButtonModule_test, TestButtonModule) { TEST_ASSERT_EQUAL(true, true); }

// Test group runner
TEST_GROUP_RUNNER(ButtonModule_test) { RUN_TEST_CASE(ButtonModule_test, TestButtonModule); }

static void run_all_tests(void) { RUN_TEST_GROUP(ButtonModule_test); }

// Test application main
void app_main(void) {
  UNITY_MAIN_FUNC(run_all_tests);
  // log GitHub CI has been completed
  printf("GitHub CI has been completed\n");
}
}  // extern "C"