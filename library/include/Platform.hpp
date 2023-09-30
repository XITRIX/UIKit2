//
// Created by Даниил Виноградов on 27.09.2023.
//

#pragma once

#include <bx/allocator.h>

class Platform {
public:
    static bx::AllocatorI* getDefaultAllocator()
    {
        static bx::DefaultAllocator s_allocator;
        return &s_allocator;
    }
};
