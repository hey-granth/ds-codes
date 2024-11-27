cmake_minimum_required(VERSION 3.30)
project(ds_codes C)

set(CMAKE_C_STANDARD 17)

add_executable(ds_codes sorting/merge_sort.c
        sorting/quick-sort-recursive.c
        sorting/bubble-sort.c
        linked-list/doubly-linked-list.c
        arrays/arrays.c
        arrays/array-stack.c
        queue/queue.c
        queue/deque.c
        queue/priority-queue.c
        linked-list/circular-linked-list.c
        linked-list/single-linked-list.c
        linked-list/cycle-linked-list.c
        linked-list/addition-of-polynomials.c
        linked-list/linked-list.c
        linked-list/reverse-linked-list.c
        sorting/quick-sort-iterative.c
        searching/binary-recursive.c
        searching/index-sequential.c
        searching/linear.c
        searching/binary-iterative.c
        premitive-op.c
        queue/queue-using-linked-list.c
        arrays/postfix.c
        arrays/paranthesis-balancing.c
        arrays/tower-of-hanoi.c
        queue/circular-queue.c)
add_executable(new_target arrays/array-stack.c)
