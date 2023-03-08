0.Install Python3 and pip
1.pip install conan
2.cd DeviceController
3.mkdir build

Release模式
4.conan install . --build=missing

Debug模式
5.conan install . -s build_type=Debug --build=missing