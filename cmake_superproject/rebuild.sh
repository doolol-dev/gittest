#!/bin/bash

build_dir=./_build
output_dir=./_out

rm -r -f $build_dir
mkdir $build_dir && cd $build_dir
cmake ..
cmake --build . --target package
cd ..
rm -r -f $output_dir
mkdir $output_dir
cp $build_dir/*.zip $output_dir 
cp $build_dir/*.deb $output_dir 
cp $build_dir/*.sh $output_dir 