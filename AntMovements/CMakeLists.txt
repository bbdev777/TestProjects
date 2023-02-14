cmake_minimum_required(VERSION 3.5)

project(AntMovements)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)
#find_package(Boost REQUIRED COMPONENTS system filesystem log program_options)


add_executable(AntMovements
	"./main.cpp"
	"./src/AntMovements.cpp")

target_include_directories(AntMovements
	PUBLIC
		${IncludeRoot}
	PRIVATE
		${CMAKE_CURRENT_BINARY_DIR}
)


target_link_libraries(AntMovements
)

