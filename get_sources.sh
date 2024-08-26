#!/bin/bash

# This script prints all the cpp files in ./src directory recursively
printAllPath() {
  path=$1
  if [[ -z "$1" ]]; then
    path=./src
  fi
  for i in $path/*; do
    ## gets the extension of path if != cpp then it must be a directory
    if [[ "${i##*.}" != "cpp" ]]; then
      printAllPath $i
    else
      echo $i
    fi
  done
}

printAllPath
