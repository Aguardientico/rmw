#!/bin/sh

. ${1}

if [ -e COMMON ]; then
  . ./COMMON
else
  . ${TESTS_DIR}/COMMON
fi

echo "== On first run, directories should get created"
# show commands that are run
set -x
$RMW_TEST_CMD_STRING
test_result $?

echo "\n\n == List the waste folders"
set -x
$BIN_DIR/rmw -c $CONFIG -l

test_result $?

# Make some temporary files
mkdir $HOME/tmp-files
cd $HOME/tmp-files
echo "\n\n == creating temporary files to be deleted"
set -x
for file in 1 2 3
do
  touch $file
done
cd $HOME/..
echo "\n\n == rmw should be able to operate on multiple files\n"
$BIN_DIR/rmw --verbose -c $CONFIG $HOME/tmp-files/*

test_result $?

echo "\n\n == Show contents of the files and info directories"
set -x

ls -al $HOME/.trash.rmw/files
test_result $?

set -x

ls -al $HOME/.trash.rmw/info
test_result $?

echo "\n\n == Display contents of 1.trashinfo "
set -x
cat $HOME/.trash.rmw/info/1.trashinfo
test_result $?

echo "\n\ntest undo/restore feature\n\n"

set -x
$BIN_DIR/rmw --verbose -c $CONFIG -u
test_result $?

echo "\n\n == show that the temp files are restored to their previous locations"

set -x

ls -al $HOME/tmp-files
test_result $?

echo "\n\n == show that the .trashinfo files have been removed"

set -x
ls -al $HOME/.trash.rmw/info
test_result $?

echo $SEPARATOR
echo "Test buffer overrun prevention... (should return 12)"
set -x
RMW_TESTBUF=20 $RMW_TEST_CMD_STRING
echo err $? returned
set +x

echo "Basic tests passed"
exit 0
