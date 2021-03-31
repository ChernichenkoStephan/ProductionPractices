clear

if ! test -d target; then
    mkdir target
fi

g++ -w -o target/prog src/main.cpp src/Equation/linear.cpp && target/prog
