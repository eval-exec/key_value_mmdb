cmake_minimum_required(VERSION 3.13)
project(key_value_mmdb)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(key_value_mmdb

        hash_table.c
        hash_table.h
        key_value_mmdb.c
        ttree.c
        ttree.h
        ttree_defs.h
        ttreebuffer.c
        ttreebuffer.h
        uthash.h
        xlarge.del
        )
