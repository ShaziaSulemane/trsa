execute_process(COMMAND "/home/shazia/trsa_ws/build/vision_opencv/cv_bridge/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/shazia/trsa_ws/build/vision_opencv/cv_bridge/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
