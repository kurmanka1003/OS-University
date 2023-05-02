#!/bin/bash
for item in *
do
     if [ -d $item ]
       then
           echo "$item -> директория"
       else
           echo "$item -> файл"
       fi
done
