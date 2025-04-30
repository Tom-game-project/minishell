export VAL='hello world!'
<< EOF cat
hello
THIS IS TOM
$VAL
EOF

<< "EOF" cat
hello
THIS IS TOM
$VAL
EOF

<< 'EOF' cat
hello
THIS IS TOM
$VAL
EOF
