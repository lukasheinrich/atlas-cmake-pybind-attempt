#!/bin/bash

# bash "scrict mode"
# No `set -u` as /opt/lcg/binutils/2.30-e5b21/x86_64-centos7/setup.sh fails
set -e
set -o pipefail

# Build fresh
if [[ -d build ]];then
  rm -rf build
fi

# Setup release in Docker image
# shellcheck disable=SC1091
if [[ -f /release_setup.sh ]]; then
  . /release_setup.sh
fi

cmake \
  -S src \
  -B build
cmake build -L
cmake --build build -- -j$(($(nproc) - 1))

# setup built enviroment
# shellcheck disable=SC1091
. setup.sh
