#include <unity.h>
#include <driver/can.h>
#include <unistd.h>

#include "can.h"

extern int parse_message_format(can_message_t *msg, const char *fmt);

void test_parse_message(void)
{
    can_message_t msg = { 0 };
    TEST_ASSERT_EQUAL(parse_message_format(&msg, "1e2#a512"), 0);
    TEST_ASSERT_EQUAL(0, msg.flags); 
    TEST_ASSERT_EQUAL(0x1e2, msg.identifier); 
    TEST_ASSERT_EQUAL(2, msg.data_length_code); 
    TEST_ASSERT_EQUAL(0xa5, msg.data[0]); 
    TEST_ASSERT_EQUAL(0x12, msg.data[1]); 
}

void test_parse_message_remote(void)
{
    can_message_t msg = { 0 };
    TEST_ASSERT_EQUAL(parse_message_format(&msg, "1e2#R"), 0);
    TEST_ASSERT_EQUAL(CAN_MSG_FLAG_RTR, msg.flags); 
    TEST_ASSERT_EQUAL(0x1e2, msg.identifier); 
    TEST_ASSERT_EQUAL(0, msg.data_length_code); 
}

void test_transmit(void)
{
    can_message_t msg = { 0 };
    TEST_ASSERT_EQUAL(0, can_init());

    TEST_ASSERT_EQUAL(0, parse_message_format(&msg, "1e2#R"));
    TEST_ASSERT_EQUAL(ESP_OK, can_transmit(&msg, 0)); 
}

void app_main() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    sleep(2);

    UNITY_BEGIN();
    RUN_TEST(test_parse_message);
    RUN_TEST(test_parse_message_remote);
    RUN_TEST(test_transmit);
    UNITY_END();
}