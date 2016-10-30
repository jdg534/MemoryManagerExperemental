#!/bin/sh

#  BuildSolutionForMac.sh
#  
#
#  Created by Josh Gibson on 30/10/2016.
#

#  This line sets the command file to execute from the folder the command file is stored in
#  cd 'dirname $0'

#RunFromDir="'dirname \"$0\"'"

#echo "Changing directory to $RunFromDir"

cd $(dirname "$0")

mkdir Build

cd Build

pwd

cmake ../ -G "Xcode"