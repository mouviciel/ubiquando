#
# Copyright © 2018 Mouviciel
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

cmake_minimum_required (VERSION 2.8)
string(REPLACE ";" "" CMAKE_OSX_SYSROOT
       "/Applications/Xcode.app/Contents/Developer/Platforms/"
       "MacOSX.platform/Developer/SDKs/MacOSX.sdk")
project (ubiquando)
set (UBIQUANDO_VERSION_MAJOR 0)
set (UBIQUANDO_VERSION_MINOR 0)
set (UBIQUANDO_VERSION_PATCH 0)
string(REPLACE ";" "" UBIQUANDO_VERSION_STRING
       "${UBIQUANDO_VERSION_MAJOR}."
       "${UBIQUANDO_VERSION_MINOR}."
       "${UBIQUANDO_VERSION_PATCH}")
configure_file(
  "${PROJECT_SOURCE_DIR}/ubiquando_config.h.in"
  "${PROJECT_BINARY_DIR}/ubiquando_config.h")
include_directories("${PROJECT_BINARY_DIR}")

add_executable(ubiquando ubiquando.c)

# vim: set tw=79 ts=2 sw=2 et ai si nonu syn=cmake fo+=ro :
