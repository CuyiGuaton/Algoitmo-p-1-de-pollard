#!/bin/bash



  for (( i=1000502; i<=10000000; i++ ))
  do
    echo $(./a.out $i)
    echo $(./a.out $i) >> informe/table.txt
  done
