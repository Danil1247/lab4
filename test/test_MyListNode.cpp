#include "gtest.h"
#include "MyListNode.h"


TEST(TListNode, can_create_ListNode)
{
  ASSERT_NO_THROW(TListNode<int> list);
}

TEST(TListNode, can_create_ListNode_with_data)
{
  ASSERT_NO_THROW(TListNode<int> list(4));
}

TEST(TListNode, can_create_copied_list)
{
  TListNode<int> list(3);

  ASSERT_NO_THROW(TListNode<int> list1(list));
}

TEST(TListNode, can_get_data_from_list)
{
  TListNode<int> list(3);

  ASSERT_NO_THROW(list.GetData());
}

TEST(TListNode, can_set_data_to_list)
{
  TListNode<int> list;

  list.SetData(3);

  EXPECT_EQ(3, list.GetData());
}