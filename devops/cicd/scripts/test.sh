#!/bin/bash

test_cat=$(make test -C src/cat  | grep "FAIL" | awk '{print $2}')
if [ $test_cat -eq 0 ]; then
    echo "Integration cat tests passed successfully."
else
    echo "Integration cat tests failed."
    exit 1
fi
test_grep=$(make test -C src/grep | grep "FAIL" | awk '{print $2}')
if [ $test_grep -eq 0 ]; then
    echo "Integration grep tests passed successfully."
else
    echo "Integration grep tests failed."
    exit 1
fi