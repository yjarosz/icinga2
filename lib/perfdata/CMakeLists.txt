# Icinga 2
# Copyright (C) 2012-2014 Icinga Development Team (http://www.icinga.org)
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation
# Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.

mkclass_target(gelfwriter.ti gelfwriter.thpp)
mkclass_target(graphitewriter.ti graphitewriter.thpp)
mkclass_target(perfdatawriter.ti perfdatawriter.thpp)

mkembedconfig_target(perfdata-type.conf perfdata-type.cpp)

set(perfdata_SOURCES
  gelfwriter.cpp gelfwriter.thpp graphitewriter.cpp graphitewriter.thpp perfdatawriter.cpp perfdatawriter.thpp perfdata-type.cpp
)

if(ICINGA2_UNITY_BUILD)
    mkunity_target(perfdata perfdata_SOURCES)
endif()

add_library(perfdata SHARED ${perfdata_SOURCES})

target_link_libraries(perfdata ${Boost_LIBRARIES} base config icinga)

set_target_properties (
  perfdata PROPERTIES
  INSTALL_RPATH ${CMAKE_INSTALL_FULL_LIBDIR}/icinga2
  FOLDER Components
)

install(
  TARGETS perfdata
  RUNTIME DESTINATION ${CMAKE_INSTALL_SBINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/icinga2
)

install(CODE "file(MAKE_DIRECTORY \"\$ENV{DESTDIR}${CMAKE_INSTALL_FULL_LOCALSTATEDIR}/spool/icinga2/perfdata\")")
install(CODE "file(MAKE_DIRECTORY \"\$ENV{DESTDIR}${CMAKE_INSTALL_FULL_LOCALSTATEDIR}/spool/icinga2/tmp\")")
