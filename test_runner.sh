#!/bin/bash

# bash "scrict mode" sans -u
set -e
set -o pipefail

. setup.sh

# Ensure testing dependencies
python -m pip --quiet install --upgrade pip setuptools wheel
python -m pip install --upgrade --requirement test-requirements.txt

python -m pytest -sx tests
