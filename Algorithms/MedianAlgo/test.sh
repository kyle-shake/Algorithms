#!/bin/bash
#Filename: test.sh
#Author: Kyle Shake
#Date: 11/13/17
#Purpose: Script to provide testing for median.cpp

numgood=0
numbad=0
bads=()

showdiff() {
  local difffile="$1"
  sed -e "s/^+.*//;
          s/^-.*//;
          s/^/   /" "$difffile"
}

success(){
   echo "Success!"
   let ++numgood
}

failure(){
  local testname="$1"
  echo "Failure!"
  let ++numbad
  bads+=("$testname")
}

test() {
  touch tmpout tmpdiff
 
  for t in ./tests/*.in; do
    base=${t%.in}
    echo "-> Testing against ${base}.in ..."
    echo " -> $1 $e < {$base}.in "
    $1 $2 < $base.in &> tmpout
    if diff -u tmpout ${base}.out > tmpdiff; then
      success $base
    else
      failure $base
      echo " -> Different Results:"
      showdiff tmpdiff
    fi
  done;

  rm tmpout tmpdiff
}

compileMedian(){
  echo "Compiling..."
  g++ -std=c++11 ./median.cpp -o ./median.out
}

cleanMedian(){
  rm ./*.out
}

case $1 in
  run)
    compileMedian
    test "" "./median.out"
  ;;
  *)
    cat README
    echo "Please pass run as an argument for this script if you wish to test this program."
  ;;
esac
