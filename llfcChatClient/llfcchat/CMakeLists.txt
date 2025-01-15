cmake_minimum_required(VERSION 3.5)

project(llfcchat LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)      # 如果 ChatView.h 在 src 目录中
if(ANDROID)
  add_library(llfcchat SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
  add_executable(llfcchat
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    adduseritem.cpp
    adduseritem.h
    adduseritem.ui
    applyfriend.cpp
    applyfriend.h
    applyfriend.ui
    applyfrienditem.cpp
    applyfrienditem.h
    applyfrienditem.ui
    applyfriendlist.cpp
    applyfriendlist.h
    applyfriendpage.cpp
    applyfriendpage.h
    applyfriendpage.ui
    authenfriend.cpp
    authenfriend.h
    authenfriend.ui
    BubbleFrame.cpp
    BubbleFrame.h
    chatdialog.cpp
    chatdialog.h
    chatdialog.ui
    ChatItemBase.cpp
    ChatItemBase.h
    chatpage.cpp
    chatpage.h
    chatpage.ui
    chatuserlist.cpp
    chatuserlist.h
    chatuserwid.cpp
    chatuserwid.h
    chatuserwid.ui
    ChatView.cpp
    ChatView.h
    clickedbtn.cpp
    clickedbtn.h
    clickedlabel.cpp
    clickedlabel.h
    clickedoncelabel.cpp
    clickedoncelabel.h
    contactuserlist.cpp
    contactuserlist.h
    conuseritem.cpp
    conuseritem.h
    conuseritem.ui
    customizeedit.cpp
    customizeedit.h
    customizetextedit.h
    customizetextedit.cpp
    findfaildlg.cpp
    findfaildlg.h
    findfaildlg.ui
    findsuccessdlg.h
    findsuccessdlg.cpp
    findsuccessdlg.ui
    friendinfopage.cpp
    friendinfopage.h
    friendinfopage.ui
    friendlabel.cpp
    friendlabel.h
    friendlabel.ui
    global.cpp
    global.h
    grouptipitem.cpp
    grouptipitem.h
    grouptipitem.ui
    httpmgr.cpp
    httpmgr.h
    invaliditem.h
    invaliditem.cpp
    lineitem.cpp
    lineitem.h
    lineitem.ui
    listitembase.cpp
    listitembase.h
    loadingdlg.cpp
    loadingdlg.h
    loadingdlg.ui
    logindialog.cpp
    logindialog.h
    logindialog.ui
    MessageTextEdit.cpp
    MessageTextEdit.h
    PictureBubble.cpp
    PictureBubble.h
    registerdialog.h
    registerdialog.cpp
    registerdialog.ui
    resetdialog.cpp
    resetdialog.h
    resetdialog.ui
    searchlist.cpp
    searchlist.h
    singleton.h
    statelabel.cpp
    statelabel.h
    statewidget.cpp
    statewidget.h
    tcpmgr.cpp
    tcpmgr.h
    TextBubble.h
    TextBubble.cpp
    timerbtn.cpp
    timerbtn.h
    userdata.cpp
    userdata.h
    usermgr.cpp
    usermgr.h
  )
endif()

target_link_libraries(llfcchat PRIVATE Qt5::Widgets Qt5::Network)
