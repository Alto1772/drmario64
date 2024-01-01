#!/bin/bash

STATUSOLD=`git status --porcelain`
make format
if [ $? -ne 0 ]
then
   echo "Formatter failed. Exiting."
   exit -1
fi
make tidy > /dev/null 2> /dev/null
if [ $? -ne 0 ]
then
   echo "Formatter failed. Exiting."
   exit -1
fi
STATUSNEW=`git status --porcelain`

if [ "${STATUSOLD}" != "${STATUSNEW}" ];
then
    echo ""
    echo "Misformatted files found. Run `make format` and `make tidy` and verify codegen is not impacted."
    echo ""
    diff --unified=0  --label "Old git status" <(echo "${STATUSOLD}") --label "New git status" <(echo "${STATUSNEW}")
    echo ""
    echo "Exiting."
    exit 1
fi

exit 0
