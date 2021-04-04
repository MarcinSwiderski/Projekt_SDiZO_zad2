cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Structures/Stack/Stack.cpp Structures/Stack/Stack.h Structures/Queue/Queue.cpp Structures/Queue/Queue.h Structures/List/List.cpp Structures/List/List.h Structures/ResultsByRow/ResultsByRow.cpp Structures/ResultsByRow/ResultsByRow.h OperationsOnStructures/List/ListOperations.h OperationsOnStructures/Array/ArraysOperations.h OperationsOnStructures/Queue/QueueOperations.h OperationsOnStructures/Stack/StackOperations.h StreamHandliing/Streams.cpp StreamHandliing/Streams.h OperationsOnStructures/Array/ArraysOperations.cpp OperationsOnStructures/List/ListOperations.cpp OperationsOnStructures/Queue/QueueOperations.cpp OperationsOnStructures/Stack/StackOperations.cpp)