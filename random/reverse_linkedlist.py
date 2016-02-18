# Iterative
def reverse(linked_list):

    # get head of original list
    head = linked_list

    # get copy of head of original list and nullify the list after it
    reversed_head = copy linked_list # current head
    reversed_head.next = Nil

    # while our current head has a next node
    while head.next != Nil:

        # create a copy of the current head
        cur_node = copy head.next

        # make the copy point at the head of our current reversed list
        cur_node.next = reversed_head

        # make the reversed head list then point at that node (now reversed_head
        #   points at the head of the reversed list)
        reversed_head = cur_node

        # move the head forward
        head = head.next

    return reversed_head

# Recursive
def reverse_r(linked_list):
    if linked_list.next == Nil:
        return linked_list

    cur_head = linked_list # head

    remaining_list = linked_list.next

    new_head = reverse_r(remaining_list)

    new_head.next = cur_head

    return new_head
