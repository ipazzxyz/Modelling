qt_add_executable(Modelling
    main.cpp
    app.cpp app.hpp
    gamewindow.cpp gamewindow.hpp gamewindow.ui
    setupform.cpp setupform.hpp setupform.ui
    buyform.cpp buyform.hpp buyform.ui
    sellform.cpp sellform.hpp sellform.ui
    depositform.cpp depositform.hpp depositform.ui
    iterateform.cpp iterateform.hpp iterateform.ui
)
target_link_libraries(Modelling PRIVATE
    ModellingLogic
    Qt::Core
    Qt::Gui
    Qt::Widgets
)
set_target_properties(Modelling PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
