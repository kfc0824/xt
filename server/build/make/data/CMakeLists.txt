LINK_LIBRARIES(mysqlclient)
LINK_LIBRARIES(mongoc-1.0)
LINK_LIBRARIES(bson-1.0)
LINK_LIBRARIES(hiredis)

FILE(GLOB CPP "${SRC}/data/*.cpp")
ADD_EXECUTABLE(data ${CPP})
