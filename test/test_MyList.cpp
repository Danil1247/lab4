#include "gtest.h"
#include "MyList.h"

TEST(TList, can_create_List)
{
  ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_push_item_into_list)
{
  TList<int> list;

  ASSERT_NO_THROW(list.PushStart(3));
}

TEST(TList, can_get_data_from_list)
{
  TList<int> list;

  list.PushStart(3);

  ASSERT_NO_THROW(list.GetStart());
}

TEST(TList, cant_delete_item_from_empty_list)
{
  TList<int> list;
  ASSERT_ANY_THROW(list.DelStart());
}

TEST(TList, can_check_for_emptiness)
{
  TList<int> list;
  EXPECT_EQ(list.IsEmpty(), true);
}

TEST(TList, can_check_for_fullness)
{
  TList<int> list;
  list.PushStart(1);
  list.PushStart(2);
  list.PushStart(3);
  EXPECT_EQ(list.IsFull(), false);
}

TEST(TList, can_get_size)
{
  TList<int> list;

  list.PushStart(1);

  list.PushStart(2);

  list.PushStart(3);

  EXPECT_EQ(3, list.GetSize());
}

TEST(TList, can_create_copied_list)
{
  TList<int> list;

  list.PushStart(3);

  list.PushEnd(4);

  ASSERT_NO_THROW(TList<int> list1(list));
}