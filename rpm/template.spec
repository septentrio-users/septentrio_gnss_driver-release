%bcond_without weak_deps

%global __os_install_post %(echo '%{__os_install_post}' | sed -e 's!/usr/lib[^[:space:]]*/brp-python-bytecompile[[:space:]].*$!!g')
%global __provides_exclude_from ^/opt/ros/noetic/.*$
%global __requires_exclude_from ^/opt/ros/noetic/.*$

Name:           ros-noetic-septentrio-gnss-driver
Version:        1.0.6
Release:        1%{?dist}%{?release_suffix}
Summary:        ROS septentrio_gnss_driver package

License:        BSD 3-Clause License
URL:            https://github.com/septentrio-gnss/septentrio_gnss_driver
Source0:        %{name}-%{version}.tar.gz

Requires:       boost-devel
Requires:       boost-python3-devel
Requires:       ros-noetic-cpp-common
Requires:       ros-noetic-diagnostic-msgs
Requires:       ros-noetic-geometry-msgs
Requires:       ros-noetic-gps-common
Requires:       ros-noetic-message-runtime
Requires:       ros-noetic-rosconsole
Requires:       ros-noetic-roscpp
Requires:       ros-noetic-roscpp-serialization
Requires:       ros-noetic-rostime
Requires:       ros-noetic-sensor-msgs
Requires:       ros-noetic-xmlrpcpp
BuildRequires:  boost-devel
BuildRequires:  boost-python3-devel
BuildRequires:  ros-noetic-catkin
BuildRequires:  ros-noetic-cpp-common
BuildRequires:  ros-noetic-diagnostic-msgs
BuildRequires:  ros-noetic-geometry-msgs
BuildRequires:  ros-noetic-gps-common
BuildRequires:  ros-noetic-message-generation
BuildRequires:  ros-noetic-rosconsole
BuildRequires:  ros-noetic-roscpp
BuildRequires:  ros-noetic-roscpp-serialization
BuildRequires:  ros-noetic-rostime
BuildRequires:  ros-noetic-sensor-msgs
BuildRequires:  ros-noetic-xmlrpcpp
Provides:       %{name}-devel = %{version}-%{release}
Provides:       %{name}-doc = %{version}-%{release}
Provides:       %{name}-runtime = %{version}-%{release}

%description
ROSaic: C++ driver for Septentrio's mosaic receivers and beyond

%prep
%autosetup

%build
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree that was dropped by catkin, and source it.  It will
# set things like CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/noetic/setup.sh" ]; then . "/opt/ros/noetic/setup.sh"; fi
mkdir -p obj-%{_target_platform} && cd obj-%{_target_platform}
%cmake3 \
    -UINCLUDE_INSTALL_DIR \
    -ULIB_INSTALL_DIR \
    -USYSCONF_INSTALL_DIR \
    -USHARE_INSTALL_PREFIX \
    -ULIB_SUFFIX \
    -DCMAKE_INSTALL_LIBDIR="lib" \
    -DCMAKE_INSTALL_PREFIX="/opt/ros/noetic" \
    -DCMAKE_PREFIX_PATH="/opt/ros/noetic" \
    -DSETUPTOOLS_DEB_LAYOUT=OFF \
    -DCATKIN_BUILD_BINARY_PACKAGE="1" \
    ..

%make_build

%install
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree that was dropped by catkin, and source it.  It will
# set things like CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/noetic/setup.sh" ]; then . "/opt/ros/noetic/setup.sh"; fi
%make_install -C obj-%{_target_platform}

%files
/opt/ros/noetic

%changelog
* Fri Oct 16 2020 Septentrio <githubuser@septentrio.com> - 1.0.6-1
- Autogenerated by Bloom

