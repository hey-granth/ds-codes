cmake_minimum_required(VERSION 3.30)
project(ds_codes C)

set(CMAKE_C_STANDARD 17)

add_executable(ds_codes sorting/merge_sort.c
        sorting/quick-sort-recursive.c
        sorting/bubble-sort.c
        linked-list/doubly-linked-list.c
        arrays/arrays.c
        arrays/arrya-stack.c
        queue/queue.c)
add_executable(new_target arrays/arrya-stack.c)
