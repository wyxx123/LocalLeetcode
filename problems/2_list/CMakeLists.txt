add_executable(remove_linked_list_elements 1_remove_linked_list_elements.cpp)
target_link_libraries(remove_linked_list_elements 
    PRIVATE 
    leetcode_common  # 继承公共包含路径
    gtest::gtest)