include_directories(..)

set(tests   IntegerTest
            StringTest
            ListTest)

foreach(testName ${tests})
    string(TOLOWER ${testName} filename)
    set(filename ${filename}.cpp)
    set(testName Bencode${testName})
    add_executable(${testName} ${filename})
    target_link_libraries(${testName} bencode)
    add_test(${testName} ${testName})
endforeach()