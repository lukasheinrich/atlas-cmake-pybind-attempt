#!/bin/bash

# bash "scrict mode" sans -u
set -e
set -o pipefail

. setup.sh

# Place .local/bin on PATH for pytest
export PATH="${HOME}/.local/bin:${PATH}"

# Ensure testing dependencies
python -m pip --quiet install --user --upgrade pip setuptools wheel
python -m pip install --user --upgrade --requirement test-requirements.txt
python -m pip list

python -m pytest -sx tests
