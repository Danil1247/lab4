#include "gtest.h"
#include "ArrList.h"

TEST(TArrList, can_create_ArrList_with_positive_length)
{
  ASSERT_NO_THROW(TArrList<int> queue(4));
}

TEST(TArrList, cant_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TArrList<int> queue(-1));
}

TEST(TArrList, can_get_size)
{
  TArrList<int> queue(3);

  queue.PushStart(1);

  queue.PushStart(2);

  queue.PushStart(3);

  EXPECT_EQ(3, queue.GetSize());
}

TEST(TArrList, can_create_copied_queue)
{
  TArrList<int> queue(3);

  ASSERT_NO_THROW(TArrList<int> queue1(queue));
}

TEST(TArrList, can_push_item_into_queue)
{
  TArrList<int> queue(4);

  ASSERT_NO_THROW(queue.PushStart(3));
}

TEST(TArrList, can_get_item_from_queue)
{
  TArrList<int> queue(3);
  queue.PushStart(1);
  queue.PushStart(2);
  queue.PushStart(3);
  ASSERT_NO_THROW(queue.GetStart());
}

TEST(TArrList, can_check_for_emptiness)
{
  TArrList<int> queue(4);
  EXPECT_EQ(queue.isEmpty(), true);
}

TEST(TArrList, can_check_for_fullness)
{
  TArrList<int> queue(3);
  queue.PushStart(1);
  queue.PushStart(2);
  queue.PushStart(3);
  EXPECT_EQ(queue.isFull(), true);
}

TEST(TArrList, cant_get_item_from_empty_queue)
{
  TArrList<int> queue(4);
  ASSERT_ANY_THROW(queue.GetStart());
}

TEST(TArrList, cant_push_item_into_full_queue)
{
  TArrList<int> queue(3);
  queue.PushStart(1);
  queue.PushStart(2);
  queue.PushStart(3);
  ASSERT_ANY_THROW(queue.PushStart(5));
}

TEST(TArrList, cant_delete_item_from_empty_queue)
{
  TArrList<int> queue(4);
  ASSERT_ANY_THROW(queue.DelStart());
}