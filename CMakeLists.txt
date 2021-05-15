cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Structures/ResultsByRow/ResultsByRow.cpp Structures/ResultsByRow/ResultsByRow.h OperationsOnStructures/Trees/SortOperations.h StreamHandliing/Streams.h StreamHandliing/Streams.cpp OperationsOnStructures/Trees/SortOperations.cpp Structures/Trees/BinaryTree/BinaryTree.cpp Structures/Trees/BinaryTree/BinaryTree.h Structures/Trees/AvlTree/AvlTree.cpp Structures/Trees/AvlTree/AvlTree.h)