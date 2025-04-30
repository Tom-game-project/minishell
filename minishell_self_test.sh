$TEST_FILE test_setting.sh
echo ==== bash.sh test '(heredoc)' ====
< bash.sh $TEST_FILE
echo ==== bash2.sh test '(expr exitstatus)' ====
< bash2.sh $TEST_FILE
echo ==== bash3.sh test '(complex syntax 1)' ====
< bash3.sh $TEST_FILE
echo ==== bash4.sh test '(heredoc python script prime)' ====
< bash4.sh $TEST_FILE
echo ==== bash5.sh test '(normal pipe)' ====
< bash5.sh $TEST_FILE
echo ==== bash6.sh test '(2000cat)' ====
< bash6.sh $TEST_FILE
echo ==== bash7.sh test '(1000sleep)'====
< bash7.sh $TEST_FILE
echo ==== bash8.sh test '(asterisk expansion && pipe)'====
< bash8.sh $TEST_FILE
