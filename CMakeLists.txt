cmake_minimum_required(VERSION 3.16)
project(aks_gui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt6 - fallback to Qt5 if not available
find_package(Qt6 COMPONENTS Widgets Network QUIET)
if(NOT Qt6_FOUND)
    find_package(Qt5 5.15 COMPONENTS Widgets Network REQUIRED)
    set(QT_VERSION_MAJOR 5)
else()
    set(QT_VERSION_MAJOR 6)
endif()

# Source files
set(SOURCES
    main.cpp
    mainwindow.cpp
    missilewidget.cpp
    launcherwidget.cpp
    AksSystem.cpp
    ObjectManager.cpp
    Simulators.cpp
    UdpSocket.cpp
)

set(HEADERS
    mainwindow.h
    missilewidget.h
    launcherwidget.h
    AksSystem.h
    ObjectManager.h
    Simulators.h
    UdpSocket.h
    defs.h
)

set(UI_FILES
    mainwindow.ui
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UI_FILES})

# Link Qt libraries
if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Network)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Network)
endif()

# Windows-specific: Link Winsock
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32)
endif()

# Copy config file to build directory
configure_file(${CMAKE_SOURCE_DIR}/config.txt ${CMAKE_BINARY_DIR}/config.txt COPYONLY)
