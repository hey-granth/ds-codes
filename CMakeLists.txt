cmake_minimum_required(VERSION 3.30)
project(ds_codes C)

set(CMAKE_C_STANDARD 17)

add_executable(ds_codes sorting/merge_sort.c
        sorting/quick-sort-recursive.c)
