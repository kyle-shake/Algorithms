#!/bin/bash

#Filename: facTest.sh
#Author: Kyle Shake
#Last Modified: 11/8/17
#Purpose: This shell script tests the recursive factorial calculator and outputs the time taken

README(){
  cat README

}

test(){
  touch tmpout tmpdiff
  for t in ./tests/*.txt; do
    base=${t%.txt}
    echo "-> Testing program with ${base}.txt..."
    for e in "$2"; do
      echo " -> $1 $e < ${base}.in"
      $1 $e < ${base}.txt
    done;
  done;

  rm tmpout tmpdiff

}

clean(){
  rm ./*.out
}


case $1 in
  test)
    make -f Makefile
    test "" "./FacFinder"
    clean
    make clean
    ;;
  *)
    README
    ;;
esac
