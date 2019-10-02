# CMake generated Testfile for 
# Source directory: /home/shazia/trsa_ws/src/vision_opencv/cv_bridge/test
# Build directory: /home/shazia/trsa_ws/build/vision_opencv/cv_bridge/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_cv_bridge_gtest_cv_bridge-utest "/home/shazia/trsa_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/shazia/trsa_ws/build/test_results/cv_bridge/gtest-cv_bridge-utest.xml" "--return-code" "/home/shazia/trsa_ws/devel/lib/cv_bridge/cv_bridge-utest --gtest_output=xml:/home/shazia/trsa_ws/build/test_results/cv_bridge/gtest-cv_bridge-utest.xml")
add_test(_ctest_cv_bridge_nosetests_enumerants.py "/home/shazia/trsa_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/shazia/trsa_ws/build/test_results/cv_bridge/nosetests-enumerants.py.xml" "--return-code" "\"/usr/bin/cmake\" -E make_directory /home/shazia/trsa_ws/build/test_results/cv_bridge" "/usr/bin/nosetests-2.7 -P --process-timeout=60 /home/shazia/trsa_ws/src/vision_opencv/cv_bridge/test/enumerants.py --with-xunit --xunit-file=/home/shazia/trsa_ws/build/test_results/cv_bridge/nosetests-enumerants.py.xml")
add_test(_ctest_cv_bridge_nosetests_conversions.py "/home/shazia/trsa_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/shazia/trsa_ws/build/test_results/cv_bridge/nosetests-conversions.py.xml" "--return-code" "\"/usr/bin/cmake\" -E make_directory /home/shazia/trsa_ws/build/test_results/cv_bridge" "/usr/bin/nosetests-2.7 -P --process-timeout=60 /home/shazia/trsa_ws/src/vision_opencv/cv_bridge/test/conversions.py --with-xunit --xunit-file=/home/shazia/trsa_ws/build/test_results/cv_bridge/nosetests-conversions.py.xml")
add_test(_ctest_cv_bridge_nosetests_python_bindings.py "/home/shazia/trsa_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/shazia/trsa_ws/build/test_results/cv_bridge/nosetests-python_bindings.py.xml" "--return-code" "\"/usr/bin/cmake\" -E make_directory /home/shazia/trsa_ws/build/test_results/cv_bridge" "/usr/bin/nosetests-2.7 -P --process-timeout=60 /home/shazia/trsa_ws/src/vision_opencv/cv_bridge/test/python_bindings.py --with-xunit --xunit-file=/home/shazia/trsa_ws/build/test_results/cv_bridge/nosetests-python_bindings.py.xml")
