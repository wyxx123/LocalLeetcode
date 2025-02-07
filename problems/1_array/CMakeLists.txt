add_executable(binary_search 1_binary_search.cpp)
target_link_libraries(binary_search 
    PRIVATE 
    leetcode_common  # 继承公共包含路径
    gtest::gtest)

add_executable(remove_element 2_remove_element.cpp)
target_link_libraries(remove_element 
    PRIVATE 
    leetcode_common  # 继承公共包含路径
    gtest::gtest)

add_executable(squares_of_a_sorted_array 3_squares_of_a_sorted_array.cpp)
target_link_libraries(squares_of_a_sorted_array
    PRIVATE 
    leetcode_common  # 继承公共包含路径
    gtest::gtest)

add_executable(minimum_size_subarray_sum 4_minimum_size_subarray_sum.cpp)
target_link_libraries(minimum_size_subarray_sum
    PRIVATE 
    leetcode_common  # 继承公共包含路径
    gtest::gtest)

add_executable(spiral_matrix 5_spiral_matrix.cpp)
target_link_libraries(spiral_matrix
    PRIVATE 
    leetcode_common  # 继承公共包含路径
    gtest::gtest)

add_executable(binary_search_test 7_binary_search_test.cpp)
target_link_libraries(binary_search_test
    PRIVATE 
    leetcode_common  # 继承公共包含路径
    gtest::gtest)