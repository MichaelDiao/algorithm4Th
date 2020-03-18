#!/bin/bash

function clean(){
    rm -rf build/*
    rm bin/*
    echo "clean all"
}

function build(){
    echo "start building..."
    cd build
    cmake ..
    make
    echo "make all done"

}

function run(){
    if [ 1 == $# ]; then
        bash bin/$1
    else
        echo "para error!"
        echo "Useage: ./build.sh executable_file_name"
    fi
}


function parse(){
    if [ 0 == $# ]; then
        echo "\$*=$*"
        echo "\$\#=$#"
        echo "\$1=$1"
        echo "Useage:"
        echo "  ./build.sh [build(b) | run(r) {exec_file_name}| clean(c) | rebuild(rb) | rebuildAndRun(rbr) {exec_file_name}]"
    elif [ 1 == $# ]; then
        if [ "build" == $1 -o "b" == $1 ]; then
            build
        elif [ "clean" == $1 -o "c" == $1 ]; then
            clean
        else
            return -1
        fi
    elif [ 2 == $# ]; then
        if [ "run" == $1 -o "r" == $1 ]; then
            run $2
        elif [ "rebuildAndRun" == $1 -o "rbr" == $1 ]; then
            clean
            build
            run $2
        fi
    else
        return -2
    fi
    
    return 0
}



parse $*
if [ $? == -1 ]; then
    echo "two parameters, but para type error, $* "
elif [ $? == -2 ]; then
    echo "parameter too much! $*"
else
    echo "OK! $*, $#, $0"
fi
