include_directories(..)

set(bencodeTests    IntegerTest
                    StringTest
                    ListTest
                    KeyValuePairTest
                    DictionaryTest
                    ParserTest
                    ConvertToBencodeTest)

foreach(testName ${bencodeTests})
    string(TOLOWER ${testName} filename)
    set(filename ${filename}.cpp)
    set(testName Bencode${testName})
    add_executable(${testName} ${filename})
    target_link_libraries(${testName} bencode)
    add_test(${testName} ${testName})
endforeach()
