#!/bin/bash
#Filename: fibTest.sh
#Author: Kyle Shake
#Last Modified: 11/08/17
#Purpose: Tests the fibonacci sequence programs and the time it took to complete each one

#Print the README
README(){
  cat README
}

export TERM="xterm-256color"

# Functions to print colour codes. tput interfaces with the terminfo library.
plain () { tput sgr0; }     # Reset to default foreground/background, no bold.
bold ()  { tput bold; }     # Turn on bold, do not change colors.
red ()   { tput setaf 1; }  # Red foreground.
green () { tput setaf 2; }  # Green foreground.
brown () { tput setaf 3; }  # Brown (dark yellow) foreground.
ltred ()   { bold; red; }   # Bold red.
ltgreen () { bold; green; } # Bold green.
yellow ()  { bold; brown; } # Bold brown = yellow.

# Display a unified diff indented three spaces, with additions in green
# and deletions in red.
showdiff () {
  local difffile="$1"
  sed -e "s/^+.*/$(green)&$(plain)/ ;
          s/^-.*/$(red)&$(plain)/ ;
          s/^/   /" "$difffile"
}

# Variables for the next four functions: count of good, bad, and
# questionable tests, and lists of names of bad and questionable tests.
numgood=0
numbad=0
numquestionable=0
bads=()
questionables=()

# Mark that a test succeeded, failed, or had a questionable result.
# Each of these functions takes the test name as its first argument.
# questionable() takes an optional additional message as its second
# argument.
success() {
  local testname="$1" # unused
  echo "  -> $(ltgreen)Success!$(plain)"
  let ++numgood
}
failure() {
  local testname="$1"
  echo "  -> $(ltred)Failure:$(plain)"
  let ++numbad
  bads+=("$testname")
}
questionable() {
  local testname="$1"
  local msg="$2"
  echo "  -> $(brown)${msg:-Questionable}:$(plain)"
  let ++numquestionable
  questionables+=("$testname")
}
# Summarize number of good/bad/questionable test results, and list again the
# tests with bad or questionable results.
summarize() {
  echo -n "$(ltgreen)$numgood good$(plain), "
  echo -n "$(ltred)$numbad bad$(plain), "
  echo    "$(brown)$numquestionable questionable$(plain)"

  if (( numbad > 0 )); then
    echo -n " --> Failed tests:$(ltred)"
    printf " %s" "${bads[@]}"
    echo "$(plain)"
  fi

  if (( numquestionable > 0 )); then
    echo -n " --> Possibly failed tests:$(brown)"
    printf " %s" "${questionables[@]}"
    echo "$(plain)"
  fi
}

compile () {
  for file in "${@:2}"; do
    echo "-> $1 $file"
    $1 $file
  done;
}

test () {
  touch tmpout tmpdiff

  for t in ./tests/*.in; do
    base=${t%.in}
    echo "-> Testing against ${base}.in..."
    for e in "${@:2}"; do
      echo " -> $1 $e < ${base}.in"
      $1 $e < ${base}.in &> tmpout
      if diff -u tmpout ${base}.out > tmpdiff; then
        success $base
      else
        failure $base
        echo "  -> Diff results:"
        showdiff tmpdiff
      fi
    done;
  done;

  rm tmpout tmpdiff
}

run () {
  echo "-> Testing against $2..."
  for e in "${@:3}"; do
    echo " -> $1 $e < $2.in"
    $1 $e < $2
  done;
}

compileCpp () {
  echo "$(bold)Compiling C++ program...$(plain)"
  compile "g++ -std=c++11" "cpp/recursive_fib.cpp -o cpp/recursive_fib.out" "cpp/memoization_fib.cpp -o cpp/memoization_fib.out"
 }

cleanCpp () {
  rm cpp/*.out
}

case $1 in
  time)
    compileCpp
    echo "$(bold)Testing C++ program...$(plain)"
    run "" "time_test.in" "./cpp/recursive_fib.out -t" "./cpp/memoization_fib.out -t"
    cleanCpp
    ;;
 cpp)
    compileCpp
    echo "$(bold)Testing C++ program...$(plain)"
    test "" "./cpp/recursive_fib.out" "./cpp/memoization_fib.out"
    cleanCpp
    summarize
    ;;
  *)
    README
    echo "Please pass either time or cpp as arguments to this script."
    ;;
esac
