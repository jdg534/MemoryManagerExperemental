# change the current directory to the directory that this script is run from
cd $(dirname "$0")

mkdir Build
cd Build

# Run cmake from inside of build or the solution gets placed on the root of the project
cmake ../ -G "Xcode"