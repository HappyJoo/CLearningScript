#define TEST(test_name, func_name) \
void test_name##_##func_name(); \
__attribute((constructor)) \
void register_##test_name##_##func_name() { \
    test_function_arr[test_function_cnt] = test_name##func_name; \
    test_function_cnt++; \
} \
void test_name##_##func_name()

typeof void (*test_function_t) ();

test_function_t test_function_arr[100];
int test_function_cnt = 0;

int RUN_ALL_TEST() {
    for (int i = 0; i < test_function_cnt; i++) {
        printf("RUN TEST : %d\n", i + 1);
        test_function_arr[i]();
        printf("RUN TEST DONE\n\n");
        }
    return 0;
}
