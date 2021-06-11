#!/bin/bash

# bash "scrict mode" sans -u
set -e
set -o pipefail

# Setup release in Docker image
# and set AnalysisBase_PLATFORM
if [ -z "${AnalysisBase_SET_UP}" ]; then
  # shellcheck disable=SC1091
  if [[ -f /release_setup.sh ]]; then
    . /release_setup.sh
  fi
fi

# setup built enviroment
# shellcheck disable=SC1091
if [[ -f "build/${AnalysisBase_PLATFORM}/setup.sh" ]];then
  . "build/${AnalysisBase_PLATFORM}/setup.sh"
else
  printf "\n# build/${AnalysisBase_PLATFORM}/setup.sh not found.\n"
  printf "# Please run:\n\nbash build.sh\n\n# and try again\n"
  exit 1
fi
