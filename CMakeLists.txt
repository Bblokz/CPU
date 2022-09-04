cmake_minimum_required(VERSION 3.20)
project(Project)

set(CMAKE_CXX_STANDARD 14, alu.cc, alu.h, arch.h, config-file.cc, config-file.h, elf.h, elf-file.cc, elf-file.h,
        framebuffer.cc, framebuffer.h, inst-decoder.cc, inst-decoder.h, inst-formatter.cc, main.cc, main.cpp, memory.cc,
        memory.h, memory-bus.cc, memory-bus.h, memory-control.cc, memory-control.h, memory-interface.h, mux.h,
        processor.cc, processor.h, reg-file.h, serial.cc, serial.h, stages.cc, stages.h, sys-status.cc, sys-status.h,
        testing.cc, testing.h)

add_executable(Project main.cc)
