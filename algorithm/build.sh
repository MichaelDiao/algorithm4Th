#!/bin/bash

function clean(){
    rm -rf build/*
    rm bin/*
    echo "clean all"
}

function build(){
    echo "start building..."
    cd build
    make clean
    make
    make_res="$?"
    echo "make all done with ${make_res}"
    cd ..
    return ${make_res}
}

function all_build(){
    echo "start building..."
    cd build
    cmake ..
    make
    echo "make all done"
    cd ..
}

function run(){
    if [ 1 == $# ]; then
        ./bin/$1
    else
        echo "para error!"
        echo "Useage: ./build.sh executable_file_name"
    fi
}


function parse(){
    if [ 0 == $# ]; then
        # echo "\$*=$*"
        # echo "\$\#=$#"
        # echo "\$1=$1"
        echo "Useage:"
        echo "  ./build.sh [ build(b) | run(r) {exec_file_name}| clean(c) | rebuild(rb) | rebuildAndRun(rbr) {exec_file_name}]"
        echo "Attention: run means that make firstly and run sencdonly."
        echo "  build:  for make clean and make."
        echo "  rebuild: clean all of build/ and bin/*, and cmake and make."
        echo "  rebuildAndRun: run something after rebuild."
        echo "  run: run something after make clean and make."
    elif [ 1 == $# ]; then
        if [ "build" == $1 -o "b" == $1 ]; then
            build
        elif [ "clean" == $1 -o "c" == $1 ]; then
            clean
        elif [ "rebuild" == $1 -o "rb" == $1 ]; then
            clean
            all_build
        else
            return -1
        fi
    elif [ 2 == $# ]; then
        if [ "run" == $1 -o "r" == $1 ]; then
            res=`build`
            echo "after build $res."
            if [ "$res" -ne "0" ];then
                return -3
            else
                run $2
            fi
        elif [ "rebuildAndRun" == $1 -o "rbr" == $1 ]; then
            clean
            all_build
            if [ $? -ne 0 ];then
                return -3
            else
                run $2
            fi
        fi
    else
        return -2
    fi
    
    return 0
}



parse $*
if [ "$?" == "-1" ]; then
    echo "two parameters, but para type error, $* "
elif [ "$?" == "-2" ]; then
    echo "parameter too much! $*"
elif [ "$?" == "-3" ]; then
    echo "compile failed!"
else
    echo "\nOK!"
fi
