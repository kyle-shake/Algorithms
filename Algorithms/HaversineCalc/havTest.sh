#!/bin/bash

#File name: PA1test.sh
#Shell script to compile and test Haversine calculator

README(){
  cat README

}

compile(){
  for file in "${@:2}"; do
    echo "-> $1 $file"
    $1 $file
  done;
}

test() {
  touch tmpout tmpdiff
  for t in ./tests/*.txt; do
    base=${t%.txt}
    echo "-> Testing against ${base}.txt..."
    for e in "${@:2}"; do
      echo " -> $1 $e < ${base}.in"
      $1 $e < ${base}.txt
    done;
  done;

  rm tmpout tmpdiff

}

compileVec(){
  echo "Compiling Haversine calculator program that uses vectors..."
  compile "g++ -std=c++11" "HaversineWVector.cpp Location.cpp Location.h -o Haversine_Vec.out"

}

compileList(){
  echo "Compiling Haversine calculator program that uses Linked Lists"
  compile "g++ -std=c++11" "HaversineWList.cpp LinkedList.cpp LinkedList.h -o Haversine_List.out" 
}

clean(){
  rm ./*.out
}

case $1 in
  vector)
    compileVec
    echo "Testing Vector based calculator..."
    test "" "./Haversine_Vec.out"
    clean
    ;;
  list)
    compileList
    echo "Testing List based calculator"
    test "" "./Haversine_List.out"
    clean
    ;;
  *)
    README
    echo "Please pass either 'vector' or 'list' as arguments to this script to execute
		the Haversine calculator."
    ;;
esac
